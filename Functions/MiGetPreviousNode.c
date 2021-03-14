_MMADDRESS_NODE *__fastcall MiGetPreviousNode(_MMADDRESS_NODE *Node)
{
  _MMADDRESS_NODE *result; // eax

  result = Node->LeftChild;
  if ( result )
  {
    while ( result->RightChild )
      result = result->RightChild;
  }
  else
  {
    while ( 1 )
    {
      result = Node->Parent;
      if ( !result )
        break;
      if ( result->RightChild == Node )
        return Node->Parent;
      Node = Node->Parent;
    }
  }
  return result;
}