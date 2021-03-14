char __fastcall RtlEqualUnicodeString(int a1, int a2, _UNICODE_STRING *String1, _UNICODE_STRING *String2, char CaseInSensitive)
{
  _UNICODE_STRING *v5; // esi
  unsigned __int16 *v6; // ebx
  int *v7; // edi
  unsigned __int16 *v8; // ebx
  unsigned int v9; // edi
  unsigned __int16 *v10; // ecx
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // si
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // dx
  int v15; // ecx
  int v16; // eax
  int n1; // [esp+Ch] [ebp-4h]
  unsigned __int16 *s2; // [esp+18h] [ebp+8h]
  unsigned __int16 *Limit; // [esp+1Ch] [ebp+Ch]
  unsigned __int16 *Limita; // [esp+1Ch] [ebp+Ch]

  v5 = String1;
  v6 = (unsigned __int16 *)String1->Length;
  v7 = (int *)String2;
  n1 = String1->Length;
  Limit = (unsigned __int16 *)String2->Length;
  if ( (unsigned __int8)v6 & 1 )
    RtlAssert(a2, a1, v7, (int)String1, "(n1 & 1) == 0", "d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c", 0x26Bu, 0);
  if ( (unsigned __int8)Limit & 1 )
    RtlAssert(a2, a1, v7, (int)String1, "(n2 & 1) == 0", "d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c", 0x26Cu, 0);
  if ( v6 != Limit )
    return 0;
  v8 = String1->Buffer;
  s2 = (unsigned __int16 *)v7[1];
  if ( (unsigned __int8)v8 & 1 || v7[1] & 1 )
  {
    if ( n1 )
    {
      if ( Limit )
        RtlAssert(
          a2,
          a1,
          v7,
          (int)v5,
          "!(((((ULONG_PTR)s1 & 1) != 0) || (((ULONG_PTR)s2 & 1) != 0)) && (n1 != 0) && (n2 != 0))",
          "d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c",
          0x272u,
          0);
    }
  }
  v9 = (unsigned int)v8 + n1;
  Limita = (unsigned __int16 *)((char *)v8 + n1);
  if ( CaseInSensitive )
  {
    while ( 1 )
    {
      do
      {
        if ( (unsigned int)v8 >= v9 )
          return 1;
        v13 = *v8;
        v14 = *s2;
        ++s2;
        ++v8;
      }
      while ( v13 == v14 );
      if ( v13 >= 0x61u )
      {
        if ( v13 <= 0x7Au )
        {
          v15 = v13 - 32;
          goto LABEL_23;
        }
        v13 -= *(_WORD *)(2
                        * ((v13 & 0xF)
                         + 4
                         * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)v13 >> 8]
                                                                         + ((unsigned __int8)v13 >> 4)])
                        - 2147399760);
      }
      v15 = v13;
LABEL_23:
      if ( v14 >= 0x61u )
      {
        if ( v14 <= 0x7Au )
        {
          v16 = v14 - 32;
          goto LABEL_28;
        }
        v14 -= *(_WORD *)(2
                        * ((v14 & 0xF)
                         + 4
                         * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)v14 >> 8]
                                                                         + ((unsigned __int8)v14 >> 4)])
                        - 2147399760);
      }
      v16 = v14;
LABEL_28:
      if ( v15 != v16 )
        return 0;
      v9 = (unsigned int)Limita;
    }
  }
  if ( (unsigned int)v8 >= v9 )
    return 1;
  v10 = s2;
  while ( 1 )
  {
    v11 = *v8;
    v12 = *v10;
    ++v8;
    ++v10;
    if ( v11 != v12 )
      break;
    if ( (unsigned int)v8 >= v9 )
      return 1;
  }
  return 0;
}