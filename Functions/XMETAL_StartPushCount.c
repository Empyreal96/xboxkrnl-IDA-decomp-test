unsigned int *__userpurge XMETAL_StartPushCount@<eax>(int *a1@<edi>, _XMETAL_PushBuffer *pPusher, unsigned int count)
{
  int *v3; // edi
  unsigned int *v4; // ebx
  unsigned int *result; // eax
  unsigned int *v6; // ebx

  if ( pPusher != (_XMETAL_PushBuffer *)D3DK::g_pDevice )
    D3DK::DXGRIP(a1, "XMETAL_StartPushCount - invalid pusher pointer.");
  if ( (_DWORD)pPusher[1].m_pThreshold & 4 && 4 * count + 4 >= pPusher[126].m_pThreshold[4] )
    D3DK::DXGRIP(
      a1,
      "XMETAL_StartPush - an individual push buffer request exceeds the total BeginPushBuffer buffer size.  \n"
      "We need %li bytes, so we're about to overwrite the end of the buffer...",
      4 * count + 4);
  v3 = (int *)(4 * count);
  if ( &pPusher->m_pPut[count] >= pPusher->m_pThreshold + 128 )
  {
    v6 = D3DK::CDevice::MakeSpace((D3DK::CDevice *)pPusher, v3);
    if ( (unsigned int *)((char *)v3 + (unsigned int)pPusher->m_pPut) >= pPusher->m_pThreshold + 128 )
      D3DK::DXGRIP(
        v3,
        "Assertion failure: %s",
        "pDevice->m_Pusher.m_pPut + count < pDevice->m_Pusher.m_pThreshold + PUSHER_THRESHOLD_SIZE");
    D3DK::DbgRecordPushStart(v3, count);
    result = v6;
  }
  else
  {
    v4 = pPusher->m_pPut;
    D3DK::DbgRecordPushStart(v3, count);
    result = v4;
  }
  return result;
}