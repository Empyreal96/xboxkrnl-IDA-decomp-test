int *__userpurge NtWaitForSingleObject@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *Handle, char Alertable, _LARGE_INTEGER *Timeout)
{
  return NtWaitForSingleObjectEx(a1, a2, a3, a4, Handle, 0, Alertable, Timeout);
}