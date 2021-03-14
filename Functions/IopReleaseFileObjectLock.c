int __fastcall IopReleaseFileObjectLock(int a1, int a2)
{
  bool v2; // sf
  unsigned __int8 v3; // of
  int result; // eax

  v3 = __OFSUB__(*(_DWORD *)(a1 + 36), 1);
  v2 = (*(_DWORD *)(a1 + 36))-- - 1 < 0;
  if ( !(v2 ^ v3) )
    result = KeSetEvent(a1 + 40, a2, (_KEVENT *)(a1 + 40), 0, 0);
  return result;
}