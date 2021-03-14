_MMADDRESS_NODE *__fastcall MiFindEmptyAddressRange(int a1, int a2, unsigned int SizeOfRange, unsigned int Alignment, unsigned int QuickCheck)
{
  _MMADDRESS_NODE *v5; // ecx
  unsigned int v6; // esi
  _MMADDRESS_NODE *v7; // eax
  _MMADDRESS_NODE *result; // eax

  v5 = MmVadFreeHint;
  if ( QuickCheck || !MmVadFreeHint )
    return (_MMADDRESS_NODE *)MiFindEmptyAddressRangeInTree(
                                (int)v5,
                                a2,
                                SizeOfRange,
                                Alignment,
                                MmVadRoot,
                                &MmVadFreeHint);
  v6 = (MmVadFreeHint->EndingVpn << 12) | 0xFFF;
  v7 = MiGetNextNode(MmVadFreeHint);
  if ( !v7 )
  {
    result = (_MMADDRESS_NODE *)(~(Alignment - 1) & (v6 + Alignment - 1));
    v5 = (_MMADDRESS_NODE *)(2147418112 - (_DWORD)result);
    if ( SizeOfRange < 2147418112 - (signed int)result )
      return result;
    return (_MMADDRESS_NODE *)MiFindEmptyAddressRangeInTree(
                                (int)v5,
                                a2,
                                SizeOfRange,
                                Alignment,
                                MmVadRoot,
                                &MmVadFreeHint);
  }
  v5 = (_MMADDRESS_NODE *)(v7->StartingVpn << 12);
  result = (_MMADDRESS_NODE *)(~(Alignment - 1) & (v6 + Alignment - 1));
  a2 = (char *)v5 - (char *)result;
  if ( SizeOfRange >= (char *)v5 - (char *)result || v5 <= result )
    return (_MMADDRESS_NODE *)MiFindEmptyAddressRangeInTree(
                                (int)v5,
                                a2,
                                SizeOfRange,
                                Alignment,
                                MmVadRoot,
                                &MmVadFreeHint);
  return result;
}