unsigned int *__userpurge XMETAL_StartPush@<eax>(int *a1@<edi>, _XMETAL_PushBuffer *pPusher)
{
  unsigned int *v2; // eax
  unsigned int *v3; // esi

  if ( pPusher != (_XMETAL_PushBuffer *)D3DK::g_pDevice )
    D3DK::DXGRIP(a1, "XMETAL_StartPush - invalid pusher pointer.");
  v2 = pPusher->m_pPut;
  if ( pPusher->m_pPut >= pPusher->m_pThreshold )
    v2 = D3DK::CDevice::MakeSpace((D3DK::CDevice *)pPusher, a1);
  v3 = v2;
  D3DK::DbgRecordPushStart(a1, 0x80u);
  return v3;
}