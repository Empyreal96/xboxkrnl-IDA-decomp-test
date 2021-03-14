void __stdcall KiFlushNPXState()
{
  unsigned int v0; // et0
  _KTHREAD *v1; // edx
  unsigned __int32 v2; // eax
  int v3; // eoff
  unsigned int v4; // [esp-4h] [ebp-4h]

  v0 = __getcallerseflags();
  v4 = v0;
  _disable();
  v1 = thread;
  if ( !thread->NpxState )
  {
    v2 = __readcr0();
    if ( v2 & 0xE )
    {
      v2 &= 0xFFFFFFF1;
      __writecr0(v2);
    }
    v3 = dword_8004C5B0;
    _fxsave((void *)dword_8004C5B0);
    v1->NpxState = 10;
    BugCheckParameter2 = 0;
    __writecr0(*(_DWORD *)(v3 + 512) | v2 | 0xA);
  }
  __writeeflags(v4);
}