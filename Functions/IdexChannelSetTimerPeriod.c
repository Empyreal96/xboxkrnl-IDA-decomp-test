void __thiscall IdexChannelSetTimerPeriod(void *this, int Period)
{
  KeSetTimerEx((int)this, -10000 * Period >> 31, &Timer, (_LARGE_INTEGER)(-10000 * Period), Period, &stru_80051374);
}