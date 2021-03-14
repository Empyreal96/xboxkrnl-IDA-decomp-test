void __stdcall CMcpxCore::SetPrivLockState(int fLocked)
{
  BOOL v1; // edx
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-Ch]
  unsigned int dwPrivLock; // [esp+Ch] [ebp-4h]

  CAutoIrql::CAutoIrql(&__AutoIrql);
  v1 = fLocked != 0;
  dwPrivLock = v1 | MEMORY[0xFE801510] & 0xFFFFFFFE;
  MEMORY[0xFE801510] = v1 | MEMORY[0xFE801510] & 0xFFFFFFFE;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}