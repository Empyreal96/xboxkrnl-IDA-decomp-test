void __usercall D3DK::HandleShaderSnapshotOpcode(int *a1@<edi>)
{
  unsigned int v1; // eax
  int v2; // edx
  int v3; // ecx
  int *v4; // eax
  _D3DSURFACE_DESC sDesc; // [esp+4h] [ebp-20h]
  D3DSurface *pBackBuffer; // [esp+20h] [ebp-4h]

  v1 = D3DK::g_pDevice->m_dwOpcode & 0xFF000000;
  switch ( v1 )
  {
    case 0x1000000u:
      D3DDevice_GetBackBuffer(0, 0, &pBackBuffer);
      D3DSurface_GetDesc(a1, pBackBuffer, &sDesc);
      D3DResource_Release(a1, (D3DResource *)&pBackBuffer->Common);
      if ( sDesc.Format == 18 || sDesc.Format == 30 )
      {
        D3DK::g_pDevice->m_dwSnapshot = sDesc.Format;
        v4 = D3DK::MemAlloc(v2, v3, (int)D3DK::g_pDevice, 0x8000u);
        D3DK::g_pDevice->m_pShaderCaptureBuffer = (unsigned int *)v4;
        D3DK::g_pDevice->m_pShaderCapturePtr = (unsigned int *)v4;
        D3DK::DebugSnapshot::BeginSnapshot(
          &D3DK::g_snapshot,
          D3DK::g_pDevice->m_dwOpcode & 0xFFF,
          (D3DK::g_pDevice->m_dwOpcode >> 12) & 0xFFF);
        D3DK::g_pDevice->m_dwOpcode = 0x2000000;
      }
      else
      {
        D3DK::g_pDevice->m_dwOpcode = 67108865;
      }
      break;
    case 0x2000000u:
      D3DK::g_pDevice->m_dwSnapshot = 0;
      D3DK::DebugSnapshot::EndSnapshot(&D3DK::g_snapshot, a1);
      D3DK::g_pDevice->m_dwOpcode = ((char *)D3DK::g_pDevice->m_pShaderCapturePtr
                                   - (char *)D3DK::g_pDevice->m_pShaderCaptureBuffer) | 0x3000000;
      break;
    case 0x5000000u:
      D3DK::MemFree(D3DK::g_pDevice->m_pShaderCaptureBuffer);
      D3DK::g_pDevice->m_pShaderCapturePtr = 0;
      D3DK::g_pDevice->m_pShaderCaptureBuffer = 0;
      D3DK::g_pDevice->m_dwOpcode = 0;
      break;
  }
}