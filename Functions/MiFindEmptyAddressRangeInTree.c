unsigned int __fastcall MiFindEmptyAddressRangeInTree(int a1, int a2, unsigned int SizeOfRange, unsigned int Alignment, _MMADDRESS_NODE *Root, _MMADDRESS_NODE **PreviousVad)
{
  unsigned int v6; // ebx
  int *v7; // edi
  unsigned int v8; // esi
  _MMADDRESS_NODE *v9; // edx
  _MMADDRESS_NODE *v11; // eax
  _MMADDRESS_NODE *v12; // edx
  _MMADDRESS_NODE *v13; // ecx
  bool v14; // zf
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  _MMADDRESS_NODE *NextNode; // [esp+14h] [ebp+8h]

  v6 = Alignment;
  v7 = (int *)(Alignment >> 12);
  v8 = (SizeOfRange + 4095) >> 12;
  if ( !v8 )
    RtlAssert(a2, a1, v7, 0, "SizeOfRange != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\addrsup.c", 0x46Eu, 0);
  v9 = Root;
  if ( !Root )
    return 0x10000;
  while ( v9->LeftChild )
    v9 = v9->LeftChild;
  if ( v9->StartingVpn > 0x10 && v8 < v9->StartingVpn - 16 )
  {
    *PreviousVad = 0;
    return 0x10000;
  }
  while ( 1 )
  {
    v11 = MiGetNextNode(v9);
    v13 = v11;
    v14 = v11 == 0;
    v15 = v12->EndingVpn;
    NextNode = v13;
    if ( v14 )
      break;
    v16 = v13->StartingVpn;
    v17 = ~((unsigned int)v7 - 1) & ((unsigned int)v7 + v15);
    if ( v8 <= v16 - v17 && v16 > v17 )
    {
      *PreviousVad = v12;
      return ~(Alignment - 1) & (((v12->EndingVpn << 12) | 0xFFF) + Alignment - 1);
    }
    v6 = Alignment;
    v9 = NextNode;
  }
  if ( v15 + 16 >= 0x7FFDF || v8 > 2147352575 - (~(v6 - 1) & ((v15 << 12) + v6 - 1)) )
    ExRaiseStatus(-1073741801);
  *PreviousVad = v12;
  return ~(v6 - 1) & (((v12->EndingVpn << 12) | 0xFFF) + v6 - 1);
}