void __userpurge __noreturn PspSystemThreadStartup(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void (__stdcall *StartRoutine)(void *), void *StartContext)
{
  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ps\\create.c",
      0x47u,
      0);
  ((void (__fastcall *)(int, int, void *))StartRoutine)(a2, a1, StartContext);
  PsTerminateSystemThread((unsigned int)a3, a4, 0);
  __debugbreak();
  JUMPOUT(*(_DWORD *)PsCreateSystemThreadEx);
}