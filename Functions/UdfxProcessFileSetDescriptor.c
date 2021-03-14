int __fastcall UdfxProcessFileSetDescriptor(int a1, int a2, _UDF_VOLUME_EXTENSION *VolumeExtension, LONGAD *FileSetDescriptorExtent, LONGAD *IcbRoot)
{
  LONGAD *v5; // esi
  int *v6; // edi
  unsigned int v8; // eax
  unsigned int v9; // ebx
  unsigned __int16 *v10; // edi
  _DWORD *v11; // esi
  unsigned int v12; // eax
  unsigned int PrevailingFSDFileSet; // [esp+8h] [ebp-10h]
  int status; // [esp+Ch] [ebp-Ch]
  NSR_VD_GENERIC *VolumeDataStructure; // [esp+10h] [ebp-8h]
  unsigned int LogicalSectorNumber; // [esp+14h] [ebp-4h]
  char SeenFileSetDescriptor_3; // [esp+27h] [ebp+Fh]

  v5 = FileSetDescriptorExtent;
  if ( !(*(_DWORD *)&FileSetDescriptorExtent->Length & 0x3FFFFFFF)
    || *(_DWORD *)&FileSetDescriptorExtent->Length & 0xC00007FF )
  {
    return -1073741774;
  }
  v6 = ExAllocatePoolWithTag(a2, a1, (int)FileSetDescriptorExtent, 0x800u, 0x64567855u);
  VolumeDataStructure = (NSR_VD_GENERIC *)v6;
  if ( !v6 )
    return -1073741670;
  v8 = FileSetDescriptorExtent->Start.Lbn;
  PrevailingFSDFileSet = 0;
  v9 = v8 + ((*(_DWORD *)&FileSetDescriptorExtent->Length >> 11) & 0x7FFFF);
  SeenFileSetDescriptor_3 = 0;
  status = -1073741774;
  LogicalSectorNumber = v5->Start.Lbn;
  if ( v8 < v9 )
  {
    while ( v8 < VolumeExtension->PartitionSectorCount )
    {
      status = UdfxReadPhysicalSector(VolumeExtension, v8 + VolumeExtension->PartitionSectorStart, v6);
      if ( status < 0 )
        break;
      status = -1073741774;
      if ( !UdfxVerifyDescriptor((DESTAG *)v6, 0x200u, *(_WORD *)v6, LogicalSectorNumber) )
      {
        DbgPrint(v6, "UDFX: invalid descriptor (line %d)\n", 1138);
        break;
      }
      if ( *(_WORD *)v6 != 256 )
      {
        if ( *(_WORD *)v6 == 8 && SeenFileSetDescriptor_3 )
          status = 0;
        break;
      }
      if ( v6[10] < PrevailingFSDFileSet )
        goto LABEL_27;
      IcbRoot->Length = (NSRLENGTH)v6[100];
      IcbRoot->Start.Lbn = v6[101];
      v11 = v6 + 102;
      v10 = &IcbRoot->Start.Partition;
      *(_DWORD *)v10 = *v11;
      *((_DWORD *)v10 + 1) = v11[1];
      v12 = *(_DWORD *)&VolumeDataStructure->Data20[428];
      v6 = (int *)VolumeDataStructure;
      PrevailingFSDFileSet = *(_DWORD *)&VolumeDataStructure->Data20[20];
      SeenFileSetDescriptor_3 = 1;
      if ( v12 & 0x3FFFFFFF )
      {
        if ( v12 & 0xC00007FF )
          break;
        LogicalSectorNumber = *(_DWORD *)&VolumeDataStructure->Data20[432];
        v9 = *(_DWORD *)&VolumeDataStructure->Data20[432] + ((v12 >> 11) & 0x7FFFF);
      }
      else
      {
LABEL_27:
        ++LogicalSectorNumber;
      }
      if ( LogicalSectorNumber >= v9 )
        break;
      v8 = LogicalSectorNumber;
    }
  }
  ExFreePool(v6);
  return status;
}