unsigned int __usercall XGRAPHICS::Log2@<eax>(unsigned int Value@<eax>, unsigned int a2@<ecx>)
{
  unsigned int result; // eax

  _BitScanForward(&result, a2);
  return result;
}