int __stdcall PsSetCreateThreadNotifyRoutine(void (__stdcall *NotifyRoutine)(_ETHREAD *, void *, char))
{
  int result; // eax
  int v2; // ecx

  result = -1073741670;
  v2 = 0;
  while ( *(_DWORD *)(4 * v2 - 2147151200) )
  {
    if ( (unsigned int)++v2 >= 8 )
      return result;
  }
  ++PspCreateThreadNotifyRoutineCount;
  *(_DWORD *)(4 * v2 - 2147151200) = NotifyRoutine;
  return 0;
}