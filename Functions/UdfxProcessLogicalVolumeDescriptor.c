char __userpurge UdfxProcessLogicalVolumeDescriptor@<al>(CHARSPEC *a1@<edi>, NSR_LVOL *LogicalVolumeDescriptor, LONGAD *FileSetDescriptorExtent, unsigned __int16 *PartitionNumber)
{
  unsigned int v4; // edx
  signed int v5; // ecx
  char *v6; // esi
  bool v7; // zf
  unsigned __int16 v8; // cx
  signed int v9; // ecx
  CHARSPEC *v10; // esi
  bool v11; // zf
  signed int v13; // [esp-4h] [ebp-10h]

  v4 = LogicalVolumeDescriptor->MapTableLength;
  if ( ((v4 + 443) & 0xFFFFFFFC) > 0x800 || LogicalVolumeDescriptor->BlockSize != 2048 )
  {
    v13 = 734;
    goto LABEL_25;
  }
  v5 = 23;
  a1 = (CHARSPEC *)"*OSTA UDF Compliant";
  v6 = LogicalVolumeDescriptor->DomainID.Identifier;
  v7 = 1;
  do
  {
    if ( !v5 )
      break;
    v7 = *v6++ == a1->Type;
    a1 = (CHARSPEC *)((char *)a1 + 1);
    --v5;
  }
  while ( v7 );
  if ( !v7 )
  {
    v13 = 744;
LABEL_25:
    DbgPrint((int *)&a1->Type, "UDFX: invalid logical volume descriptor (line %d)\n", v13);
    return 0;
  }
  v8 = *(_WORD *)LogicalVolumeDescriptor->DomainID.Suffix;
  if ( v8 < 0x100u || v8 > 0x150u )
  {
    DbgPrint((int *)&a1->Type, "UDFX: unsupported UDF version %04x\n", v8);
  }
  else
  {
    v9 = 16;
    a1 = &UdfxCS0Identifier;
    v10 = &LogicalVolumeDescriptor->Charset;
    v11 = 1;
    do
    {
      if ( !v9 )
        break;
      v11 = *(_DWORD *)&v10->Type == *(_DWORD *)&a1->Type;
      v10 = (CHARSPEC *)((char *)v10 + 4);
      a1 = (CHARSPEC *)((char *)a1 + 4);
      --v9;
    }
    while ( v11 );
    if ( !v11 )
    {
      v13 = 765;
      goto LABEL_25;
    }
    if ( LogicalVolumeDescriptor->MapTableCount > 1 || v4 < 6 )
    {
      v13 = 776;
      goto LABEL_25;
    }
    if ( LOBYTE(LogicalVolumeDescriptor[1].Destag.Ident) == 1
      && HIBYTE(LogicalVolumeDescriptor[1].Destag.Ident) == 6
      && LogicalVolumeDescriptor[1].Destag.Version <= 1u )
    {
      FileSetDescriptorExtent->Length = LogicalVolumeDescriptor->FSD.Length;
      FileSetDescriptorExtent->Start.Lbn = LogicalVolumeDescriptor->FSD.Start.Lbn;
      *(_DWORD *)&FileSetDescriptorExtent->Start.Partition = *(_DWORD *)&LogicalVolumeDescriptor->FSD.Start.Partition;
      *(_DWORD *)&FileSetDescriptorExtent->ImpUse[2] = *(_DWORD *)&LogicalVolumeDescriptor->FSD.ImpUse[2];
      *PartitionNumber = *(_WORD *)&LogicalVolumeDescriptor[1].Destag.Checksum;
      return 1;
    }
    DbgPrint((int *)&a1->Type, "UDFX: invalid partition map descriptor (line %d)\n", 790);
  }
  return 0;
}