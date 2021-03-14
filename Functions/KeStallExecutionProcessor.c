void __stdcall KeStallExecutionProcessor(ULONG MicroSeconds)
{
  ULONG v6; // eax

  _EAX = 0;
  __asm { cpuid }
  if ( MicroSeconds )
  {
    v6 = MicroSeconds * HalpStallScaleFactor;
    if ( !is_mul_ok(MicroSeconds, HalpStallScaleFactor) )
      __debugbreak();
    if ( !v6 )
      __debugbreak();
    do
      --v6;
    while ( v6 );
  }
}