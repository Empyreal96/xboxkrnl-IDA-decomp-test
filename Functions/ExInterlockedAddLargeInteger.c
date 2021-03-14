LARGE_INTEGER __stdcall ExInterlockedAddLargeInteger(PLARGE_INTEGER Addend, LARGE_INTEGER Increment, PKSPIN_LOCK Lock)
{
  unsigned int v3; // et0
  __int64 v4; // ST04_8

  v3 = __readeflags();
  _disable();
  v4 = Addend->QuadPart;
  *(_QWORD *)Addend += Increment.QuadPart;
  __writeeflags(v3);
  return (LARGE_INTEGER)v4;
}