void __stdcall RtlInitUnicodeString(PUNICODE_STRING DestinationString, PCWSTR SourceString)
{
  PCWSTR v2; // edi
  signed int v3; // ecx
  bool v4; // zf
  unsigned __int16 v5; // cx

  v2 = SourceString;
  *(_DWORD *)&DestinationString->Length = 0;
  DestinationString->Buffer = (unsigned __int16 *)SourceString;
  if ( SourceString )
  {
    v3 = -1;
    do
    {
      if ( !v3 )
        break;
      v4 = *v2 == 0;
      ++v2;
      --v3;
    }
    while ( !v4 );
    v5 = 2 * ~(_WORD)v3;
    DestinationString->MaximumLength = v5;
    DestinationString->Length = v5 - 2;
  }
}