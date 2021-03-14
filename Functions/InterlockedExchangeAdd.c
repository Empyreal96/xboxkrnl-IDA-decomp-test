LONG __fastcall InterlockedExchangeAdd(volatile LONG *Addend, LONG Increment)
{
  __asm { xadd    [ecx], edx }
  return _EDX;
}