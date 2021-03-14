// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::PushedRaw(int *a1@<edi>, unsigned int *pPushNext)
{
  D3DK::g_pPushNext = pPushNext;
  D3DK::g_PushIndex += pPushNext - D3DK::g_pPushNext;
  if ( D3DK::g_PushState != 1 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushState == PUSH_STATE_START");
  if ( D3DK::g_PushIndex > D3DK::g_ReservedSize )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushIndex <= g_ReservedSize");
}