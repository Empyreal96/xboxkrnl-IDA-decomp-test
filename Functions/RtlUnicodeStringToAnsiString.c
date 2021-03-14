int __fastcall RtlUnicodeStringToAnsiString(int a1, int a2, _STRING *DestinationString, _UNICODE_STRING *SourceString, char AllocateDestinationString)
{
  _UNICODE_STRING *v5; // edi
  signed int v6; // ebx
  unsigned int v7; // eax
  int result; // eax
  bool v9; // zf
  int v10; // ecx
  int *v11; // eax
  unsigned __int16 v12; // ax
  int v13; // edi

  v5 = SourceString;
  v6 = 0;
  v7 = ((unsigned int)SourceString->Length + 2) >> 1;
  if ( v7 > 0xFFFF )
    return -1073741584;
  v9 = AllocateDestinationString == 0;
  v10 = v7 - 1;
  DestinationString->Length = v7 - 1;
  if ( v9 )
  {
    v12 = DestinationString->MaximumLength;
    if ( (unsigned __int16)v10 >= v12 )
    {
      if ( !v12 )
        return -2147483643;
      v6 = -2147483643;
      DestinationString->Length = v12 - 1;
    }
  }
  else
  {
    DestinationString->MaximumLength = v7;
    v11 = ExAllocatePoolWithTag(a2, v10, (int)DestinationString, v7, 0x67727453u);
    DestinationString->Buffer = (char *)v11;
    if ( !v11 )
      return -1073741801;
  }
  v13 = RtlUnicodeToMultiByteN(
          DestinationString->Buffer,
          DestinationString->Length,
          (unsigned int *)&SourceString,
          v5->Buffer,
          v5->Length);
  if ( v13 >= 0 )
  {
    *((_BYTE *)&SourceString->Length + (unsigned int)DestinationString->Buffer) = 0;
    result = v6;
  }
  else
  {
    if ( AllocateDestinationString )
    {
      ExFreePool(DestinationString->Buffer);
      DestinationString->Buffer = 0;
    }
    result = v13;
  }
  return result;
}