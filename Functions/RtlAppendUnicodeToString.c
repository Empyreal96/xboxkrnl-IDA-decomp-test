int __stdcall RtlAppendUnicodeToString(_UNICODE_STRING *Destination, const unsigned __int16 *Source)
{
  unsigned int v2; // eax
  int v3; // edx
  unsigned int v4; // edi
  char *v6; // ebx
  _UNICODE_STRING UniSource; // [esp+8h] [ebp-Ch]
  int n; // [esp+10h] [ebp-4h]

  if ( Source )
  {
    RtlInitUnicodeString(&UniSource, Source);
    v2 = Destination->Length;
    v3 = Destination->MaximumLength;
    v4 = UniSource.Length;
    n = *(_DWORD *)&UniSource.Length;
    if ( (signed int)(UniSource.Length + v2) > v3 )
      return -1073741789;
    v6 = (char *)&Destination->Buffer[v2 >> 1];
    memmove(v6, (char *)Source, UniSource.Length);
    Destination->Length += n;
    if ( Destination->Length < Destination->MaximumLength )
      *(_WORD *)&v6[2 * (v4 >> 1)] = 0;
  }
  return 0;
}