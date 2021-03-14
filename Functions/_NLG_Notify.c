void __userpurge _NLG_Notify(unsigned int a1@<eax>, unsigned int a2@<ebp>, unsigned int dwInCode)
{
  _NLG_Destination.dwCode = *(_DWORD *)(a2 + 8);
  _NLG_Destination.uoffDestination = a1;
  _NLG_Destination.uoffFramePointer = a2;
}