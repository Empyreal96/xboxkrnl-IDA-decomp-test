bool __userpurge IoIsNameInExpression@<al>(__int16 a1@<dx>, int a2@<ecx>, int *a3@<edi>, _STRING *TemplateFileName, _STRING *FileName)
{
  _STRING *v5; // ecx
  unsigned __int16 v6; // dx
  char *v8; // eax
  char *v9; // ebx
  unsigned int v10; // esi
  int *v11; // edi
  char *TemplateFileNameCurrent; // [esp+Ch] [ebp+8h]

  if ( !TemplateFileName->Length )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)TemplateFileName,
      "TemplateFileName->Length > 0",
      "d:\\xbox-apr03\\private\\ntos\\io\\fsrtl.c",
      0xC6u,
      0);
  v5 = FileName;
  v6 = FileName->Length;
  if ( !FileName->Length )
    return 0;
  v8 = TemplateFileName->Buffer;
  v9 = FileName->Buffer;
  v10 = (unsigned int)&v8[TemplateFileName->Length];
  v11 = (int *)&v9[v6];
  while ( 1 )
  {
    while ( 1 )
    {
      if ( (unsigned int)v8 >= v10 )
        return v9 == (char *)v11;
      LOBYTE(v6) = *v8++;
      TemplateFileNameCurrent = v8;
      if ( (_BYTE)v6 != 42 )
        break;
      if ( v8 == (char *)v10 )
        return 1;
      if ( *v8 != 46 )
      {
        RtlAssert(
          v6,
          (int)v5,
          v11,
          v10,
          "*TemplateFileNameCurrent == OTEXT('.')",
          "d:\\xbox-apr03\\private\\ntos\\io\\fsrtl.c",
          0xEBu,
          0);
        v8 = TemplateFileNameCurrent;
      }
      ++v8;
      do
      {
        if ( v9 == (char *)v11 )
          break;
        LOBYTE(v5) = *v9++;
      }
      while ( (_BYTE)v5 != 46 );
    }
    if ( v9 == (char *)v11 )
      break;
    LOBYTE(v5) = *v9++;
    if ( (_BYTE)v6 != 63 )
    {
      if ( (char)v5 >= 97 && (char)v5 <= 122 )
        LOBYTE(v5) = (_BYTE)v5 - 32;
      if ( (_BYTE)v5 != (_BYTE)v6 )
        break;
    }
  }
  return 0;
}