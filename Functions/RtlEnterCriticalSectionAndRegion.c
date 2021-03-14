void __stdcall RtlEnterCriticalSectionAndRegion(_DWORD *a1)
{
  _KTHREAD *v1; // ecx
  bool v2; // zf

  v1 = thread;
  --v1->KernelApcDisable;
  v2 = a1[4]++ == -1;
  JUMPOUT(!v2, &Ent20);
  a1[6] = v1;
  a1[5] = 1;
}