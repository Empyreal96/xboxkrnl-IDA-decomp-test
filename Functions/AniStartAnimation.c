void __userpurge AniStartAnimation(int *a1@<edi>, char fShort)
{
  if ( gBootAnimation_DoAnimation )
  {
    g_bShortVersion = (unsigned __int8)fShort;
    if ( PsCreateSystemThreadEx(
           a1,
           0,
           &g_hThread,
           0,
           0x4000u,
           0,
           0,
           0,
           0,
           0,
           0,
           (void (__stdcall *)(void (__stdcall *)(void *), void *))AnipStartAnimationThread) < 0 )
      g_hThread = 0;
  }
}