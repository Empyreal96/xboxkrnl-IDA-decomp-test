void __stdcall RtlUpperString(_STRING *DestinationString, _STRING *SourceString)
{
  unsigned __int16 v2; // dx
  char *v3; // esi
  char *v4; // edi
  int v5; // eax
  int v6; // ebx

  v2 = DestinationString->MaximumLength;
  v3 = DestinationString->Buffer;
  v4 = SourceString->Buffer;
  v5 = SourceString->Length;
  if ( (unsigned __int16)v5 > v2 )
    v5 = v2;
  DestinationString->Length = v5;
  if ( v5 )
  {
    v6 = v5;
    do
    {
      *v3++ = RtlUpperChar(*v4++);
      --v6;
    }
    while ( v6 );
  }
}