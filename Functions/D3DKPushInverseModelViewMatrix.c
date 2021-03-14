// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::PushInverseModelViewMatrix(int *a1@<edi>, unsigned int *pPush, unsigned int method, _D3DMATRIX *pMatrix)
{
  if ( pPush != D3DK::g_pPushNext )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "pPush == g_pPushNext");
  if ( D3DK::g_PushState != 1 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushState == PUSH_STATE_START");
  *pPush = method + 3145728;
  qmemcpy(pPush + 1, pMatrix, 0x30u);
  D3DK::g_PushIndex += 13;
  D3DK::g_pPushNext += 13;
  if ( D3DK::g_PushIndex + 13 > D3DK::g_ReservedSize )
    D3DK::DXGRIP((int *)pPush + 13, "Assertion failure: %s", "g_PushIndex <= g_ReservedSize");
}