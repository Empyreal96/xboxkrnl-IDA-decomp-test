int __stdcall UdfxFsdRead(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v2; // ecx
  _IO_STACK_LOCATION *v3; // esi
  int *v4; // edi
  _DWORD *v5; // ebx
  int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned __int64 v9; // kr00_8
  int v10; // edx
  _IRP *v11; // ecx
  unsigned int v12; // eax
  unsigned __int64 v13; // ST08_8
  _IO_STACK_LOCATION *v15; // esi
  int v16; // ecx
  int v17; // edx
  unsigned int v18; // eax
  _FILE_OBJECT *FileObject; // [esp+Ch] [ebp-14h]
  unsigned int *v20; // [esp+10h] [ebp-10h]
  _UDF_VOLUME_EXTENSION *VolumeExtension; // [esp+14h] [ebp-Ch]
  _IO_STACK_LOCATION *NextIrpSp; // [esp+18h] [ebp-8h]
  char NonCachedEndOfFileTransfer; // [esp+1Ch] [ebp-4h]
  unsigned int ReadLength; // [esp+28h] [ebp+8h]

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = (int *)DeviceObject->DeviceExtension;
  NextIrpSp = v3 - 1;
  v5 = v3->FileObject->FsContext;
  FileObject = v3->FileObject;
  v20 = &v3->Parameters.Create.DesiredAccess;
  VolumeExtension = (_UDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  ReadLength = v3->Parameters.Create.DesiredAccess;
  NonCachedEndOfFileTransfer = 0;
  if ( *((_BYTE *)v4 + 40) )
  {
    v6 = -1073741202;
CleanupAndExit_34:
    v2->IoStatus.Status = v6;
    IofCompleteRequest(v2, 0, v4);
    return v6;
  }
  if ( *(_BYTE *)v5 & 2 )
  {
    v6 = -1073741808;
    goto CleanupAndExit_34;
  }
  if ( *(_BYTE *)v5 & 8 )
  {
    v6 = -1073741790;
    goto CleanupAndExit_34;
  }
  if ( !v3->Parameters.Create.DesiredAccess )
  {
    Irp->IoStatus.Information = 0;
    v6 = 0;
    goto CleanupAndExit_34;
  }
  v7 = v5[3];
  v8 = v5[2];
  if ( v3->Parameters.Read.ByteOffset.QuadPart >= __PAIR__(v7, v8) )
  {
    v6 = -1073741807;
LABEL_23:
    v2 = Irp;
    goto CleanupAndExit_34;
  }
  v9 = __PAIR__(v7, v8) - v3->Parameters.Read.ByteOffset.QuadPart;
  v10 = 0;
  if ( ReadLength >= v9 )
  {
    if ( !(*(_BYTE *)v5 & 1) && ReadLength >= ((v5[2] + 2047) & 0xFFFFF800) - v3->Parameters.Read.ByteOffset.LowPart )
      NonCachedEndOfFileTransfer = 1;
    ReadLength = v9;
  }
  if ( !ReadLength )
    RtlAssert(0, v9, v4, (int)v3, "ReadLength > 0", "d:\\xbox-apr03\\private\\ntos\\udfx\\read.c", 0xD3u, 0);
  v11 = Irp;
  v12 = Irp->Flags;
  if ( !(v12 & 1) && !(*(_BYTE *)v5 & 1) )
  {
    if ( v12 & 0x400 )
    {
      RtlAssert(
        v10,
        (int)Irp,
        v4,
        (int)v3,
        "UdfxIsFlagClear(Irp->Flags, IRP_SCATTER_GATHER_OPERATION)",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\read.c",
        0x11Du,
        0);
      v11 = Irp;
    }
    v13 = v3->Parameters.Read.ByteOffset.QuadPart + ((unsigned __int64)(unsigned int)(v4[7] + v5[1]) << 11);
    v6 = FscCachedRead(
           (int)v11,
           SHIDWORD(v13),
           (_FSCACHE_EXTENSION *)v4,
           v11,
           v13,
           ReadLength,
           NonCachedEndOfFileTransfer);
    goto LABEL_23;
  }
  v15 = Irp->Tail.Overlay.CurrentStackLocation;
  qmemcpy(&v15[-1], v15, 0x1Cu);
  v15[-1].Control = 0;
  IoLockUserBuffer(v10, 0, (int)v20, Irp, *v20);
  if ( *(_BYTE *)v5 & 1 )
  {
    v16 = (int)NextIrpSp;
  }
  else
  {
    v16 = (int)NextIrpSp;
    NextIrpSp->Parameters.Read.ByteOffset.QuadPart += (unsigned __int64)(VolumeExtension->PartitionSectorStart + v5[1]) << 11;
  }
  v17 = (ReadLength + 2047) & 0xFFFFF800;
  *(_DWORD *)(v16 + 4) = v17;
  if ( *v20 != ReadLength || (v16 = (int)FileObject, FileObject->Flags & 1) )
  {
    *v20 = ReadLength;
    if ( !UdfxNonCachedReadCompletion )
      RtlAssert(
        v17,
        v16,
        (int *)&Irp->Type,
        (int)UdfxNonCachedReadCompletion,
        "(1) | (0) | (0) ? (UdfxNonCachedReadCompletion) != NULL : TRUE",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\read.c",
        0x10Fu,
        (char *)UdfxNonCachedReadCompletion);
    v18 = Irp->Tail.Overlay.PacketType - 36;
    *(_DWORD *)(v18 + 32) = 0;
    *(_DWORD *)(v18 + 28) = UdfxNonCachedReadCompletion;
    *(_BYTE *)(v18 + 3) = 64;
  }
  return IofCallDriver(VolumeExtension->CacheExtension.TargetDeviceObject, Irp);
}