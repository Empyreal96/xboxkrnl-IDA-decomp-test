char __fastcall MiMakeSystemPteProtectionMask(unsigned int Protect, _MMPTE *ProtoPte)
{
  unsigned int v2; // ecx
  int v3; // eax
  signed int v5; // [esp-4h] [ebp-4h]

  if ( Protect & 0xFFFFF9F9 )
    return 0;
  if ( (Protect & 6) == 2 )
  {
    v5 = 97;
  }
  else
  {
    if ( (Protect & 6) != 4 )
      return 0;
    v5 = 99;
  }
  v2 = Protect & 0x600;
  v3 = v5;
  if ( v2 )
  {
    if ( v2 == 512 )
    {
      v3 = v5 | 0x10;
    }
    else
    {
      if ( v2 != 1024 )
        return 0;
      v3 = v5 | 8;
    }
  }
  ProtoPte->Long = v3;
  return 1;
}