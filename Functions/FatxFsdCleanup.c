int __fastcall FatxFsdCleanup(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _FAT_VOLUME_EXTENSION *v4; // ebx
  int v5; // edi
  _FAT_FCB *v6; // esi
  int v7; // edx
  int v8; // ecx
  char v9; // al
  int v10; // edx
  char v11; // cl
  int v12; // edx
  _LIST_ENTRY *v13; // eax
  _LIST_ENTRY *v14; // ecx
  int v15; // edx
  int v16; // ecx
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+14h] [ebp+8h]

  v4 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v5 = *(_DWORD *)(Irp->Tail.Overlay.PacketType + 24);
  v6 = *(_FAT_FCB **)(v5 + 8);
  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  if ( !(v6->Flags & 3) )
    FatxAcquireFileMutexExclusive(a2, a1, (int *)v5, v6);
  FatxAcquireVolumeMutexExclusive(a2, a1, (int *)v5, (int)v6, v4);
  IoRemoveShareAccess((int *)v5, (int)v6, (_FILE_OBJECT *)v5, &v6->ShareAccess);
  if ( !v6->ShareAccess.OpenCount && !(VolumeExtension->Flags & 1) )
  {
    v9 = v6->Flags;
    if ( v6->Flags & 0x10 )
    {
      if ( v9 & 5 )
        RtlAssert(
          v7,
          v8,
          (int *)v5,
          (int)v6,
          "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME | FAT_FCB_ROOT_DIRECTORY)",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\cleanup.c",
          0x58u,
          0);
      if ( FatxMarkDirectoryEntryDeleted(v8, v7, VolumeExtension, Irp, v6) >= 0 )
      {
        FatxFreeClusters(v10, v11, (int *)v5, VolumeExtension, Irp, v6->FirstCluster, 0);
        if ( v6->ParentFcb )
        {
          v13 = v6->SiblingFcbLink.Flink;
          v14 = v6->SiblingFcbLink.Blink;
          v14->Flink = v13;
          v13->Blink = v14;
          FatxDereferenceFcb(v12, (int)v14, (int *)v5, v6->ParentFcb);
          v6->ParentFcb = 0;
        }
      }
    }
    else if ( v9 & 0x40 )
    {
      FatxUpdateDirectoryEntry(v7, v8, (int *)v5, VolumeExtension, Irp, v6);
    }
  }
  *(_BYTE *)(v5 + 3) |= 0x10u;
  FatxReleaseVolumeMutex(VolumeExtension);
  if ( !(v6->Flags & 3) )
    FatxReleaseFileMutex(v15, v16, (int *)v5, v6);
  Irp->IoStatus.Status = 0;
  LOBYTE(v15) = 0;
  IofCompleteRequest(Irp, v15, (int *)v5);
  return 0;
}