char __stdcall KeGetCurrentIrql()
{
  return KeGetPcr()->Irql;
}