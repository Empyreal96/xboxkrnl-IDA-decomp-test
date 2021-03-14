char __stdcall RtlCreateUnicodeString(_UNICODE_STRING *DestinationString, const unsigned __int16 *SourceString)
{
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  int *v5; // eax

  v2 = 2 * wcslen(SourceString) + 2;
  v5 = ExAllocatePoolWithTag(v3, v4, v2, v2, 0x67727453u);
  DestinationString->Buffer = (unsigned __int16 *)v5;
  if ( !v5 )
    return 0;
  memmove((char *)v5, (char *)SourceString, v2);
  DestinationString->MaximumLength = v2;
  DestinationString->Length = v2 - 2;
  return 1;
}