void __stdcall ExReleaseReadWriteLock(int a1)
{
  bool v1; // sf
  unsigned __int8 v2; // of
  int v3; // eax
  int v4; // edx
  bool v5; // zf

  _disable();
  v2 = __OFSUB__(*(_DWORD *)a1, 1);
  v1 = (*(_DWORD *)a1)-- - 1 < 0;
  if ( v1 ^ v2 )
  {
    *(_DWORD *)(a1 + 12) = 0;
ReleaseExit:
    _enable();
    return;
  }
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)(a1 + 12) )
  {
    v5 = (*(_DWORD *)(a1 + 12))-- == 1;
    if ( !v5 )
      goto ReleaseExit;
    goto ReleaseWriter;
  }
  if ( !v3 )
  {
ReleaseWriter:
    --*(_DWORD *)(a1 + 4);
    _enable();
    KeSetEvent(a1 + 16, v4, (_KEVENT *)(a1 + 16), 1, 0);
    return;
  }
  *(_DWORD *)(a1 + 12) = v3;
  *(_DWORD *)(a1 + 8) = 0;
  _enable();
  KeReleaseSemaphore(a1 + 32, 0, (_KSEMAPHORE *)(a1 + 32), 1, v3, 0);
}