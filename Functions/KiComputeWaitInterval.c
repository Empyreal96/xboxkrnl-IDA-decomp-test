_LARGE_INTEGER *__fastcall KiComputeWaitInterval(_LARGE_INTEGER *OriginalTime, _LARGE_INTEGER *DueTime, _LARGE_INTEGER *NewTime)
{
  _LARGE_INTEGER *result; // eax
  bool v4; // zf
  int v5; // ecx
  bool v6; // cf

  result = OriginalTime;
  if ( OriginalTime->HighPart < 0 )
  {
    v5 = KeInterruptTime.High1Time;
    result = NewTime;
    *NewTime = *(_LARGE_INTEGER *)&KeInterruptTime.LowPart;
    if ( v5 != KeInterruptTime.High2Time )
    {
      do
      {
        _mm_pause();
        *NewTime = *(_LARGE_INTEGER *)&KeInterruptTime.LowPart;
      }
      while ( NewTime->HighPart != KeInterruptTime.High2Time );
    }
    v6 = NewTime->LowPart < DueTime->LowPart;
    NewTime->LowPart -= DueTime->LowPart;
    NewTime->HighPart -= v6 + DueTime->HighPart;
  }
  else if ( OriginalTime->HighPart <= 0 )
  {
    v4 = OriginalTime->LowPart == 0;
  }
  return result;
}