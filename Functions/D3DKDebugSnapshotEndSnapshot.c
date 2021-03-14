void __usercall D3DK::DebugSnapshot::EndSnapshot(D3DK::DebugSnapshot *this@<ecx>, int *a2@<edi>)
{
  D3DK::DebugSnapshot *v2; // esi
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int dwDepth; // [esp+Ch] [ebp-8h]
  unsigned int dwColor; // [esp+10h] [ebp-4h]

  v2 = this;
  D3DK::DebugSnapshot::GetColorAndDepth(this, a2, &dwColor, &dwDepth);
  if ( v2->dwCaptureCount < 0x2000 )
  {
    *D3DK::g_pDevice->m_pShaderCapturePtr = 33554435;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v3 = v2->dwCaptureCount + 1;
    v2->dwCaptureCount = v3;
    if ( v3 < 0x2000 )
    {
      *D3DK::g_pDevice->m_pShaderCapturePtr = dwColor;
      ++D3DK::g_pDevice->m_pShaderCapturePtr;
      v4 = v2->dwCaptureCount + 1;
      v2->dwCaptureCount = v4;
      if ( v4 < 0x2000 )
      {
        *D3DK::g_pDevice->m_pShaderCapturePtr = dwDepth;
        ++D3DK::g_pDevice->m_pShaderCapturePtr;
        ++v2->dwCaptureCount;
      }
    }
  }
  D3DK::DebugSnapshot::DumpImage(v2, (int *)4);
  if ( v2->dwCaptureCount < 0x2000 )
  {
    *D3DK::g_pDevice->m_pShaderCapturePtr = 0;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    ++v2->dwCaptureCount;
  }
  D3DResource_Release((int *)4, (D3DResource *)&v2->pBackBuffer->Common);
  D3DResource_Release((int *)4, (D3DResource *)&v2->pDepthBuffer->Common);
}