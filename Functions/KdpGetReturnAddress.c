_CONTEXT *__stdcall KdpGetReturnAddress(_CONTEXT *ContextRecord)
{
  KdpMoveMemory(&ContextRecord, (void *)ContextRecord->Esp, 4u, 1);
  return ContextRecord;
}