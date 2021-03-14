LONG __fastcall ___00015(volatile LONG *Target, LONG Value)
{
  return InterlockedExchange(Target, Value);
}