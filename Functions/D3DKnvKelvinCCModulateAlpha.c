int __userpurge D3DK::nvKelvinCCModulateAlpha@<eax>(D3DK::CDevice *pDevice@<esi>, unsigned int dwD3DStage@<edx>, unsigned int a3@<ebx>, D3DK::CDevice *a4@<edi>, int bComplement)
{
  int hr; // ST20_4
  int v6; // ST20_4

  hr = D3DK::nvKelvinCCSelectColorInput(a4, 0, (unsigned int)pDevice, a3, 2u, 0, 0, 0);
  a4->m_ColorICW[(_DWORD)pDevice] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
  v6 = D3DK::nvKelvinCCSelectColorInput(a4, kelvinCombinerInputC, (unsigned int)pDevice, a3, 2u, bComplement, 0, 1) | hr;
  return v6 | D3DK::nvKelvinCCSelectColorInput(a4, kelvinCombinerInputD, (unsigned int)pDevice, a3, 3u, 0, 0, 0);
}