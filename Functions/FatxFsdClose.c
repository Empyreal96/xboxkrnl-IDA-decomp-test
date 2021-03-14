int __userpurge FatxFsdClose@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int *v5; // edi
  int v6; // edx
  int v7; // ecx
  int v8; // esi
  void *v9; // eax
  _FAT_FCB *v10; // eax
  bool v11; // zf
  int v12; // edx
  int v13; // ecx
  int v14; // edx

  v5 = (int *)DeviceObject->DeviceExtension;
  FatxAcquireVolumeMutexExclusive(a1, a2, v5, a3, (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension);
  v8 = *(_DWORD *)(Irp->Tail.Overlay.PacketType + 24);
  v9 = *(void **)(v8 + 12);
  if ( v9 )
  {
    *(_DWORD *)(v8 + 12) = 0;
    ExFreePool(v9);
  }
  v10 = *(_FAT_FCB **)(v8 + 8);
  *(_DWORD *)(v8 + 8) = 0;
  FatxDereferenceFcb(v6, v7, v5, v10);
  v11 = v5[5]-- == 1;
  if ( v11 && *((_BYTE *)v5 + 35) & 1 )
  {
    FatxReleaseVolumeMutex((_FAT_VOLUME_EXTENSION *)v5);
    FatxDeleteVolumeDevice(v13, v12, DeviceObject);
  }
  else
  {
    FatxReleaseVolumeMutex((_FAT_VOLUME_EXTENSION *)v5);
  }
  Irp->IoStatus.Status = 0;
  LOBYTE(v14) = 0;
  IofCompleteRequest(Irp, v14, v5);
  return 0;
}