// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::DbgRecordPushStart(int *a1@<edi>, unsigned int Size)
{
  if ( D3DK::g_PushState == 1 )
  {
    D3DK::DXGRIP(
      a1,
      "Pusher - Nested calls to the push-buffer allocator, potentially caused by calling drawing methods from multiple th"
      "reads or from within a DPC.");
  }
  else if ( D3DK::g_PushState == 3 )
  {
    D3DK::DXGRIP(
      a1,
      "Pusher - The push buffer allocator was called while a thread was blocked on a resource, potentially caused by call"
      "ing a drawing from another thread or a DPC.");
  }
  D3DK::g_PushState = 1;
  D3DK::g_PushIndex = 0;
  D3DK::g_pPushNext = D3DK::g_pDevice->m_Pusher.m_pPut;
  D3DK::g_ReservedSize = Size;
}