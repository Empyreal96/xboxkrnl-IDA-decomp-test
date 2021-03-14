signed int __fastcall MiDecodePteProtectionMask(unsigned int PteProtectionMask)
{
  signed int result; // eax

  result = (PteProtectionMask & 2) != 0 ? 4 : 2;
  if ( !(PteProtectionMask & 1) )
  {
    if ( PteProtectionMask & 0x200 )
      result |= 0x100u;
    else
      result = 1;
  }
  if ( PteProtectionMask & 0x10 )
    return result | 0x200;
  if ( PteProtectionMask & 8 )
    result |= 0x400u;
  return result;
}