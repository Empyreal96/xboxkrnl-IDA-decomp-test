int __stdcall KeRaiseIrqlToSynchLevel()
{
  int result; // eax

  result = (unsigned __int8)dword_8004C5D0;
  LOBYTE(dword_8004C5D0) = 28;
  if ( (unsigned __int8)result > 0x1Cu )
    KeBugCheck(9u);
  return result;
}