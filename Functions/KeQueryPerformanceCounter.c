LARGE_INTEGER __stdcall KeQueryPerformanceCounter(PLARGE_INTEGER PerformanceFrequency)
{
  unsigned __int32 v1; // eax

  while ( HalpPerformanceCounterHigh2 != HalpPerformanceCounterHigh1 )
    ;
  v1 = __indword(0x8008u);
  return (LARGE_INTEGER)(((HalpPerformanceCounterLow ^ v1) & 0x80000000)
                       + __PAIR__(HalpPerformanceCounterHigh2, HalpPerformanceCounterLow & 0x80000000 | v1 & 0x7FFFFFFF));
}