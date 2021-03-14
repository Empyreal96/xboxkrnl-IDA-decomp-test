void __stdcall D3DK::nvConstructKelvinOutputAlphaCombiners(D3DK::CDevice *pDevice, int bEnable, unsigned int dwHWStage, unsigned int dwD3DStage, int bBias, unsigned int dwShift, int bOutTemp)
{
  if ( bEnable && D3D__TextureState[dwD3DStage][0] != 22 )
  {
    if ( dwShift )
    {
      if ( dwShift == 1 )
      {
        pDevice->m_AlphaOCW[dwHWStage] |= bBias != 0 ? 98304 : 0x10000;
      }
      else if ( dwShift == 2 )
      {
        pDevice->m_AlphaOCW[dwHWStage] |= bBias != 0 ? 98304 : 0x20000;
      }
      else
      {
        D3DK::DXGRIP((int *)pDevice, "illegal shift in nvConstructKelvinOutputAlphaCombiners");
      }
    }
    else
    {
      pDevice->m_AlphaOCW[dwHWStage] |= bBias != 0 ? 0x8000 : 0;
    }
    pDevice->m_AlphaOCW[dwHWStage] |= (bOutTemp != 0 ? 3328 : 3072) | 0xC00;
  }
}