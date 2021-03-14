unsigned int __usercall D3DK::GetSurfaceFormat@<eax>(int *a1@<edi>)
{
  return D3DK::PixelJar::GetSurfaceFormat(
           a1,
           (D3DPixelContainer *)&D3DK::g_pDevice->m_pRenderTarget->Common,
           (D3DPixelContainer *)&D3DK::g_pDevice->m_pZBuffer->Common);
}