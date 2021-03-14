int __usercall D3DK::nvKelvinCCMultiplyAdd@<eax>(D3DK::CDevice *pDevice@<esi>, int dxStage@<edx>, unsigned int a3@<ebx>, D3DK::CDevice *a4@<edi>)
{
  int hr; // ST20_4
  int v5; // ST20_4

  hr = D3DK::nvKelvinCCSelectColorInput(a4, 0, (unsigned int)pDevice, a3, 1u, 0, 0, 0);
  a4->m_ColorICW[(_DWORD)pDevice] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
  v5 = D3DK::nvKelvinCCSelectColorInput(a4, kelvinCombinerInputC, (unsigned int)pDevice, a3, 2u, 0, 0, 0) | hr;
  return v5 | D3DK::nvKelvinCCSelectColorInput(a4, kelvinCombinerInputD, (unsigned int)pDevice, a3, 3u, 0, 0, 0);
}