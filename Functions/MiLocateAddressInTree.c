_MMADDRESS_NODE *__fastcall MiLocateAddressInTree(unsigned int Vpn, _MMADDRESS_NODE **Root)
{
  _MMADDRESS_NODE **v2; // edi
  _MMADDRESS_NODE *v3; // esi
  unsigned int v4; // ebx
  unsigned int Level; // [esp+Ch] [ebp-4h]

  Level = 0;
  v2 = Root;
  v3 = *Root;
  v4 = Vpn;
  while ( 1 )
  {
    if ( !v3 )
      return 0;
    if ( Level == 20 )
      MiReorderTree(v3, v2);
    if ( v4 < v3->StartingVpn )
    {
      v3 = v3->LeftChild;
      goto LABEL_8;
    }
    if ( v4 <= v3->EndingVpn )
      return v3;
    v3 = v3->RightChild;
LABEL_8:
    ++Level;
  }
}