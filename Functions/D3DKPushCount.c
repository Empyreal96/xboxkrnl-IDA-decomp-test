// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::PushCount(int *a1@<edi>, unsigned int *pPush, D3DK::SubChannel subch, unsigned int method, unsigned int count)
{
  if ( pPush != D3DK::g_pPushNext )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "pPush == g_pPushNext");
  if ( D3DK::g_PushState != 1 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushState == PUSH_STATE_START");
  *pPush = method + ((subch + 32 * count) << 13);
  D3DK::g_pPushNext += count + 1;
  D3DK::g_PushIndex += count + 1;
  if ( D3DK::g_PushIndex + count + 1 > D3DK::g_ReservedSize )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushIndex <= g_ReservedSize");
}