char __userpurge RtlPrefixString@<al>(int a1@<edi>, _STRING *String1, _STRING *String2, char CaseInSensitive)
{
  char *v4; // edx
  char *v5; // esi
  int v7; // edx
  char v8; // al
  char v9; // cl
  char v10; // al
  char v11; // cl
  char v12; // bl
  char c1; // [esp+10h] [ebp+8h]
  char *s2; // [esp+14h] [ebp+Ch]

  v4 = String2->Buffer;
  v5 = String1->Buffer;
  LOWORD(a1) = String1->Length;
  if ( String2->Length < String1->Length )
    return 0;
  if ( CaseInSensitive )
  {
    while ( (_WORD)a1 )
    {
      v10 = *v5;
      v11 = *v4;
      ++v5;
      ++v4;
      c1 = v10;
      s2 = v4;
      if ( v10 != v11 )
      {
        v12 = RtlUpperChar(v11);
        if ( (unsigned __int8)RtlUpperChar(c1) != v12 )
          return 0;
        v4 = s2;
      }
      LOWORD(a1) = a1 - 1;
    }
    return 1;
  }
  if ( !(_WORD)a1 )
    return 1;
  v7 = v4 - v5;
  while ( 1 )
  {
    v8 = *v5;
    v9 = (v5++)[v7];
    if ( v8 != v9 )
      break;
    a1 += 0xFFFF;
    if ( !(_WORD)a1 )
      return 1;
  }
  return 0;
}