void __stdcall CMcpxCore::SetInterruptState(int fEnabled)
{
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-10h]
  R_INTR rInterruptMask; // [esp+Ch] [ebp-8h]

  CAutoIrql::CAutoIrql(&__AutoIrql);
  rInterruptMask.uValue = (fEnabled != 0) | MEMORY[0xFE801004] & 0xFFFFFFFE;
  MEMORY[0xFE801004] = (fEnabled != 0) | MEMORY[0xFE801004] & 0xFFFFFFFE;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}