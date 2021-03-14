int __stdcall IdexDiskReadWrite(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  char *v2; // ecx
  _IO_STACK_LOCATION *v3; // esi
  int v4; // edx
  unsigned int v5; // eax
  int *v6; // edi
  signed int v7; // esi
  __int64 v9; // rax
  bool v10; // zf
  unsigned int EndingByteOffset; // [esp+Ch] [ebp-14h]
  __int64 StartingByteOffset; // [esp+14h] [ebp-Ch]
  _IDE_DISK_EXTENSION *DiskExtension; // [esp+1Ch] [ebp-4h]

  v2 = (char *)DeviceObject->DeviceExtension;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = v3->Parameters.Create.DesiredAccess;
  StartingByteOffset = v3->Parameters.Read.ByteOffset.QuadPart;
  DiskExtension = (_IDE_DISK_EXTENSION *)DeviceObject->DeviceExtension;
  v6 = (int *)((StartingByteOffset + (unsigned __int64)(unsigned int)v4) >> 32);
  v5 = StartingByteOffset + v4;
  EndingByteOffset = StartingByteOffset + v4;
  if ( v3->Flags < 0 )
  {
    if ( (_DWORD)v3->Parameters.QueryDirectory.FileName & 0x1FF )
    {
      RtlAssert(
        v4,
        (int)v2,
        v6,
        (int)v3,
        "(PtrToUlong(IrpSp->Parameters.Read.CacheBuffer) & IDE_ATA_SECTOR_MASK) == 0",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x382u,
        0);
      v5 = EndingByteOffset;
      v2 = (char *)DiskExtension;
    }
    if ( v3->Parameters.Create.DesiredAccess & 0x1FF )
    {
      RtlAssert(
        v4,
        (int)v2,
        v6,
        (int)v3,
        "(IrpSp->Parameters.Read.Length & IDE_ATA_SECTOR_MASK) == 0",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x383u,
        0);
      v5 = EndingByteOffset;
      v2 = (char *)DiskExtension;
    }
    if ( v3->Parameters.Create.FileAttributes & 0x1FF )
    {
      RtlAssert(
        v4,
        (int)v2,
        v6,
        (int)v3,
        "(IrpSp->Parameters.Read.ByteOffset.LowPart & IDE_ATA_SECTOR_MASK) == 0",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x384u,
        0);
      v5 = EndingByteOffset;
      v2 = (char *)DiskExtension;
    }
    if ( (signed __int64)__PAIR__((unsigned int)v6, v5) > *(_QWORD *)(v2 + 12) )
    {
      RtlAssert(
        v4,
        (int)v2,
        v6,
        (int)v3,
        "EndingByteOffset <= DiskExtension->PartitionInformation.PartitionLength.QuadPart",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x386u,
        0);
      v2 = (char *)DiskExtension;
    }
  }
  else if ( (_DWORD)Irp->UserBuffer & 1
         || (_DWORD)v3->Parameters.QueryDirectory.FileName & 1
         || v4 & 0x1FF
         || v3->Parameters.Create.FileAttributes & 0x1FF
         || (signed __int64)__PAIR__((unsigned int)v6, v5) > *(_QWORD *)(v2 + 12) )
  {
    Irp->IoStatus.Status = -1073741811;
    v7 = -1073741811;
LABEL_18:
    LOBYTE(v4) = 0;
    IofCompleteRequest(Irp, v4, v6);
    return v7;
  }
  v6 = (int *)v3->Parameters.Create.DesiredAccess;
  if ( !v6 )
  {
    Irp->IoStatus.Information = 0;
    Irp->IoStatus.Status = 0;
    v7 = 0;
    goto LABEL_18;
  }
  v9 = (StartingByteOffset + *(_QWORD *)(v2 + 4)) >> 9;
  v10 = v3->Flags >= 0;
  v3->Parameters.Read.ByteOffset.LowPart = v9;
  if ( v10 )
  {
    v3->Parameters.Read.ByteOffset.HighPart = v3->Parameters.Create.Options;
    v3->Parameters.Create.Options = (unsigned int)Irp->UserBuffer;
  }
  else
  {
    v3->Parameters.Read.ByteOffset.HighPart = 0;
  }
  LODWORD(v9) = Irp->Tail.Overlay.CurrentStackLocation;
  Irp->IoStatus.Information = (unsigned int)v6;
  *(_BYTE *)(v9 + 3) |= 1u;
  dword_80051350(v2, HIDWORD(v9), DeviceObject, Irp);
  return 259;
}