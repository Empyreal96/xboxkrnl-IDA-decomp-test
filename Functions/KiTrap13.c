void KiTrap13()
{
  unsigned int v0; // eax
  int v1; // ecx
  unsigned __int32 v2; // ebx
  unsigned int v3; // eax

  v0 = BugCheckParameter2;
  if ( (_KTHREAD *)BugCheckParameter2 != thread )
    KeBugCheckEx(0x12u, 0xDu, BugCheckParameter2, 0, 0);
  v1 = dword_8004C5B0;
  v2 = __readcr0();
  v2 &= 0xFFFFFFF1;
  __writecr0(v2);
  _fxsave((void *)v1);
  JUMPOUT(*(_DWORD *)(v1 + 512) & 0xFFFFFFF1, 0, &Kt13_dbg2);
  __writecr0(*(_DWORD *)(v1 + 512) | v2 | 0xA);
  *(_DWORD *)(v1 + 512) &= 0xFFFFFFF7;
  *(_BYTE *)(v0 + 48) = 10;
  BugCheckParameter2 = 0;
  _enable();
  v3 = ~((unsigned int)*(unsigned __int16 *)(v1 + 24) >> 7) & *(_WORD *)(v1 + 24) & 0x3F;
  if ( v3 & 1 )
    JUMPOUT(&CommonDispatchException1Arg0d);
  if ( v3 & 4 )
    JUMPOUT(&CommonDispatchException1Arg0d);
  if ( v3 & 2 )
    JUMPOUT(&CommonDispatchException1Arg0d);
  if ( v3 & 8 )
    JUMPOUT(&CommonDispatchException1Arg0d);
  if ( v3 & 0x10 )
    JUMPOUT(&CommonDispatchException1Arg0d);
  if ( v3 & 0x20 )
    JUMPOUT(&CommonDispatchException1Arg0d);
  _enable();
  KeBugCheckEx(0x12u, 0xDu, v3, 0, 1u);
}