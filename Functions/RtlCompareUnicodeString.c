int __stdcall RtlCompareUnicodeString(_UNICODE_STRING *String1, _UNICODE_STRING *String2, int CaseInSensitive)
{
  unsigned __int16 *v3; // edx
  int v4; // ecx
  unsigned __int16 *v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  unsigned __int16 *v8; // eax
  unsigned __int16 v9; // cx
  unsigned __int16 v10; // cx
  unsigned __int16 v12; // cx
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // dx
  unsigned __int16 v15; // cx
  unsigned __int16 *Limit; // [esp+Ch] [ebp-Ch]
  int n1; // [esp+10h] [ebp-8h]
  int n2; // [esp+14h] [ebp-4h]
  int c1; // [esp+20h] [ebp+8h]
  unsigned __int16 *s2; // [esp+24h] [ebp+Ch]

  v3 = String2->Buffer;
  v4 = String2->Length;
  v5 = String1->Buffer;
  s2 = String2->Buffer;
  n1 = String1->Length;
  n2 = v4;
  if ( String1->Length & 1 )
    RtlAssert(
      (int)v3,
      v4,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c",
      "(n1 & 1) == 0",
      "d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c",
      0x21Du,
      0);
  if ( n2 & 1 )
    RtlAssert(
      (int)v3,
      v4,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c",
      "(n2 & 1) == 0",
      "d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c",
      0x21Eu,
      0);
  if ( ((unsigned __int8)v5 & 1 || (unsigned __int8)s2 & 1) && n1 && n2 )
    RtlAssert(
      (int)v3,
      v4,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c",
      "!(((((ULONG_PTR)s1 & 1) != 0) || (((ULONG_PTR)s2 & 1) != 0)) && (n1 != 0) && (n2 != 0))",
      "d:\\xbox-apr03\\private\\ntos\\rtl\\nls.c",
      0x21Fu,
      0);
  v6 = n1;
  if ( n1 > n2 )
    v6 = n2;
  v7 = (unsigned int)v5 + v6;
  Limit = (unsigned __int16 *)((char *)v5 + v6);
  if ( (_BYTE)CaseInSensitive )
  {
    while ( 1 )
    {
      do
      {
        if ( (unsigned int)v5 >= v7 )
          return n1 - n2;
        v12 = *s2;
        ++s2;
        v13 = *v5;
        ++v5;
        LOWORD(CaseInSensitive) = v12;
      }
      while ( v13 == v12 );
      if ( v13 < 0x61u )
        goto LABEL_21;
      if ( v13 <= 0x7Au )
        break;
      v14 = v13
          - *(_WORD *)(2
                     * ((v13 & 0xF)
                      + 4
                      * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)v13 >> 8]
                                                                      + (((unsigned int)v13 >> 4) & 0xF)])
                     - 2147399760);
LABEL_25:
      if ( v12 < 0x61u )
        goto LABEL_26;
      if ( v12 <= 0x7Au )
      {
        CaseInSensitive += 65504;
LABEL_26:
        v15 = CaseInSensitive;
        goto LABEL_30;
      }
      v15 = v12
          - *(_WORD *)(2
                     * ((v12 & 0xF)
                      + 4
                      * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)v12 >> 8]
                                                                      + (((unsigned int)v12 >> 4) & 0xF)])
                     - 2147399760);
LABEL_30:
      if ( v14 != v15 )
        return v14 - v15;
      v7 = (unsigned int)Limit;
    }
    v13 -= 32;
LABEL_21:
    v14 = v13;
    goto LABEL_25;
  }
  if ( (unsigned int)v5 >= v7 )
    return n1 - n2;
  v8 = s2;
  while ( 1 )
  {
    v9 = *v5;
    ++v5;
    c1 = v9;
    v10 = *v8;
    ++v8;
    if ( (_WORD)c1 != v10 )
      break;
    if ( (unsigned int)v5 >= v7 )
      return n1 - n2;
  }
  return (unsigned __int16)c1 - v10;
}