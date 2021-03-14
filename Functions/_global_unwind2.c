void __cdecl _global_unwind2(void *TargetFrame)
{
  RtlUnwind(TargetFrame, &gu_return, 0, 0);
}