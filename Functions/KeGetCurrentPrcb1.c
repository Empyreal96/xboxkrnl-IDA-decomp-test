_KPRCB *__stdcall KeGetCurrentPrcb()
{
  return &KeGetPcr()->PrcbData;
}