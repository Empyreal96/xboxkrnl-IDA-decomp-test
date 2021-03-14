int __userpurge UdfxLookupElementNameInDirectory@<eax>(unsigned int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _UDF_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _UDF_FCB *DirectoryFcb, _STRING *ElementName, LONGAD *ElementIcb)
{
  unsigned int v8; // esi
  int v9; // edi
  int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // ecx
  $90DBE875D98C541648A110D255070AFE *v15; // eax
  unsigned int v16; // ebx
  int v17; // edx
  int v18; // ecx
  $90DBE875D98C541648A110D255070AFE *v19; // eax
  $90DBE875D98C541648A110D255070AFE Stack; // [esp+Ch] [ebp-124h]
  unsigned int ExpectedFileID8BitLength; // [esp+10Ch] [ebp-24h]
  _UDF_DIRECTORY_MAPPING DirectoryMapping; // [esp+110h] [ebp-20h]
  unsigned int FileIdentifierDescriptorLength; // [esp+138h] [ebp+8h]
  int status; // [esp+140h] [ebp+10h]

  v8 = (unsigned int)DirectoryFcb;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)DirectoryFcb,
      "UdfxIsFlagSet(DirectoryFcb->Flags, UDF_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
      0xE4u,
      0);
  v9 = ElementName->Length;
  DirectoryMapping.VolumeExtension = VolumeExtension;
  DirectoryMapping.Irp = Irp;
  v10 = v9 + 1;
  DirectoryMapping.LogicalSectorNumber = DirectoryFcb->AllocationSectorStart;
  v11 = DirectoryFcb->FileSize.LowPart;
  v12 = 0;
  ExpectedFileID8BitLength = v10;
  DirectoryMapping.DirectoryFcb = DirectoryFcb;
  DirectoryMapping.FileBytesRemaining = v11;
  DirectoryMapping.CacheBuffer = 0;
  for ( DirectoryMapping.CurrentBuffer = 0; ; DirectoryMapping.CurrentBuffer += a1 )
  {
    DirectoryMapping.CacheBytesRemaining = v12;
    if ( (signed int)v12 <= 0 )
    {
      status = UdfxMapNextDirectorySector(&DirectoryMapping);
      if ( status < 0 )
        goto LABEL_30;
      v12 = DirectoryMapping.CacheBytesRemaining;
    }
    if ( v12 >= 0x26 )
    {
      v15 = ($90DBE875D98C541648A110D255070AFE *)DirectoryMapping.CurrentBuffer;
    }
    else
    {
      if ( v12 + DirectoryMapping.FileBytesRemaining < 0x26 )
      {
        status = -1073741772;
        goto LABEL_30;
      }
      v8 = v12;
      UdfxCopyPartialDirectoryBuffer(
        a1,
        v12,
        (int *)v10,
        &DirectoryMapping,
        &Stack,
        DirectoryMapping.CurrentBuffer,
        v12);
      status = UdfxMapNextDirectorySector(&DirectoryMapping);
      if ( status < 0 )
        goto LABEL_30;
      UdfxCopyPartialDirectoryBuffer(
        v13,
        v14,
        (int *)v10,
        &DirectoryMapping,
        (char *)&Stack + v8,
        &DirectoryMapping.CurrentBuffer[v8],
        38 - v8);
      v12 = DirectoryMapping.CacheBytesRemaining;
      v15 = &Stack;
    }
    v16 = (unsigned __int8)v15->FileID[19];
    a1 = (*(unsigned __int16 *)&v15->FileID[36] + v16 + 41) & 0xFFFFFFFC;
    FileIdentifierDescriptorLength = (*(unsigned __int16 *)&v15->FileID[36] + v16 + 41) & 0xFFFFFFFC;
    if ( *(_WORD *)&v15->FileID[2] != 2 )
      break;
    if ( v15->FileIdentifierDescriptor.Destag.Ident != 257 )
      break;
    if ( a1 > 0x800 )
      break;
    v8 = v12 + DirectoryMapping.FileBytesRemaining;
    if ( a1 > v12 + DirectoryMapping.FileBytesRemaining )
      break;
    if ( v16 == v10 )
    {
      ElementIcb->Length = *(NSRLENGTH *)&v15->FileID[20];
      ElementIcb->Start.Lbn = v15->FileIdentifierDescriptor.Icb.Start.Lbn;
      *(_DWORD *)&ElementIcb->Start.Partition = *(_DWORD *)&v15->FileID[28];
      *(_DWORD *)&ElementIcb->ImpUse[2] = *(_DWORD *)&v15->FileID[32];
      v10 = (int)&ElementIcb[1];
      v8 = *(unsigned __int16 *)&v15->FileID[36] + 38;
      if ( v12 >= v8 + v16 )
      {
        v19 = ($90DBE875D98C541648A110D255070AFE *)&DirectoryMapping.CurrentBuffer[v8];
      }
      else
      {
        if ( v12 <= v8 )
        {
          v10 = 0;
        }
        else
        {
          v10 = v12 - v8;
          UdfxCopyPartialDirectoryBuffer(
            a1,
            v10,
            (int *)v10,
            &DirectoryMapping,
            &Stack,
            &DirectoryMapping.CurrentBuffer[v8],
            v10);
        }
        status = UdfxMapNextDirectorySector(&DirectoryMapping);
        if ( status < 0 )
          goto LABEL_30;
        v8 += (unsigned int)&DirectoryMapping.CurrentBuffer[v10];
        UdfxCopyPartialDirectoryBuffer(
          v17,
          v18,
          (int *)v10,
          &DirectoryMapping,
          (char *)&Stack + v10,
          (void *)v8,
          v16 - v10);
        v19 = &Stack;
      }
      if ( UdfxEqualOSTACS0StringAndObjectString((char *)v19, v16, ElementName) )
      {
        status = 0;
        goto LABEL_30;
      }
      v12 = DirectoryMapping.CacheBytesRemaining;
      v10 = ExpectedFileID8BitLength;
      a1 = FileIdentifierDescriptorLength;
    }
    v12 -= a1;
  }
  DbgPrint((int *)v10, "UDFX: file identifier descriptor doesn't verify\n");
  status = -1073741774;
LABEL_30:
  if ( DirectoryMapping.CacheBuffer )
    FscUnmapBuffer((int *)v10, v8, DirectoryMapping.CacheBuffer);
  return status;
}