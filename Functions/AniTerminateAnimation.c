void *__usercall AniTerminateAnimation@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  void *result; // eax

  result = g_hThread;
  if ( g_hThread )
  {
    NtWaitForSingleObjectEx(a1, a2, a3, a4, g_hThread, 0, 0, 0);
    result = (void *)NtClose(a3, g_hThread);
    g_hThread = 0;
  }
  return result;
}