void __stdcall DaysAndFractionToTime(unsigned int ElapsedDays, unsigned int Milliseconds, _LARGE_INTEGER *Time)
{
  *Time = RtlExtendedIntegerMultiply((LARGE_INTEGER)(Milliseconds + 86400000i64 * (signed int)ElapsedDays), 10000);
}