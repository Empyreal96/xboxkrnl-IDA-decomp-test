void KiTrap07()
{
  _KTHREAD *v0; // eax
  _DWORD *v1; // ecx
  unsigned __int32 v2; // ebx
  unsigned int v3; // edx
  unsigned __int32 v4; // ebx
  int v5; // ebx
  unsigned __int32 v6; // eax
  _KTHREAD *v7; // eax
  _WORD *v8; // ecx
  unsigned __int32 v9; // ebx
  int v10; // ebx
  int v11; // esi
  int v12; // eax

  while ( 1 )
  {
    v0 = thread;
    v1 = (_DWORD *)dword_8004C5B0;
    _disable();
    if ( dword_8004C604 )
    {
      if ( thread->NpxIrql != 2 )
        break;
    }
    if ( !thread->NpxState )
    {
      v6 = __readcr0();
      JUMPOUT(v6 & 0xE, 0, &Kt07dbg3);
      *(_DWORD *)(dword_8004C5B0 + 512) |= 8u;
      v7 = thread;
      v8 = (_WORD *)dword_8004C5B0;
      v9 = __readcr0();
      v9 &= 0xFFFFFFF1;
      __writecr0(v9);
      _fxsave(v8);
      JUMPOUT(*((_DWORD *)v8 + 128) & 0xFFFFFFF1, 0, &Kt07dbg2);
      __writecr0(*((_DWORD *)v8 + 128) | v9 | 0xA);
      *((_DWORD *)v8 + 128) &= 0xFFFFFFF7;
      v7->NpxState = 10;
      BugCheckParameter2 = 0;
      _enable();
      v10 = *((_DWORD *)v8 + 2);
      v11 = *((_DWORD *)v8 + 4);
      v12 = (unsigned __int16)v8[1] & ~(*v8 & 0x3F);
      if ( v12 & 1 )
      {
        if ( !(v12 & 0x40) )
          JUMPOUT(&CommonDispatchException1Arg0d);
        JUMPOUT(&CommonDispatchException2Args0d);
      }
      if ( v12 & 4 )
        JUMPOUT(&CommonDispatchException1Arg0d);
      if ( v12 & 2 )
        JUMPOUT(&CommonDispatchException1Arg0d);
      if ( v12 & 8 )
        JUMPOUT(&CommonDispatchException1Arg0d);
      if ( v12 & 0x10 )
        JUMPOUT(&CommonDispatchException1Arg0d);
      if ( v12 & 0x20 )
        JUMPOUT(&CommonDispatchException1Arg0d);
      _enable();
      KeBugCheck(0x12u);
    }
    v2 = __readcr0();
    __writecr0(v2 & 0xFFFFFFF1);
    v3 = BugCheckParameter2;
    if ( BugCheckParameter2 )
    {
      _fxsave((void *)(*(_DWORD *)(BugCheckParameter2 + 28) - 528));
      *(_BYTE *)(v3 + 48) = 10;
    }
    _fxrstor(v1);
    v0->NpxState = 0;
    BugCheckParameter2 = (unsigned int)v0;
    _enable();
    JUMPOUT(v1[128], 0, KiExceptionExit);
    _disable();
    JUMPOUT(v1[128] & 0xFFFFFFF1, 0, &Kt07dbg1);
    v4 = __readcr0();
    v5 = v1[128] | v4;
    __writecr0((unsigned int)v5);
    _enable();
    JUMPOUT(v5 & 8, 0, KiExceptionExit);
  }
  KeBugCheck(0xF0u);
}