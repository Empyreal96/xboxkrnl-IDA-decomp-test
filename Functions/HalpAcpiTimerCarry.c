unsigned __int64 __stdcall HalpAcpiTimerCarry()
{
  unsigned __int32 v0; // eax
  unsigned __int32 v1; // ecx
  unsigned __int64 result; // rax
  signed __int64 v3; // kr00_8

  v0 = __indword(0x8008u);
  v1 = ((HalpPerformanceCounterLow + 2147483648) ^ v0) & 0x80000000;
  result = v1 + __PAIR__(HalpPerformanceCounterHigh2, HalpPerformanceCounterLow) + 0x80000000i64;
  HalpPerformanceCounterHigh1 = HIDWORD(result);
  v3 = v1 + __PAIR__(HalpPerformanceCounterHigh2, HalpPerformanceCounterLow) + 0x80000000i64;
  HalpPerformanceCounterHigh2 = result >> 32;
  HalpPerformanceCounterLow = v3;
  return result;
}