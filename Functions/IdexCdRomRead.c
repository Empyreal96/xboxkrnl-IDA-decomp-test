int __stdcall IdexCdRomRead(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v2; // esi
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  unsigned int v6; // ebx
  signed int v7; // esi
  unsigned int v8; // ebx
  bool v10; // zf
  _IO_STACK_LOCATION *v11; // eax
  int EndingByteOffset; // [esp+Ch] [ebp-10h]
  __int64 StartingByteOffset; // [esp+14h] [ebp-8h]

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  v3 = v2->Parameters.Create.DesiredAccess;
  v4 = v2->Parameters.Read.ByteOffset.LowPart;
  HIDWORD(StartingByteOffset) = v2->Parameters.Create.RemainingName;
  v6 = (__PAIR__(HIDWORD(StartingByteOffset), v4) + (unsigned int)v3) >> 32;
  v5 = v4 + v3;
  LODWORD(StartingByteOffset) = v2->Parameters.Read.ByteOffset.LowPart;
  EndingByteOffset = v4 + v3;
  if ( v2->Flags < 0 )
  {
    if ( (_DWORD)v2->Parameters.QueryDirectory.FileName & 0x7FF )
    {
      RtlAssert(
        v4,
        v3,
        (int *)&Irp->Type,
        (int)v2,
        "(PtrToUlong(IrpSp->Parameters.Read.CacheBuffer) & IDE_ATAPI_CD_SECTOR_MASK) == 0",
        "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        0xAEAu,
        0);
      v5 = EndingByteOffset;
    }
    if ( v2->Parameters.Create.DesiredAccess & 0x7FF )
    {
      RtlAssert(
        v4,
        v3,
        (int *)&Irp->Type,
        (int)v2,
        "(IrpSp->Parameters.Read.Length & IDE_ATAPI_CD_SECTOR_MASK) == 0",
        "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        0xAEBu,
        0);
      v5 = EndingByteOffset;
    }
    if ( v2->Parameters.Create.FileAttributes & 0x7FF )
    {
      RtlAssert(
        v4,
        v3,
        (int *)&Irp->Type,
        (int)v2,
        "(IrpSp->Parameters.Read.ByteOffset.LowPart & IDE_ATAPI_CD_SECTOR_MASK) == 0",
        "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        0xAECu,
        0);
      v5 = EndingByteOffset;
    }
    if ( (signed __int64)__PAIR__(v6, v5) > IdexCdRomPartitionLength )
      RtlAssert(
        v4,
        v3,
        (int *)&Irp->Type,
        (int)v2,
        "EndingByteOffset <= IdexCdRomPartitionLength",
        "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        0xAEDu,
        0);
  }
  else if ( (_DWORD)Irp->UserBuffer & 1
         || (_DWORD)v2->Parameters.QueryDirectory.FileName & 1
         || (v4 = 2047, v3 & 0x7FF)
         || v2->Parameters.Read.ByteOffset.LowPart & 0x7FF
         || (signed __int64)__PAIR__(v6, v5) > IdexCdRomPartitionLength )
  {
    Irp->IoStatus.Status = -1073741811;
    v7 = -1073741811;
LABEL_18:
    LOBYTE(v4) = 0;
    IofCompleteRequest(Irp, v4, (int *)&Irp->Type);
    return v7;
  }
  v8 = v2->Parameters.Create.DesiredAccess;
  if ( !v8 )
  {
    Irp->IoStatus.Information = 0;
    Irp->IoStatus.Status = 0;
    v7 = 0;
    goto LABEL_18;
  }
  v10 = v2->Flags >= 0;
  v2->Parameters.Read.ByteOffset.LowPart = StartingByteOffset >> 11;
  if ( v10 )
  {
    v2->Parameters.Read.ByteOffset.HighPart = v2->Parameters.Create.Options;
    v2->Parameters.Create.Options = (unsigned int)Irp->UserBuffer;
  }
  else
  {
    v2->Parameters.Read.ByteOffset.HighPart = 0;
  }
  v11 = Irp->Tail.Overlay.CurrentStackLocation;
  Irp->IoStatus.Information = v8;
  v11->Control |= 1u;
  dword_80051350(v3, (unsigned __int64)(StartingByteOffset >> 11) >> 32, DeviceObject, Irp);
  return 259;
}