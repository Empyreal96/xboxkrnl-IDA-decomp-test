int __userpurge FatxFsdDeviceControl@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int v5; // edx
  int v6; // esi
  int v7; // edx
  _IO_STACK_LOCATION *v8; // esi
  _IO_STACK_LOCATION *v9; // eax
  _KTHREAD *v10; // eax
  unsigned int v11; // ecx
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+Ch] [ebp+8h]

  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  FatxAcquireVolumeMutexShared(a1, a2, a3, VolumeExtension);
  if ( VolumeExtension->Flags & 1 )
  {
    FatxReleaseVolumeMutex(VolumeExtension);
    v6 = -1073741202;
    LOBYTE(v7) = 0;
    Irp->IoStatus.Status = -1073741202;
    IofCompleteRequest(Irp, v7, a3);
  }
  else
  {
    v8 = Irp->Tail.Overlay.CurrentStackLocation;
    qmemcpy(&v8[-1], v8, 0x1Cu);
    v8[-1].Control = 0;
    if ( !FatxVolumeIoCompletion )
      RtlAssert(
        v5,
        0,
        (int *)&v8[-1].CompletionRoutine,
        (int)FatxVolumeIoCompletion,
        "(1) | (1) | (1) ? (FatxVolumeIoCompletion) != NULL : TRUE",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\devctrl.c",
        0x40u,
        (char *)FatxVolumeIoCompletion);
    v9 = Irp->Tail.Overlay.CurrentStackLocation;
    v9[-1].Context = 0;
    --v9;
    v9->CompletionRoutine = (int (__stdcall *)(_DEVICE_OBJECT *, _IRP *, void *))FatxVolumeIoCompletion;
    v9->Control = -32;
    v6 = IofCallDriver(VolumeExtension->CacheExtension.TargetDeviceObject, Irp);
    v10 = thread;
    v11 = thread->KernelApcDisable + 1;
    thread->KernelApcDisable = v11;
    if ( !v11 && (_KAPC_STATE *)v10->ApcState.ApcListHead[0].Flink != &v10->ApcState )
    {
      v10->ApcState.KernelApcPending = 1;
      HalRequestSoftwareInterrupt(1);
    }
  }
  return v6;
}