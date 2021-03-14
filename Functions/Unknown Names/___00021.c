LONG __fastcall ___00021(volatile LONG *Destination, LONG ExChange, LONG Comperand)
{
  return InterlockedCompareExchange(Destination, ExChange, Comperand);
}