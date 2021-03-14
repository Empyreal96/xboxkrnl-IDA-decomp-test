_IRP *__fastcall IopAllocateIrpMustSucceed(int a1, int a2, char StackSize)
{
  _IRP *result; // eax
  int v4; // edx
  int v5; // ecx
  _LARGE_INTEGER interval; // [esp+0h] [ebp-8h]

  while ( 1 )
  {
    result = IoAllocateIrp(a1, a2, StackSize);
    if ( result )
      break;
    interval.QuadPart = -50000000i64;
    KeDelayExecutionThread(v5, v4, 0, 0, &interval);
  }
  return result;
}