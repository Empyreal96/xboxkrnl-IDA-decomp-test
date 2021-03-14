void __stdcall MiReorderTree(_MMADDRESS_NODE *Node, _MMADDRESS_NODE **Root)
{
  _MMADDRESS_NODE *v2; // eax
  _MMADDRESS_NODE *v3; // ecx
  _MMADDRESS_NODE *v4; // edi
  _MMADDRESS_NODE *v5; // esi
  _MMADDRESS_NODE *v6; // edx
  _MMADDRESS_NODE *v7; // eax
  _MMADDRESS_NODE *v8; // eax
  _MMADDRESS_NODE *v9; // eax
  _MMADDRESS_NODE *v10; // eax
  _MMADDRESS_NODE *v11; // esi
  _MMADDRESS_NODE *v12; // esi
  _MMADDRESS_NODE *v13; // esi
  _MMADDRESS_NODE *v14; // esi
  _MMADDRESS_NODE *v15; // esi
  _MMADDRESS_NODE *v16; // esi
  bool v17; // zf
  _MMADDRESS_NODE *v18; // edx
  _MMADDRESS_NODE *v19; // edx

  v2 = Node;
  if ( Node == *Root )
    return;
  while ( 1 )
  {
    v3 = v2->Parent;
    v4 = *Root;
    if ( v3 == *Root )
      break;
    v5 = v3->LeftChild;
    v6 = v3->Parent;
    if ( v2 != v5 || v3 != v6->LeftChild )
    {
      if ( v2 != v3->RightChild || v3 != v6->RightChild )
      {
        if ( v2 != v5 || v3 != v6->RightChild )
        {
          if ( v6 == v4 )
          {
            *Root = v2;
            v2->Parent = 0;
          }
          else
          {
            v2->Parent = v6->Parent;
            v14 = v6->Parent;
            if ( v6 == v14->LeftChild )
              v14->LeftChild = v2;
            else
              v14->RightChild = v2;
          }
          v3->RightChild = v2->LeftChild;
          v15 = v2->LeftChild;
          if ( v15 )
            v15->Parent = v3;
          v6->LeftChild = v2->RightChild;
          v16 = v2->RightChild;
          if ( v16 )
            v16->Parent = v6;
          v3->Parent = v2;
          v6->Parent = v2;
          v2->LeftChild = v3;
          v2->RightChild = v6;
        }
        else
        {
          if ( v6 == v4 )
          {
            *Root = v2;
            v2->Parent = 0;
          }
          else
          {
            v2->Parent = v6->Parent;
            v11 = v6->Parent;
            if ( v6 == v11->LeftChild )
              v11->LeftChild = v2;
            else
              v11->RightChild = v2;
          }
          v3->LeftChild = v2->RightChild;
          v12 = v2->RightChild;
          if ( v12 )
            v12->Parent = v3;
          v6->RightChild = v2->LeftChild;
          v13 = v2->LeftChild;
          if ( v13 )
            v13->Parent = v6;
          v3->Parent = v2;
          v6->Parent = v2;
          v2->LeftChild = v6;
          v2->RightChild = v3;
        }
        goto LABEL_46;
      }
      if ( v6 == v4 )
      {
        *Root = v3;
        v3->Parent = 0;
      }
      else
      {
        v3->Parent = v6->Parent;
        v9 = v6->Parent;
        if ( v6 == v9->LeftChild )
          v9->LeftChild = v3;
        else
          v9->RightChild = v3;
      }
      v6->RightChild = v3->LeftChild;
      v10 = v3->LeftChild;
      if ( v10 )
        v10->Parent = v6;
      v6->Parent = v3;
      v3->LeftChild = v6;
    }
    else
    {
      if ( v6 == v4 )
      {
        *Root = v3;
        v3->Parent = 0;
      }
      else
      {
        v3->Parent = v6->Parent;
        v7 = v6->Parent;
        if ( v6 == v7->LeftChild )
          v7->LeftChild = v3;
        else
          v7->RightChild = v3;
      }
      v6->LeftChild = v3->RightChild;
      v8 = v3->RightChild;
      if ( v8 )
        v8->Parent = v6;
      v6->Parent = v3;
      v3->RightChild = v6;
    }
    v2 = v3;
LABEL_46:
    if ( v2 == *Root )
      return;
  }
  *Root = v2;
  v2->Parent = 0;
  v17 = v2 == v3->LeftChild;
  v3->Parent = v2;
  if ( v17 )
  {
    v3->LeftChild = v2->RightChild;
    v18 = v2->RightChild;
    if ( v18 )
      v18->Parent = v3;
    v2->RightChild = v3;
  }
  else
  {
    v3->RightChild = v2->LeftChild;
    v19 = v2->LeftChild;
    if ( v19 )
      v19->Parent = v3;
    v2->LeftChild = v3;
  }
}