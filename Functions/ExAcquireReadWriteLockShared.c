int *__stdcall ExAcquireReadWriteLockShared(_DWORD *a1)
{
  bool v1; // zf
  int *result; // eax

  _disable();
  v1 = (*a1)++ == -1;
  if ( v1 || a1[3] && !a1[1] )
  {
    ++a1[3];
    _enable();
  }
  else
  {
    ++a1[2];
    _enable();
    result = KeWaitForSingleObject((int)(a1 + 8), 0, a1 + 8, 0, 0, 0, 0);
  }
  return result;
}