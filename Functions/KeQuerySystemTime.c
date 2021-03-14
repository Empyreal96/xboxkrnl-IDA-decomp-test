void __stdcall KeQuerySystemTime(_LARGE_INTEGER *CurrentTime)
{
  int v1; // eax

  while ( 1 )
  {
    v1 = KeSystemTime.High1Time;
    if ( KeSystemTime.High1Time == KeSystemTime.High2Time )
      break;
    _mm_pause();
  }
  CurrentTime->LowPart = KeSystemTime.LowPart;
  CurrentTime->HighPart = v1;
}