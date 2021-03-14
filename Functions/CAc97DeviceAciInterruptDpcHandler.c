void __stdcall CAc97Device::AciInterruptDpcHandler(_KDPC *pdpc, void *pvDeferredContext, void *pvSystemArgument1, void *pvSystemArgument2)
{
  CAc97Device::ServiceAciInterruptDpc((CAc97Device *)pvDeferredContext);
}