LONG __fastcall InterlockedDecrement(volatile LONG *Addend)
{
  _EAX = -1;
  __asm { xadd    [ecx], eax }
  return _EAX - 1;
}