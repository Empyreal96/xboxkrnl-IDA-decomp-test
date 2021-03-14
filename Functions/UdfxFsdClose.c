int __stdcall UdfxFsdClose(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int *v2; // edi
  int v3; // esi
  int v4; // edx
  int v5; // ecx
  void *v6; // eax
  _UDF_FCB *v7; // eax
  int v8; // edx
  void *v9; // ecx
  bool v10; // zf
  int v11; // edx

  v2 = (int *)DeviceObject->DeviceExtension;
  v3 = *(_DWORD *)(Irp->Tail.Overlay.PacketType + 24);
  RtlEnterCriticalSectionAndRegion(&UdfxGlobalMutex);
  v6 = *(void **)(v3 + 12);
  if ( v6 )
  {
    *(_DWORD *)(v3 + 12) = 0;
    ExFreePool(v6);
  }
  v7 = *(_UDF_FCB **)(v3 + 8);
  *(_DWORD *)(v3 + 8) = 0;
  UdfxDereferenceFcb(v4, v5, v2, v7);
  v10 = v2[9]-- == 1;
  if ( v10 && *((_BYTE *)v2 + 40) )
    UdfxDeleteVolumeDevice((int)v9, v8, DeviceObject);
  RtlLeaveCriticalSectionAndRegion(v9, (_KEVENT *)&UdfxGlobalMutex);
  Irp->IoStatus.Status = 0;
  LOBYTE(v11) = 0;
  IofCompleteRequest(Irp, v11, v2);
  return 0;
}