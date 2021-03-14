int __stdcall RtlAppendUnicodeStringToString(_UNICODE_STRING *Destination, _UNICODE_STRING *Source)
{
  _UNICODE_STRING *v2; // ecx
  unsigned __int16 v3; // dx
  unsigned int v4; // eax
  unsigned int v5; // edi
  char *v7; // ebx
  int n; // [esp+18h] [ebp+Ch]

  v2 = Source;
  v3 = Source->Length;
  n = Source->Length;
  if ( (_WORD)n )
  {
    v4 = Destination->Length;
    v5 = v3;
    if ( (signed int)(v3 + v4) > Destination->MaximumLength )
      return -1073741789;
    v7 = (char *)&Destination->Buffer[v4 >> 1];
    memmove(v7, (char *)v2->Buffer, v3);
    Destination->Length += n;
    if ( Destination->Length < Destination->MaximumLength )
      *(_WORD *)&v7[2 * (v5 >> 1)] = 0;
  }
  return 0;
}