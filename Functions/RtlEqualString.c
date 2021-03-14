char __stdcall RtlEqualString(_STRING *String1, _STRING *String2, char CaseInSensitive)
{
  int v3; // eax
  char *v4; // esi
  char *v5; // edi
  unsigned int v6; // eax
  char v7; // cl
  char v8; // dl
  char v9; // bl
  char v11; // cl
  char v12; // dl
  char c1; // [esp+14h] [ebp+8h]
  char *Limit; // [esp+18h] [ebp+Ch]

  v3 = String1->Length;
  if ( v3 != String2->Length )
    return 0;
  v4 = String1->Buffer;
  v5 = String2->Buffer;
  v6 = (unsigned int)&v4[v3];
  Limit = (char *)v6;
  if ( CaseInSensitive )
  {
    while ( (unsigned int)v4 < v6 )
    {
      v7 = *v4;
      v8 = *v5;
      ++v4;
      ++v5;
      c1 = v7;
      if ( v7 != v8 )
      {
        v9 = RtlUpperChar(v8);
        if ( (unsigned __int8)RtlUpperChar(c1) != v9 )
          return 0;
        v6 = (unsigned int)Limit;
      }
    }
  }
  else
  {
    while ( (unsigned int)v4 < v6 )
    {
      v11 = *v4;
      v12 = *v5;
      ++v4;
      ++v5;
      if ( v11 != v12 )
        return 0;
    }
  }
  return 1;
}