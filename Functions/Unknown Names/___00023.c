__int64 __fastcall ___00023(int a1, int *a2, __int64 *a3)
{
  return ExInterlockedCompareExchange64(a1, a2, a3);
}