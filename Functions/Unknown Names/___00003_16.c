LARGE_INTEGER __stdcall ___00003_16(LARGE_INTEGER Dividend, LARGE_INTEGER MagicDivisor, CCHAR ShiftCount)
{
  return RtlExtendedMagicDivide(Dividend, MagicDivisor, ShiftCount);
}