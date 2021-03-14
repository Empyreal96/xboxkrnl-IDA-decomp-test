int __fastcall RtlUpcaseUnicodeString(int a1, int a2, _UNICODE_STRING *DestinationString, _UNICODE_STRING *SourceString, char AllocateDestinationString)
{
  _UNICODE_STRING *v5; // esi
  unsigned __int16 v6; // ax
  int *v7; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // cx
  unsigned int StopIndex; // [esp+14h] [ebp+Ch]
  unsigned int Index; // [esp+18h] [ebp+10h]

  v5 = SourceString;
  v6 = SourceString->Length;
  if ( AllocateDestinationString )
  {
    DestinationString->MaximumLength = v6;
    v7 = ExAllocatePoolWithTag(a2, a1, (int)SourceString, v6, 0x67727453u);
    DestinationString->Buffer = (unsigned __int16 *)v7;
    if ( !v7 )
      return -1073741801;
  }
  else if ( v6 > DestinationString->MaximumLength )
  {
    return -2147483643;
  }
  v9 = (unsigned int)SourceString->Length >> 1;
  v10 = 0;
  StopIndex = v9;
  Index = 0;
  if ( v9 )
  {
    do
    {
      v11 = v5->Buffer[v10];
      if ( v11 >= 0x61u )
      {
        if ( v11 > 0x7Au )
        {
          v12 = v5->Buffer[v10];
          v9 = StopIndex;
          v11 = v12
              - *(_WORD *)(2
                         * ((v12 & 0xF)
                          + 4
                          * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)v12 >> 8]
                                                                          + (((unsigned int)v12 >> 4) & 0xF)])
                         - 2147399760);
          v10 = Index;
        }
        else
        {
          v11 -= 32;
        }
      }
      DestinationString->Buffer[v10++] = v11;
      Index = v10;
    }
    while ( v10 < v9 );
  }
  DestinationString->Length = v5->Length;
  return 0;
}