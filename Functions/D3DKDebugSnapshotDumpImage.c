void __usercall D3DK::DebugSnapshot::DumpImage(D3DK::DebugSnapshot *this@<ecx>, int *a2@<edi>)
{
  D3DK::DebugSnapshot *v2; // esi
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // ebx
  unsigned int v6; // eax
  int v7; // edi
  _D3DLOCKED_RECT lr; // [esp+Ch] [ebp-8h]

  v2 = this;
  if ( this->dwCaptureCount < 0x2000 )
  {
    a2 = (int *)D3DK::g_pDevice->m_pShaderCapturePtr;
    *a2 = 100666370;
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    v3 = this->dwCaptureCount + 1;
    this->dwCaptureCount = v3;
    if ( v3 < 0x2000 )
    {
      *D3DK::g_pDevice->m_pShaderCapturePtr = 4194368;
      ++D3DK::g_pDevice->m_pShaderCapturePtr;
      ++this->dwCaptureCount;
    }
  }
  D3DSurface_LockRect(a2, this->pBackBuffer, &lr, 0, 0x40u);
  v4 = v2->dwY;
  v5 = v4 + 32;
  if ( (signed int)(v4 + 32) > (signed int)(v4 - 32) )
  {
    do
    {
      v6 = v2->dwX;
      v7 = v6 - 32;
      if ( (signed int)(v6 - 32) < (signed int)(v6 + 32) )
      {
        do
        {
          if ( v5 < 0 || v5 >= 480 || v7 < 0 || v7 >= 640 )
            D3DK::DebugSnapshot::WriteColor24(v2, 0);
          else
            D3DK::DebugSnapshot::WriteColor24(
              v2,
              *((_DWORD *)lr.pBits + v7 * v2->dwXScale + (v5 * lr.Pitch * v2->dwYScale >> 2)));
          ++v7;
        }
        while ( v7 < (signed int)(v2->dwX + 32) );
      }
      --v5;
    }
    while ( v5 > (signed int)(v2->dwY - 32) );
  }
}