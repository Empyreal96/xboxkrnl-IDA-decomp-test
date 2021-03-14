int __userpurge UdfxReadNextFileIdentifierDescriptor@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _UDF_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _UDF_FCB *DirectoryFcb, _DIRECTORY_ENUM_CONTEXT *DirectoryEnumContext, NSR_FID **ReturnedFileIdentifierDescriptor)
{
  unsigned int v9; // edi
  unsigned int v10; // eax
  int *v11; // edi
  int v12; // esi
  int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // ebx
  void *v16; // edx
  char *v17; // esi
  char *v18; // edi
  char *v19; // esi
  int v20; // ecx
  NSR_FID *v21; // esi
  int v22; // ecx
  unsigned int v23; // eax
  int v24; // edx
  int v25; // ecx
  NSR_FID *v26; // eax
  unsigned int v27; // ecx
  NSR_FID *v28; // edi
  char *v29; // edi
  char *v30; // esi
  int v31; // ecx
  char v32; // al
  unsigned int v33; // ecx
  int *v34; // edi
  char *v35; // esi
  int v36; // ecx
  NSR_FID StackFileIdentifierDescriptor; // [esp+Ch] [ebp-3Ch]
  unsigned int FileBytesRemaining; // [esp+38h] [ebp-10h]
  unsigned int LogicalSectorNumber; // [esp+3Ch] [ebp-Ch]
  NSR_FID *PoolFileIdentifierDescriptor; // [esp+40h] [ebp-8h]
  void *CacheBuffer; // [esp+44h] [ebp-4h]
  unsigned int FileIdentifierDescriptorLength; // [esp+5Ch] [ebp+14h]

  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "UdfxIsFlagSet(DirectoryFcb->Flags, UDF_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\udfx\\dirctrl.c",
      0x40u,
      0);
  *ReturnedFileIdentifierDescriptor = 0;
  v9 = DirectoryFcb->FileSize.LowPart;
  CacheBuffer = 0;
  PoolFileIdentifierDescriptor = 0;
  v10 = DirectoryEnumContext->QueryOffset;
  v11 = (int *)(v9 - DirectoryEnumContext->QueryOffset);
  FileBytesRemaining = (unsigned int)v11;
  if ( (unsigned int)v11 < 0x26 )
    return -1073741807;
  LogicalSectorNumber = DirectoryFcb->AllocationSectorStart + (v10 >> 11);
  v12 = UdfxMapLogicalSector(VolumeExtension, Irp, LogicalSectorNumber, &CacheBuffer);
  if ( v12 >= 0 )
  {
    v14 = DirectoryEnumContext->QueryOffset & 0x7FF;
    if ( DirectoryFcb->Flags & 8 )
      v14 += DirectoryFcb->EmbeddedDataOffset;
    v15 = 2048 - v14;
    if ( 2048 - v14 >= 0x26 )
    {
      v21 = (NSR_FID *)((char *)CacheBuffer + v14);
    }
    else
    {
      v16 = CacheBuffer;
      v17 = (char *)CacheBuffer + v14;
      qmemcpy(&StackFileIdentifierDescriptor, (char *)CacheBuffer + v14, 4 * (v15 >> 2));
      v19 = &v17[4 * (v15 >> 2)];
      v18 = (char *)&StackFileIdentifierDescriptor + 4 * (v15 >> 2);
      v20 = -(char)v14 & 3;
      qmemcpy(v18, v19, v20);
      v11 = (int *)&v18[v20];
      FscUnmapBuffer(v11, (int)&v19[v20], v16);
      CacheBuffer = 0;
      v12 = UdfxMapLogicalSector(VolumeExtension, Irp, ++LogicalSectorNumber, &CacheBuffer);
      if ( v12 < 0 )
        goto LABEL_32;
      qmemcpy((char *)&StackFileIdentifierDescriptor + v15, CacheBuffer, 38 - v15);
      v11 = (int *)FileBytesRemaining;
      v21 = &StackFileIdentifierDescriptor;
    }
    v22 = (unsigned __int8)v21->FileIDLen;
    v23 = (v21->ImpUseLen + v22 + 41) & 0xFFFFFFFC;
    FileIdentifierDescriptorLength = (v21->ImpUseLen + v22 + 41) & 0xFFFFFFFC;
    if ( v21->Destag.Version != 2 || v21->Destag.Ident != 257 || v23 > 0x800 || v23 > (unsigned int)v11 )
    {
      v12 = -1073741774;
CleanupAndExit_31:
      if ( PoolFileIdentifierDescriptor )
        ExFreePool(PoolFileIdentifierDescriptor);
      goto LABEL_32;
    }
    v11 = ExAllocatePoolWithTag(v13, v22, (int)v21, v23, 0x69467855u);
    PoolFileIdentifierDescriptor = (NSR_FID *)v11;
    if ( !v11 )
    {
      v12 = -1073741670;
      goto CleanupAndExit_31;
    }
    if ( v21 == &StackFileIdentifierDescriptor )
    {
      if ( DirectoryFcb->Flags & 8 )
        RtlAssert(
          v24,
          v25,
          v11,
          (int)v21,
          "UdfxIsFlagClear(DirectoryFcb->Flags, UDF_FCB_EMBEDDED_DATA)",
          "d:\\xbox-apr03\\private\\ntos\\udfx\\dirctrl.c",
          0xD4u,
          0);
      v26 = PoolFileIdentifierDescriptor;
      qmemcpy(PoolFileIdentifierDescriptor, &StackFileIdentifierDescriptor, v15);
    }
    else
    {
      v27 = FileIdentifierDescriptorLength;
      if ( v15 >= FileIdentifierDescriptorLength )
      {
LABEL_28:
        v32 = v27;
        v33 = v27 >> 2;
        qmemcpy(v11, v21, 4 * v33);
        v35 = (char *)v21 + 4 * v33;
        v34 = &v11[v33];
        v36 = v32 & 3;
        qmemcpy(v34, v35, v36);
        v11 = (int *)((char *)v34 + v36);
        *ReturnedFileIdentifierDescriptor = PoolFileIdentifierDescriptor;
        v12 = 0;
        goto LABEL_32;
      }
      if ( DirectoryFcb->Flags & 8 )
        RtlAssert(
          v24,
          FileIdentifierDescriptorLength,
          v11,
          (int)v21,
          "UdfxIsFlagClear(DirectoryFcb->Flags, UDF_FCB_EMBEDDED_DATA)",
          "d:\\xbox-apr03\\private\\ntos\\udfx\\dirctrl.c",
          0xE4u,
          0);
      v28 = PoolFileIdentifierDescriptor;
      qmemcpy(PoolFileIdentifierDescriptor, v21, 4 * (v15 >> 2));
      v30 = (char *)v21 + 4 * (v15 >> 2);
      v29 = (char *)v28 + 4 * (v15 >> 2);
      v31 = v15 & 3;
      qmemcpy(v29, v30, v31);
      v11 = (int *)&v29[v31];
      FscUnmapBuffer(v11, (int)&v30[v31], CacheBuffer);
      CacheBuffer = 0;
      v12 = UdfxMapLogicalSector(VolumeExtension, Irp, LogicalSectorNumber + 1, &CacheBuffer);
      if ( v12 < 0 )
        goto CleanupAndExit_31;
      v26 = PoolFileIdentifierDescriptor;
    }
    v21 = (NSR_FID *)CacheBuffer;
    v27 = FileIdentifierDescriptorLength - v15;
    v11 = (int *)((char *)v26 + v15);
    goto LABEL_28;
  }
LABEL_32:
  if ( CacheBuffer )
    FscUnmapBuffer(v11, v12, CacheBuffer);
  return v12;
}