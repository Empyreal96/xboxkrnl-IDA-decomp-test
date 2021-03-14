int __userpurge UdfxFindNextFileIdentifierDescriptor@<eax>(int a1@<edx>, int a2@<ecx>, NSR_FID *a3@<esi>, _UDF_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _UDF_FCB *DirectoryFcb, _DIRECTORY_ENUM_CONTEXT *DirectoryEnumContext, NSR_FID **ReturnedFileIdentifierDescriptor, _STRING *FileName)
{
  _DIRECTORY_ENUM_CONTEXT *v9; // edi
  unsigned __int8 v10; // al
  __int16 v11; // dx
  int v12; // ecx
  int v13; // ebx
  _STRING *v14; // ebx
  int v15; // eax
  int v16; // edx
  int v17; // ecx

  v9 = DirectoryEnumContext;
  while ( 1 )
  {
    v15 = UdfxReadNextFileIdentifierDescriptor(
            a1,
            a2,
            (int *)v9,
            (int)a3,
            VolumeExtension,
            Irp,
            DirectoryFcb,
            v9,
            (NSR_FID **)&DirectoryEnumContext);
    a3 = (NSR_FID *)DirectoryEnumContext;
    v13 = v15;
    if ( v15 < 0 )
      break;
    v10 = HIBYTE(DirectoryEnumContext[1].TemplateFileName.MaximumLength);
    if ( v10 )
    {
      v13 = UdfxOSTACS0StringToObjectString(
              v17,
              v16,
              (char *)&DirectoryEnumContext[3].QueryOffset + LOWORD(DirectoryEnumContext[3].QueryOffset) + 2,
              v10,
              FileName);
      if ( v13 < 0 )
        break;
      if ( !v9->TemplateFileName.Buffer
        || (v14 = FileName, IoIsNameInExpression(v11, v12, (int *)v9, &v9->TemplateFileName, FileName)) )
      {
        *ReturnedFileIdentifierDescriptor = a3;
        return 0;
      }
      ExFreePool(v14->Buffer);
    }
    v9->QueryOffset += (a3->ImpUseLen + (unsigned __int8)a3->FileIDLen + 41) & 0xFFFFFFFC;
    ExFreePool(a3);
    DirectoryEnumContext = 0;
  }
  if ( a3 )
    ExFreePool(a3);
  return v13;
}