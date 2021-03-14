// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::Push3(int *a1@<edi>, unsigned int *pPush, D3DK::SubChannel subch, unsigned int method, float a, float b, float c)
{
  if ( pPush != D3DK::g_pPushNext )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "pPush == g_pPushNext");
  if ( D3DK::g_PushState != 1 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushState == PUSH_STATE_START");
  *pPush = method + ((subch + 96) << 13);
  *((float *)pPush + 2) = b;
  *((float *)pPush + 3) = c;
  *((float *)pPush + 1) = a;
  D3DK::g_PushIndex += 4;
  D3DK::g_pPushNext += 4;
  if ( D3DK::g_PushIndex + 4 > D3DK::g_ReservedSize )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushIndex <= g_ReservedSize");
}