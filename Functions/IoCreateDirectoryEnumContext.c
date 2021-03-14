int __userpurge IoCreateDirectoryEnumContext@<eax>(int a1@<edx>, int a2@<esi>, _STRING *TemplateFileName, _DIRECTORY_ENUM_CONTEXT **ReturnedDirectoryEnumContext)
{
  _BYTE *v4; // ecx
  unsigned __int16 v5; // ax
  int v6; // ebx
  _DIRECTORY_ENUM_CONTEXT *v7; // esi
  int result; // eax

  v4 = TemplateFileName;
  if ( TemplateFileName
    && (v5 = TemplateFileName->Length) != 0
    && (v5 != 1 || (v4 = TemplateFileName->Buffer, *v4 != 42)) )
  {
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = (_DIRECTORY_ENUM_CONTEXT *)ExAllocatePoolWithTag(a1, (int)v4, a2, v6 + 12, 0x65446F49u);
  if ( !v7 )
    return -1073741670;
  v7->QueryOffset = 0;
  *(_DWORD *)&v7->TemplateFileName.Length = 0;
  v7->TemplateFileName.Buffer = 0;
  if ( !v6
    || (v7->TemplateFileName.Length = v6,
        v7->TemplateFileName.MaximumLength = v6,
        v7->TemplateFileName.Buffer = (char *)&v7[1],
        IopCopyTemplateFileName(&v7->TemplateFileName, TemplateFileName)) )
  {
    *ReturnedDirectoryEnumContext = v7;
    result = 0;
  }
  else
  {
    ExFreePool(v7);
    result = -1073741811;
  }
  return result;
}