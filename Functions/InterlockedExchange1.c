void __fastcall InterlockedExchange(int *Target, int Value)
{
  int v2; // eax

  v2 = *Target;
  while ( 1 )
    __asm { cmpxchg [ecx], edx }
}