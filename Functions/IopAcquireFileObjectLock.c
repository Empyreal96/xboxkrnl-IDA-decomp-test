int *__fastcall IopAcquireFileObjectLock(int a1, int a2)
{
  bool v2; // zf
  int *result; // eax

  v2 = (*(_DWORD *)(a1 + 36))++ == -1;
  if ( !v2 )
    result = KeWaitForSingleObject(a1 + 40, a2, (void *)(a1 + 40), 0, 0, 0, 0);
  return result;
}