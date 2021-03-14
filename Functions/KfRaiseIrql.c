KIRQL __fastcall KfRaiseIrql(KIRQL NewIrql)
{
  KIRQL result; // al

  result = dword_8004C5D0;
  LOBYTE(dword_8004C5D0) = NewIrql;
  if ( (unsigned __int8)result > (unsigned __int8)NewIrql )
  {
    LOBYTE(dword_8004C5D0) = 0;
    KeBugCheck(9u);
  }
  return result;
}