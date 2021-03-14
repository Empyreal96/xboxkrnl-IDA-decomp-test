char __stdcall UdfxEqualOSTACS0StringAndObjectString(char *OSTACS0String, unsigned int OSTACS0StringLength, _STRING *ObjectString)
{
  char *v3; // edi
  char *v5; // esi
  char v6; // al
  char v7; // cl
  char v8; // bl
  unsigned int OSTACS0StringLengtha; // [esp+10h] [ebp+Ch]
  char c1; // [esp+14h] [ebp+10h]

  if ( *OSTACS0String != 8 )
    return 0;
  v3 = OSTACS0String + 1;
  OSTACS0StringLengtha = OSTACS0StringLength - 1;
  if ( ObjectString->Length != OSTACS0StringLengtha )
    return 0;
  v5 = ObjectString->Buffer;
  if ( !OSTACS0StringLengtha )
    return 1;
  while ( 1 )
  {
    v6 = *v5;
    v7 = *v3;
    ++v5;
    ++v3;
    c1 = v6;
    if ( v6 != v7 )
    {
      v8 = RtlUpperChar(v7);
      if ( (unsigned __int8)RtlUpperChar(c1) != v8 )
        break;
    }
    if ( !--OSTACS0StringLengtha )
      return 1;
  }
  return 0;
}