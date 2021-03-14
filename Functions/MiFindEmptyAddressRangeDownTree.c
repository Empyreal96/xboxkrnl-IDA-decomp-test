unsigned int __fastcall MiFindEmptyAddressRangeDownTree(int a1, int a2, unsigned int SizeOfRange, void *HighestAddressToEndAt, unsigned int Alignment, _MMADDRESS_NODE *Root)
{
  char *v6; // edi
  int v7; // esi
  _MMADDRESS_NODE *v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v12; // ebx
  unsigned int v13; // ecx
  unsigned int v14; // edi
  unsigned int v15; // ebx
  _MMADDRESS_NODE *v16; // eax
  unsigned int *v17; // edx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // edx
  unsigned int AlignmentVpn; // [esp+Ch] [ebp-8h]
  unsigned int HighestVpn; // [esp+10h] [ebp-4h]
  unsigned int SizeOfRangea; // [esp+1Ch] [ebp+8h]
  unsigned int OptimalStartVpn; // [esp+20h] [ebp+Ch]
  unsigned int Alignmenta; // [esp+24h] [ebp+10h]
  _MMADDRESS_NODE *PreviousNode; // [esp+28h] [ebp+14h]

  v6 = (char *)HighestAddressToEndAt;
  v7 = (SizeOfRange + 4095) & 0xFFFFF000;
  SizeOfRangea = (SizeOfRange + 4095) & 0xFFFFF000;
  if ( !HighestAddressToEndAt )
    RtlAssert(
      a2,
      a1,
      (int *)HighestAddressToEndAt,
      v7,
      "HighestAddressToEndAt != NULL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\addrsup.c",
      0x4ECu,
      (char *)HighestAddressToEndAt);
  if ( (unsigned int)HighestAddressToEndAt > 0x7FFE0000 )
    RtlAssert(
      a2,
      a1,
      (int *)HighestAddressToEndAt,
      v7,
      "HighestAddressToEndAt <= (PVOID)((ULONG_PTR)MM_HIGHEST_VAD_ADDRESS + 1)",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\addrsup.c",
      0x4EDu,
      0);
  v8 = Root;
  HighestVpn = (unsigned int)HighestAddressToEndAt >> 12;
  v9 = Alignment;
  OptimalStartVpn = (unsigned int)HighestAddressToEndAt - v7;
  v10 = (unsigned int)&v6[-v7 + 1] & ~(Alignment - 1);
  if ( !Root )
    return v10;
  while ( v8->RightChild )
    v8 = v8->RightChild;
  v12 = ~(Alignment - 1);
  v13 = v12 & (((v8->EndingVpn << 12) | 0xFFF) + Alignment - 1);
  Alignmenta = ~(Alignment - 1);
  if ( v13 < (unsigned int)v6 && SizeOfRangea < (unsigned int)&v6[-v13] )
    return OptimalStartVpn & v12;
  v14 = v10 >> 12;
  v15 = v9 >> 12;
  AlignmentVpn = v9 >> 12;
  while ( 1 )
  {
    v16 = MiGetPreviousNode(v8);
    PreviousNode = v16;
    if ( !v16 )
      break;
    v18 = v16->EndingVpn;
    if ( v18 < v14 )
    {
      v19 = ~(v15 - 1) & (v18 + v15);
      if ( SizeOfRangea >> 12 <= *v17 - v19 )
      {
        if ( v10 >> 12 > v18 && HighestVpn < *v17 )
          return v10;
        if ( *v17 > v19 )
        {
          v20 = *v17;
          return Alignmenta & ((v20 << 12) - SizeOfRangea);
        }
      }
    }
LABEL_27:
    v8 = PreviousNode;
    v15 = AlignmentVpn;
    v14 = v10 >> 12;
  }
  if ( *v17 <= 0x10 )
    ExRaiseStatus(-1073741801);
  if ( SizeOfRangea >> 12 > *v17 - 16 )
    goto LABEL_27;
  v21 = *v17;
  if ( HighestVpn < v21 )
    return v10;
  v20 = v21;
  return Alignmenta & ((v20 << 12) - SizeOfRangea);
}