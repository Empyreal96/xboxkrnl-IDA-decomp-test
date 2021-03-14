char __stdcall UdfxProcessPartitionDescriptor(NSR_PART *PartitionDescriptor, _UDF_VOLUME_EXTENSION *VolumeExtension, unsigned __int16 *PartitionNumber)
{
  signed int v3; // ecx
  int *v4; // edi
  char *v5; // esi
  bool v6; // zf
  char result; // al
  __int64 v8; // rax
  __int64 v9; // kr00_8

  v3 = 23;
  v4 = (int *)"+NSR02";
  v5 = PartitionDescriptor->ContentsID.Identifier;
  v6 = 1;
  do
  {
    if ( !v3 )
      break;
    v6 = *v5++ == *(_BYTE *)v4;
    v4 = (int *)((char *)v4 + 1);
    --v3;
  }
  while ( v6 );
  if ( v6 )
  {
    VolumeExtension->PartitionSectorStart = PartitionDescriptor->Start;
    v8 = PartitionDescriptor->Length;
    v9 = v8 + VolumeExtension->PartitionSectorStart;
    VolumeExtension->PartitionSectorCount = v8;
    VolumeExtension->VolumeFcb->FileSize.QuadPart = v9 << 11;
    VolumeExtension->CacheExtension.PartitionLength.QuadPart = VolumeExtension->VolumeFcb->FileSize.QuadPart;
    *PartitionNumber = PartitionDescriptor->Number;
    result = 1;
  }
  else
  {
    DbgPrint(v4, "UDFX: invalid partition descriptor (line %d)\n", 671);
    result = 0;
  }
  return result;
}