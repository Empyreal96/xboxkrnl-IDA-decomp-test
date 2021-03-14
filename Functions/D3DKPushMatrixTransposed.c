// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::PushMatrixTransposed(int *a1@<edi>, unsigned int *pPush, unsigned int method, _D3DMATRIX *pMatrix)
{
  if ( pPush != D3DK::g_pPushNext )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "pPush == g_pPushNext");
  if ( D3DK::g_PushState != 1 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushState == PUSH_STATE_START");
  D3DK::DumpMatrixTransposed(pPush, method + 0x400000, pMatrix);
  D3DK::g_PushIndex += 17;
  D3DK::g_pPushNext += 17;
  if ( D3DK::g_PushIndex + 17 > D3DK::g_ReservedSize )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "g_PushIndex <= g_ReservedSize");
}