void *__stdcall RtlpGetStackLimits(void **a1, _DWORD *a2)
{
  void *result; // eax

  *a1 = KeGetPcr()->NtTib.StackLimit;
  result = KeGetPcr()->NtTib.StackBase;
  *a2 = result;
  return result;
}