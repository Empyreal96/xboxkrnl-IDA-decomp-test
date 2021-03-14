void __stdcall RtlCopyUnicodeString(_UNICODE_STRING *DestinationString, _UNICODE_STRING *SourceString)
{
  _UNICODE_STRING *v2; // edx
  unsigned __int16 v3; // cx
  unsigned __int16 *v4; // esi
  unsigned int v5; // eax
  unsigned __int16 *v6; // edi
  unsigned __int16 *dst; // [esp+8h] [ebp+8h]

  if ( SourceString )
  {
    v2 = DestinationString;
    v3 = DestinationString->MaximumLength;
    v4 = SourceString->Buffer;
    v5 = SourceString->Length;
    v6 = DestinationString->Buffer;
    dst = DestinationString->Buffer;
    if ( (unsigned __int16)v5 > v3 )
      v5 = v3;
    v2->Length = v5;
    qmemcpy(v6, v4, v5);
    if ( v2->Length < v2->MaximumLength )
      dst[v5 >> 1] = 0;
  }
  else
  {
    DestinationString->Length = 0;
  }
}