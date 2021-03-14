char __stdcall IopCopyTemplateFileName(_STRING *TargetTemplateFileName, _STRING *SourceTemplateFileName)
{
  char *v2; // ecx
  char *v3; // esi
  char v4; // bl
  unsigned int v5; // eax
  char v6; // dl

  v2 = SourceTemplateFileName->Buffer;
  v3 = TargetTemplateFileName->Buffer;
  v4 = 0;
  v5 = (unsigned int)&v2[SourceTemplateFileName->Length];
  while ( 1 )
  {
    if ( (unsigned int)v2 >= v5 )
      return 1;
    v6 = *v2++;
    if ( v4 )
      break;
LABEL_5:
    if ( v6 == 42 )
    {
      v4 = 1;
    }
    else if ( v6 >= 97 && v6 <= 122 )
    {
      v6 -= 32;
    }
    *v3++ = v6;
  }
  if ( v6 == 46 )
  {
    v4 = 0;
    goto LABEL_5;
  }
  return 0;
}