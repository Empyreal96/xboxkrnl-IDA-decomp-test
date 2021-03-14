__int64 __stdcall ExInterlockedExchangeAddLargeInteger(_QWORD *a1, __int64 a2, int a3)
{
  __int64 result; // rax

  _EBP = a1;
  result = *a1;
  do
    __asm { cmpxchg8b qword ptr [ebp+0] }
  while ( (unsigned __int64)(a2 + result) >> 32 );
  return result;
}