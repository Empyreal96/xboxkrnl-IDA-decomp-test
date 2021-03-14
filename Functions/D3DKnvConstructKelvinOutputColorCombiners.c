void __userpurge D3DK::nvConstructKelvinOutputColorCombiners(int *a1@<edi>, D3DK::CDevice *pDevice, int bEnable, unsigned int dwStage, int bBias, unsigned int dwShift, int bDotAB, int bDotCD, int bOutTemp)
{
  unsigned int v9; // eax
  unsigned int v10; // eax

  if ( !bEnable )
  {
    if ( !dwStage )
      D3DK::DXGRIP(a1, "Assertion failure: %s", "dwStage > 0");
    return;
  }
  if ( dwShift )
  {
    if ( dwShift != 1 )
    {
      if ( dwShift == 2 )
        pDevice->m_ColorOCW[dwStage] |= bBias != 0 ? 98304 : 0x20000;
      else
        D3DK::DXGRIP((int *)pDevice, "illagal shift in nvConstructKelvinOutputColorCombiners");
      goto LABEL_12;
    }
    v9 = (bBias != 0 ? 98304 : 0x10000) | pDevice->m_ColorOCW[dwStage];
  }
  else
  {
    v9 = (bBias != 0 ? 0x8000 : 0) | pDevice->m_ColorOCW[dwStage];
  }
  pDevice->m_ColorOCW[dwStage] = v9;
LABEL_12:
  v10 = pDevice->m_ColorOCW[dwStage];
  if ( bDotAB )
  {
    if ( bDotCD )
      pDevice->m_ColorOCW[dwStage] = v10 | (bOutTemp != 0 ? 3328 : 3072) | 0xC3000;
    else
      pDevice->m_ColorOCW[dwStage] = v10 | (bOutTemp != 0 ? 208 : 192) | 0x82000;
  }
  else
  {
    pDevice->m_ColorOCW[dwStage] = v10 | (bOutTemp != 0 ? 3328 : 3072);
  }
}