void __stdcall RtlInitAnsiString(PANSI_STRING DestinationString, PCSZ SourceString)
{
  unsigned int v2; // kr04_4

  *(_DWORD *)&DestinationString->Length = 0;
  DestinationString->Buffer = (char *)SourceString;
  if ( SourceString )
  {
    v2 = strlen(SourceString) + 1;
    DestinationString->MaximumLength = v2;
    DestinationString->Length = v2 - 1;
  }
}