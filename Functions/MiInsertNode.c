void __fastcall MiInsertNode(_MMADDRESS_NODE *Node, _MMADDRESS_NODE **Root)
{
  _MMADDRESS_NODE *v2; // edi
  _MMADDRESS_NODE **v3; // ebx
  _MMADDRESS_NODE *v4; // esi
  _MMADDRESS_NODE *v5; // eax
  unsigned int Level; // [esp+Ch] [ebp-4h]

  v2 = Node;
  v3 = Root;
  Node->LeftChild = 0;
  Node->RightChild = 0;
  v4 = *Root;
  Level = 0;
  if ( !*Root )
  {
    *Root = Node;
    Node->Parent = 0;
    return;
  }
  while ( 1 )
  {
    if ( ++Level == 15 )
      MiReorderTree(v4, v3);
    if ( v2->StartingVpn < v4->StartingVpn )
      break;
    v5 = v4->RightChild;
    if ( !v5 )
    {
      v4->RightChild = v2;
      goto LABEL_10;
    }
LABEL_7:
    v4 = v5;
  }
  v5 = v4->LeftChild;
  if ( v5 )
    goto LABEL_7;
  v4->LeftChild = v2;
LABEL_10:
  v2->Parent = v4;
}