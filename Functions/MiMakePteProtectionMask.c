char __fastcall MiMakePteProtectionMask(unsigned int Protect, unsigned int *PteProtectionMask)
{
  int v3; // edx
  int v4; // esi
  unsigned int *v5; // [esp+0h] [ebp-8h]

  v5 = PteProtectionMask;
  if ( Protect & 0xFFFFF800 || Protect & 1 && Protect & 0x700 )
    return 0;
  if ( Protect & 0x200 && Protect & 0x400 )
    return 0;
  v3 = Protect & 0xF;
  if ( !(Protect & 0xF) )
  {
    if ( (unsigned __int8)Protect >> 4 )
      goto LABEL_9;
    return 0;
  }
  if ( (unsigned __int8)Protect >> 4 )
    return 0;
LABEL_9:
  v4 = MmProtectToPteProtectionMask[v3 | ((unsigned __int8)Protect >> 4)];
  if ( v4 == -1 )
    return 0;
  if ( Protect & 0x101 )
  {
    if ( Protect & 0x100 )
      v4 |= 0x200u;
  }
  else
  {
    v4 |= 1u;
  }
  if ( Protect & 0x200 )
  {
    v4 |= 0x10u;
  }
  else if ( Protect & 0x400 )
  {
    v4 |= 8u;
  }
  if ( v4 & 0xFFFFFDE4 )
    RtlAssert(
      v3,
      Protect,
      (int *)0x200,
      v4,
      "(Mask & ~(MM_PTE_PROTECTION_MASK)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x1F2u,
      0);
  *v5 = v4;
  return 1;
}