void __stdcall CMcpxAPU::ApuInterruptDpcRoutine(_KDPC *pDpc, void *pvDeferredContext, void *pvSystemContext1, void *pvSystemContext2)
{
  CMcpxAPU::ServiceApuInterruptDpc((CMcpxAPU *)pvDeferredContext);
}