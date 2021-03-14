void __userpurge __noreturn AnipStartAnimationThread(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void (__stdcall *StartRoutine)(void *), void *StartContext)
{
  AnipRunAnimation(a1, a2, a3, a4);
  PsTerminateSystemThread((unsigned int)a3, a4, 0);
  __debugbreak();
  JUMPOUT(*(_DWORD *)_ftol2);
}