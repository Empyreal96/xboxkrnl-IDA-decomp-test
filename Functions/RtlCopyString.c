void __stdcall RtlCopyString(_STRING *DestinationString, _STRING *SourceString)
{
  char *v2; // edi
  int v3; // eax
  unsigned __int16 v4; // dx
  char *v5; // esi

  if ( SourceString )
  {
    v2 = SourceString->Buffer;
    v3 = SourceString->Length;
    v4 = DestinationString->MaximumLength;
    v5 = DestinationString->Buffer;
    if ( (unsigned __int16)v3 > v4 )
      v3 = v4;
    for ( DestinationString->Length = v3; v3; --v3 )
      *v5++ = *v2++;
  }
  else
  {
    DestinationString->Length = 0;
  }
}