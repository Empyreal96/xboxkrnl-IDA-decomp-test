void __stdcall CMcpxAPU::DeferredCommandDpcRoutine(_KDPC *pdpc, void *pvDeferredContext, void *pvSystemContext1, void *pvSystemContext2)
{
  CMcpxAPU::ServiceDeferredCommandsHigh((CMcpxAPU *)pvDeferredContext);
}