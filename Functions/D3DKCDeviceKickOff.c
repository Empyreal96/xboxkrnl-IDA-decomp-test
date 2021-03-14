// write access to const memory has been detected, the output may be wrong!
void __usercall D3DK::CDevice::KickOff(D3DK::CDevice *this@<ecx>, int *a2@<edi>)
{
  unsigned int *v2; // esi
  _DWORD *v3; // eax
  unsigned int v4; // esi
  D3DK::CDevice *v5; // [esp+4h] [ebp-4h]

  v5 = this;
  if ( D__ )
  {
    v4 = this->m_pControlDma->Get;
    if ( v4 > 0x4000000 )
    {
      DbgPrint(a2, "DebugVerifyPhysical - Not a valid physical memory offset.");
      DbgPrint(a2, "\n");
      __debugbreak();
      this = v5;
    }
    this->m_Pusher.m_pPut = (unsigned int *)(v4 | 0x80000000);
    v5->m_pKickOff = v5->m_Pusher.m_pPut;
    *v5->m_pGpuTime = v5->m_CpuTime - 2;
    v5->m_Miniport.m_VBlankFlipCount = v5->m_PresentCount;
    g_StartPut = v5->m_Pusher.m_pPut;
  }
  else
  {
    if ( this->m_StateFlags & 4 )
      v2 = this->m_pPushBufferRecordSavedPut;
    else
      v2 = this->m_Pusher.m_pPut;
    if ( D3DK::g_PushState == 1 )
    {
      D3DK::DXGRIP(a2, "Assertion failure: %s", "g_PushState != PUSH_STATE_START");
      this = v5;
    }
    if ( this->m_Pusher.m_pPut >= this->m_pPushLimit && !(this->m_StateFlags & 4) )
      D3DK::DXGRIP(
        a2,
        "Assertion failure: %s",
        "(m_Pusher.m_pPut < m_pPushLimit) || (m_StateFlags & STATE_RECORDPUSHBUFFER )");
    v3 = D3DK::g_pDevice->m_Miniport.m_RegisterBase;
    _mm_sfence();
    v3[262404] |= 0x10000u;
    while ( v3[262404] & 0x10000 )
      ;
    v5->m_pControlDma->Put = D3DK::GetGPUAddress(a2, v2);
    v5->m_pKickOff = v2;
  }
}