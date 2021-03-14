LONG __fastcall InterlockedExchange(volatile LONG *Target, LONG Value)
{
  char v2; // zf
  LONG result; // eax

  result = *Target;
  do
    __asm { cmpxchg [ecx], edx }
  while ( !v2 );
  return result;
}