__int64 __fastcall ExInterlockedCompareExchange64(int a1, int *a2, __int64 *a3)
{
  int v4; // ebx
  int v5; // ecx
  __int64 result; // rax

  _EBP = a1;
  v4 = *a2;
  v5 = a2[1];
  result = *a3;
  __asm { cmpxchg8b qword ptr [ebp+0] }
  return result;
}