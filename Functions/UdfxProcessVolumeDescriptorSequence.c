int __fastcall UdfxProcessVolumeDescriptorSequence(int a1, int a2, _UDF_VOLUME_EXTENSION *VolumeExtension, EXTENTAD *VolumeDescriptorSequenceExtent, LONGAD *FileSetDescriptorExtent)
{
  NSR_PVD *v5; // edi
  unsigned int v7; // ebx
  unsigned int v8; // esi
  unsigned int v9; // esi
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // ax
  int PartitionNumber; // [esp+Ch] [ebp-1Ch]
  int ExpectedPartitionNumber; // [esp+10h] [ebp-18h]
  unsigned int PrevailingLVOLVolDescSeqNum; // [esp+14h] [ebp-14h]
  unsigned int PrevailingPartitionVolDescSeqNum; // [esp+18h] [ebp-10h]
  unsigned int PrevailingPVDVolDescSeqNum; // [esp+1Ch] [ebp-Ch]
  int status; // [esp+20h] [ebp-8h]
  char SeenPartitionDescriptor; // [esp+26h] [ebp-2h]
  char SeenLogicalVolumeDescriptor; // [esp+27h] [ebp-1h]
  char SeenPrimaryVolumeDescriptor_3; // [esp+37h] [ebp+Fh]

  if ( !VolumeDescriptorSequenceExtent->Len || VolumeDescriptorSequenceExtent->Len & 0x7FF )
    return -1073741774;
  v5 = (NSR_PVD *)ExAllocatePoolWithTag(a2, a1, (int)VolumeDescriptorSequenceExtent, 0x800u, 0x64567855u);
  if ( !v5 )
    return -1073741670;
  PrevailingPVDVolDescSeqNum = 0;
  PrevailingPartitionVolDescSeqNum = 0;
  PrevailingLVOLVolDescSeqNum = 0;
  PartitionNumber = 0;
  ExpectedPartitionNumber = 0;
  v7 = VolumeDescriptorSequenceExtent->Lsn;
  v8 = VolumeDescriptorSequenceExtent->Len >> 11;
  SeenPrimaryVolumeDescriptor_3 = 0;
  SeenPartitionDescriptor = 0;
  SeenLogicalVolumeDescriptor = 0;
  status = -1073741489;
  v9 = v7 + v8;
  while ( v7 < v9 )
  {
    status = UdfxReadPhysicalSector(VolumeExtension, v7, v5);
    if ( status < 0 )
      break;
    v10 = v5->Destag.Ident;
    status = -1073741489;
    if ( !UdfxVerifyDescriptor(&v5->Destag, 0x200u, v10, v7) )
    {
      DbgPrint((int *)v5, "UDFX: invalid descriptor (line %d)\n", 924);
      break;
    }
    v11 = v5->Destag.Ident;
    if ( v5->Destag.Ident == 1 )
    {
      if ( v5->VolDescSeqNum >= PrevailingPVDVolDescSeqNum )
      {
        SeenPrimaryVolumeDescriptor_3 = UdfxProcessPrimaryVolumeDescriptor((int *)v5, v5);
        PrevailingPVDVolDescSeqNum = v5->VolDescSeqNum;
      }
    }
    else
    {
      switch ( v11 )
      {
        case 5u:
          if ( v5->VolDescSeqNum >= PrevailingPartitionVolDescSeqNum )
          {
            SeenPartitionDescriptor = UdfxProcessPartitionDescriptor(
                                        (NSR_PART *)v5,
                                        VolumeExtension,
                                        (unsigned __int16 *)&PartitionNumber);
            PrevailingPartitionVolDescSeqNum = v5->VolDescSeqNum;
          }
          break;
        case 6u:
          if ( v5->VolDescSeqNum >= PrevailingLVOLVolDescSeqNum )
          {
            SeenLogicalVolumeDescriptor = UdfxProcessLogicalVolumeDescriptor(
                                            (CHARSPEC *)v5,
                                            (NSR_LVOL *)v5,
                                            FileSetDescriptorExtent,
                                            (unsigned __int16 *)&ExpectedPartitionNumber);
            PrevailingLVOLVolDescSeqNum = v5->VolDescSeqNum;
          }
          break;
        case 8u:
          if ( SeenPrimaryVolumeDescriptor_3
            && SeenLogicalVolumeDescriptor
            && SeenPartitionDescriptor
            && (_WORD)PartitionNumber == (_WORD)ExpectedPartitionNumber )
          {
            status = 0;
          }
          goto LABEL_27;
      }
    }
    ++v7;
  }
LABEL_27:
  ExFreePool(v5);
  return status;
}