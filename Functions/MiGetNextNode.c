_MMADDRESS_NODE *__fastcall MiGetNextNode(_MMADDRESS_NODE *Node)
{
  _MMADDRESS_NODE *result; // eax
  _MMADDRESS_NODE *i; // ecx

  result = Node->RightChild;
  if ( result )
  {
    for ( i = result->LeftChild; i; i = i->LeftChild )
      result = i;
  }
  else
  {
    for ( result = Node->Parent; result && result->LeftChild != Node; result = result->Parent )
      Node = result;
  }
  return result;
}