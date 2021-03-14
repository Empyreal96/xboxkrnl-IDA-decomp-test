void __stdcall RtlMapGenericMask(unsigned int *AccessMask, _GENERIC_MAPPING *GenericMapping)
{
  if ( (*AccessMask & 0x80000000) != 0 )
    *AccessMask |= GenericMapping->GenericRead;
  if ( *AccessMask & 0x40000000 )
    *AccessMask |= GenericMapping->GenericWrite;
  if ( *AccessMask & 0x20000000 )
    *AccessMask |= GenericMapping->GenericExecute;
  if ( *AccessMask & 0x10000000 )
    *AccessMask |= GenericMapping->GenericAll;
  *((_BYTE *)AccessMask + 3) &= 0xFu;
}