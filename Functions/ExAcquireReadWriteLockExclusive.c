int *__stdcall ExAcquireReadWriteLockExclusive(_DWORD *a1)
{
  bool v1; // zf
  int *result; // eax

  _disable();
  v1 = (*a1)++ == -1;
  if ( v1 )
  {
    _enable();
  }
  else
  {
    ++a1[1];
    _enable();
    result = KeWaitForSingleObject((int)(a1 + 4), 0, a1 + 4, 0, 0, 0, 0);
  }
  return result;
}