void D3DK::FlushWCCache()
{
  _DWORD *v0; // eax

  v0 = D3DK::g_pDevice->m_Miniport.m_RegisterBase;
  _mm_sfence();
  v0[262404] |= 0x10000u;
  while ( v0[262404] & 0x10000 )
    ;
}