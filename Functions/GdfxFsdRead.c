int __stdcall GdfxFsdRead(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v2; // ecx
  _IO_STACK_LOCATION *v3; // esi
  int *v4; // edi
  unsigned int *v5; // ebx
  signed int v6; // esi
  char v7; // dl
  int v8; // eax
  int v9; // ecx
  unsigned int v11; // eax
  int v12; // ecx
  unsigned __int64 v13; // kr00_8
  unsigned int v14; // edx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned __int64 v17; // ST08_8
  int v18; // eax
  _IO_STACK_LOCATION *v19; // esi
  int v20; // ecx
  int v21; // edx
  unsigned int v22; // eax
  _GDF_VOLUME_EXTENSION *VolumeExtension; // [esp+Ch] [ebp-14h]
  _FILE_OBJECT *FileObject; // [esp+10h] [ebp-10h]
  unsigned int *v25; // [esp+14h] [ebp-Ch]
  _IO_STACK_LOCATION *NextIrpSp; // [esp+18h] [ebp-8h]
  char NonCachedEndOfFileTransfer; // [esp+1Ch] [ebp-4h]
  unsigned int ReadLength; // [esp+28h] [ebp+8h]

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = (int *)DeviceObject->DeviceExtension;
  NextIrpSp = v3 - 1;
  v5 = (unsigned int *)v3->FileObject->FsContext;
  FileObject = v3->FileObject;
  v25 = &v3->Parameters.Create.DesiredAccess;
  VolumeExtension = (_GDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  ReadLength = v3->Parameters.Create.DesiredAccess;
  NonCachedEndOfFileTransfer = 0;
  if ( *((_BYTE *)v4 + 40) )
  {
    v6 = -1073741202;
CleanupAndExit_25:
    v2->IoStatus.Status = v6;
    IofCompleteRequest(v2, 0, v4);
    return v6;
  }
  v7 = *((_BYTE *)v5 + 32);
  if ( v7 & 2 )
  {
    v6 = -1073741808;
    goto CleanupAndExit_25;
  }
  if ( !v3->Parameters.Create.DesiredAccess )
  {
    v6 = 0;
    Irp->IoStatus.Information = 0;
    goto CleanupAndExit_25;
  }
  if ( v7 & 1 )
  {
    v8 = v4[2];
    v9 = v4[1];
    if ( v3->Parameters.Read.ByteOffset.QuadPart >= __PAIR__((unsigned int)v8, v9) )
    {
      v2 = Irp;
LABEL_10:
      v6 = -1073741807;
      goto CleanupAndExit_25;
    }
    v13 = __PAIR__(v8, v9) - v3->Parameters.Read.ByteOffset.QuadPart;
    v11 = (__PAIR__((unsigned int)v8, v9) - v3->Parameters.Read.ByteOffset.QuadPart) >> 32;
    v12 = v13;
    v14 = 0;
    if ( ReadLength >= __PAIR__(v11, (unsigned int)v13) )
      goto LABEL_20;
  }
  else
  {
    if ( v3->Parameters.Read.ByteOffset.HighPart )
      goto LABEL_10;
    v14 = v3->Parameters.Read.ByteOffset.LowPart;
    v15 = v5[1];
    if ( v14 >= v15 )
      goto LABEL_10;
    v12 = v15 - v14;
    if ( ReadLength >= v15 - v14 )
    {
      if ( ReadLength >= ((v15 + 2047) & 0xFFFFF800) - v14 )
        NonCachedEndOfFileTransfer = 1;
LABEL_20:
      ReadLength = v12;
      goto LABEL_21;
    }
  }
LABEL_21:
  if ( !ReadLength )
    RtlAssert(v14, v12, v4, (int)v3, "ReadLength > 0", "d:\\xbox-apr03\\private\\ntos\\gdfx\\read.c", 0xE4u, 0);
  v16 = Irp->Flags;
  if ( !(v16 & 1) && !(v5[8] & 1) )
  {
    if ( v16 & 0x400 )
      RtlAssert(
        v14,
        (int)Irp,
        v4,
        (int)v3,
        "GdfxIsFlagClear(Irp->Flags, IRP_SCATTER_GATHER_OPERATION)",
        "d:\\xbox-apr03\\private\\ntos\\gdfx\\read.c",
        0x12Du,
        0);
    v17 = v3->Parameters.Read.ByteOffset.QuadPart + ((unsigned __int64)*v5 << 11);
    v18 = FscCachedRead(2048, SHIDWORD(v17), (_FSCACHE_EXTENSION *)v4, Irp, v17, ReadLength, NonCachedEndOfFileTransfer);
    v2 = Irp;
    v6 = v18;
    goto CleanupAndExit_25;
  }
  v19 = Irp->Tail.Overlay.CurrentStackLocation;
  qmemcpy(&v19[-1], v19, 0x1Cu);
  v19[-1].Control = 0;
  IoLockUserBuffer(v14, 0, (int)v25, Irp, *v25);
  if ( v5[8] & 1 )
  {
    v20 = (int)NextIrpSp;
  }
  else
  {
    v20 = (int)NextIrpSp;
    NextIrpSp->Parameters.Read.ByteOffset.QuadPart += (unsigned __int64)*v5 << 11;
  }
  v21 = (ReadLength + 2047) & 0xFFFFF800;
  *(_DWORD *)(v20 + 4) = v21;
  if ( *v25 != ReadLength || (v20 = (int)FileObject, FileObject->Flags & 1) )
  {
    *v25 = ReadLength;
    if ( !GdfxNonCachedReadCompletion )
      RtlAssert(
        v21,
        v20,
        (int *)&Irp->Type,
        (int)GdfxNonCachedReadCompletion,
        "(1) | (0) | (0) ? (GdfxNonCachedReadCompletion) != NULL : TRUE",
        "d:\\xbox-apr03\\private\\ntos\\gdfx\\read.c",
        0x11Fu,
        (char *)GdfxNonCachedReadCompletion);
    v22 = Irp->Tail.Overlay.PacketType - 36;
    *(_DWORD *)(v22 + 32) = 0;
    *(_DWORD *)(v22 + 28) = GdfxNonCachedReadCompletion;
    *(_BYTE *)(v22 + 3) = 64;
  }
  return IofCallDriver(VolumeExtension->CacheExtension.TargetDeviceObject, Irp);
}