void __fastcall MiRemoveNode(_MMADDRESS_NODE *Node, _MMADDRESS_NODE **Root)
{
  _MMADDRESS_NODE *v2; // eax
  _MMADDRESS_NODE *v3; // esi
  _MMADDRESS_NODE *v4; // ecx
  _MMADDRESS_NODE *v5; // edx
  _MMADDRESS_NODE *v6; // edx
  bool v7; // zf
  _MMADDRESS_NODE *v8; // ecx
  _MMADDRESS_NODE *v9; // edi
  _MMADDRESS_NODE *v10; // ecx
  _MMADDRESS_NODE *v11; // ecx
  _MMADDRESS_NODE *v12; // eax
  _MMADDRESS_NODE *v13; // eax

  v2 = Node->LeftChild;
  v3 = Node->RightChild;
  if ( Node == *Root )
  {
    if ( v2 )
    {
      if ( !v3 )
      {
        *Root = v2;
        v2->Parent = 0;
        return;
      }
      v4 = v2->RightChild;
      if ( v4 )
      {
        while ( v4->RightChild )
          v4 = v4->RightChild;
        *Root = v4;
        v4->Parent->RightChild = v4->LeftChild;
        v5 = v4->LeftChild;
      }
      else
      {
        v4 = v3->LeftChild;
        if ( !v4 )
        {
          *Root = v2;
          v2->Parent = 0;
LABEL_41:
          v2->RightChild = v3;
          v3->Parent = v2;
          return;
        }
        while ( v4->LeftChild )
          v4 = v4->LeftChild;
        *Root = v4;
        v4->Parent->LeftChild = v4->RightChild;
        v5 = v4->RightChild;
      }
      if ( v5 )
        v5->Parent = v4->Parent;
      v4->Parent = 0;
      v2->Parent = v4;
      v3->Parent = v4;
      v4->LeftChild = v2;
      v4->RightChild = v3;
    }
    else if ( v3 )
    {
      *Root = v3;
      v3->Parent = 0;
      do
        v3 = v3->LeftChild;
      while ( v3 );
    }
    else
    {
      *Root = 0;
    }
  }
  else if ( v2 )
  {
    if ( v3 )
    {
      v6 = v2->RightChild;
      if ( v6 )
      {
        while ( v6->RightChild )
          v6 = v6->RightChild;
        v6->Parent->RightChild = v6->LeftChild;
        v9 = v6->LeftChild;
      }
      else
      {
        v6 = v3->LeftChild;
        if ( !v6 )
        {
          v2->Parent = Node->Parent;
          v7 = Node == Node->Parent->LeftChild;
          v8 = Node->Parent;
          if ( v7 )
            v8->LeftChild = v2;
          else
            v8->RightChild = v2;
          goto LABEL_41;
        }
        while ( v6->LeftChild )
          v6 = v6->LeftChild;
        v6->Parent->LeftChild = v6->RightChild;
        v9 = v6->RightChild;
      }
      if ( v9 )
        v9->Parent = v6->Parent;
      v6->Parent = Node->Parent;
      v7 = Node == Node->Parent->LeftChild;
      v10 = Node->Parent;
      if ( v7 )
        v10->LeftChild = v6;
      else
        v10->RightChild = v6;
      v2->Parent = v6;
      v3->Parent = v6;
      v6->LeftChild = v2;
      v6->RightChild = v3;
    }
    else
    {
      v2->Parent = Node->Parent;
      v7 = Node == Node->Parent->LeftChild;
      v11 = Node->Parent;
      if ( v7 )
        v11->LeftChild = v2;
      else
        v11->RightChild = v2;
    }
  }
  else if ( v3 )
  {
    v3->Parent = Node->Parent;
    v12 = Node->Parent;
    if ( Node == Node->Parent->LeftChild )
      v12->LeftChild = v3;
    else
      v12->RightChild = v3;
  }
  else
  {
    v13 = Node->Parent;
    if ( Node == v13->LeftChild )
      v13->LeftChild = 0;
    else
      v13->RightChild = 0;
  }
}