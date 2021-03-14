unsigned int __stdcall KeQueryInterruptTime()
{
  unsigned int result; // eax

  while ( 1 )
  {
    result = KeInterruptTime.LowPart;
    if ( KeInterruptTime.High1Time == KeInterruptTime.High2Time )
      break;
    _mm_pause();
  }
  return result;
}