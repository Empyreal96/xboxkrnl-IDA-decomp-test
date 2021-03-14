int __userpurge RawxPassIrpDownToTargetDevice@<eax>(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int v3; // edx
  int v4; // esi
  int v5; // edx
  _IO_STACK_LOCATION *v6; // esi
  _IO_STACK_LOCATION *v7; // eax
  _KTHREAD *v8; // eax
  unsigned int v9; // ecx
  _RAW_VOLUME_EXTENSION *VolumeExtension; // [esp+Ch] [ebp+8h]

  VolumeExtension = (_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  RawxAcquireVolumeMutexShared(VolumeExtension);
  if ( VolumeExtension->Dismounted )
  {
    RawxReleaseVolumeMutex(VolumeExtension);
    v4 = -1073741202;
    LOBYTE(v5) = 0;
    Irp->IoStatus.Status = -1073741202;
    IofCompleteRequest(Irp, v5, a1);
  }
  else
  {
    v6 = Irp->Tail.Overlay.CurrentStackLocation;
    qmemcpy(&v6[-1], v6, 0x1Cu);
    v6[-1].Control = 0;
    if ( !RawxVolumeIoCompletion )
      RtlAssert(
        v3,
        0,
        (int *)&v6[-1].CompletionRoutine,
        (int)RawxVolumeIoCompletion,
        "(1) | (1) | (1) ? (RawxVolumeIoCompletion) != NULL : TRUE",
        "d:\\xbox-apr03\\private\\ntos\\rawx\\driver.c",
        0xA9u,
        (char *)RawxVolumeIoCompletion);
    v7 = Irp->Tail.Overlay.CurrentStackLocation;
    v7[-1].Context = 0;
    --v7;
    v7->CompletionRoutine = RawxVolumeIoCompletion;
    v7->Control = -32;
    v4 = IofCallDriver(VolumeExtension->TargetDeviceObject, Irp);
    v8 = thread;
    v9 = thread->KernelApcDisable + 1;
    thread->KernelApcDisable = v9;
    if ( !v9 && (_KAPC_STATE *)v8->ApcState.ApcListHead[0].Flink != &v8->ApcState )
    {
      v8->ApcState.KernelApcPending = 1;
      HalRequestSoftwareInterrupt(1);
    }
  }
  return v4;
}