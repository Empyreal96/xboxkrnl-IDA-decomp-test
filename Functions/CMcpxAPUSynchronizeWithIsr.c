char __stdcall CMcpxAPU::SynchronizeWithIsr(void *pvContext)
{
  int v1; // eax

  InterlockedExchange((int *)pvContext + 378, 0);
  *((_DWORD *)pvContext + 380) |= v1;
  return 1;
}