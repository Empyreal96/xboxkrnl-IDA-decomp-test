int __stdcall RtlAppendStringToString(_STRING *Destination, _STRING *Source)
{
  unsigned __int16 v2; // di
  int v3; // eax

  v2 = Source->Length;
  if ( Source->Length )
  {
    v3 = Destination->Length;
    if ( v2 + v3 > Destination->MaximumLength )
      return -1073741789;
    memmove(&Destination->Buffer[v3], Source->Buffer, v2);
    Destination->Length += v2;
  }
  return 0;
}