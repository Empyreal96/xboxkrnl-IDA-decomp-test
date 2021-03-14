_MMADDRESS_NODE *__stdcall MiCheckForConflictingNode(unsigned int StartVpn, unsigned int EndVpn, _MMADDRESS_NODE *Root)
{
  _MMADDRESS_NODE *result; // eax

  result = Root;
  while ( result )
  {
    if ( StartVpn <= result->EndingVpn )
    {
      if ( EndVpn >= result->StartingVpn )
        return result;
      result = result->LeftChild;
    }
    else
    {
      result = result->RightChild;
    }
  }
  return result;
}