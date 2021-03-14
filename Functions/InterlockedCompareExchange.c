LONG __fastcall InterlockedCompareExchange(volatile LONG *Destination, LONG ExChange, LONG Comperand)
{
  LONG result; // eax

  result = Comperand;
  __asm { cmpxchg [ecx], edx }
  return result;
}