KIRQL KeRaiseIrqlToDpcLevel(void)
{
  KIRQL result; // al

  result = dword_8004C5D0;
  LOBYTE(dword_8004C5D0) = 2;
  if ( (unsigned __int8)result > 2u )
    KeBugCheck(9u);
  return result;
}