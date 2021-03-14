signed int __userpurge RtlTryEnterCriticalSection@<eax>(char a1@<zf>, _DWORD *a2)
{
  signed int result; // eax

  _ECX = a2;
  _EDX = 0;
  __asm { cmpxchg [ecx+10h], edx }
  if ( a1 )
  {
    a2[6] = thread;
    a2[5] = 1;
    result = 1;
  }
  else if ( (_KTHREAD *)a2[6] == thread )
  {
    ++a2[4];
    ++a2[5];
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}