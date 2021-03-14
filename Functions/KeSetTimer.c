char __fastcall KeSetTimer(int a1, int a2, _KTIMER *Timer, _LARGE_INTEGER DueTime, _KDPC *Dpc)
{
  return KeSetTimerEx(a1, a2, Timer, DueTime, 0, Dpc);
}