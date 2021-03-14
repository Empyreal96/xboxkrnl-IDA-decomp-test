// write access to const memory has been detected, the output may be wrong!
void __userpurge XMETAL_EndPush(int *a1@<edi>, _XMETAL_PushBuffer *pPusher, unsigned int *pPush)
{
  volatile unsigned int v3; // esi
  _XMETAL_PushBuffer *pPushera; // [esp+14h] [ebp+8h]

  if ( pPusher != (_XMETAL_PushBuffer *)D3DK::g_pDevice )
    D3DK::DXGRIP(a1, "XMETAL_EndPush - invalid pusher pointer.");
  if ( D3DK::g_PushState != 1 )
    D3DK::DXGRIP(a1, "Pusher - End push is not paired with a start push, probably due to an earlier error.");
  D3DK::g_PushState = 0;
  D3DK::ASSERTMSG(
    (int *)pPush,
    pPush == &pPusher->m_pPut[D3DK::g_PushIndex],
    "Bad EndPush: Expected %lx, got %lx.  g_PushIndex: %li",
    &pPusher->m_pPut[D3DK::g_PushIndex],
    pPush,
    D3DK::g_PushIndex);
  if ( pPusher->m_pPut >= D3DK::g_pDevice->m_pPushLimit && !(D3DK::g_pDevice->m_StateFlags & 4) )
    D3DK::DXGRIP(
      (int *)pPush,
      "Assertion failure: %s",
      "(pPusher->m_pPut < pDevice->m_pPushLimit) || (pDevice->m_StateFlags & STATE_RECORDPUSHBUFFER )");
  pPusher->m_pPut = pPush;
  if ( D3D__SingleStepPusher )
  {
    D3DK::CDevice::KickOff(D3DK::g_pDevice, (int *)pPush);
    v3 = KeTickCount;
    while ( D3DDevice_IsBusy() )
    {
      pPushera = (_XMETAL_PushBuffer *)400;
      do
        pPushera = (_XMETAL_PushBuffer *)((char *)pPushera - 1);
      while ( pPushera );
      if ( KeTickCount - v3 > D3D__DeadlockTimeOutVal )
        RtlRip(0, 0, "Possible deadlock, blocked for more than 2 seconds.");
      if ( D3DK::g_DpcRIPFired )
      {
        RtlRip(0, 0, "Graphics processor error.");
        D3DK::g_DpcRIPFired = 0;
      }
    }
  }
  D3DK::PARSE_PUSH_BUFFER();
}