LONG __fastcall InterlockedIncrement(volatile LONG *Addend)
{
  _EAX = 1;
  __asm { xadd    [ecx], eax }
  return _EAX + 1;
}