int __usercall D3DK::nvKelvinACAddSmooth@<eax>(D3DK::CDevice *pDevice@<esi>, unsigned int dwD3DStage@<edx>, unsigned int a3@<ebx>, D3DK::CDevice *a4@<edi>)
{
  int hr; // ST1C_4
  int v5; // ST1C_4

  hr = D3DK::nvKelvinACSelectAlphaInput(a4, 0, (unsigned int)pDevice, a3, 6u, 0, 0);
  a4->m_AlphaICW[(_DWORD)pDevice] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
  v5 = D3DK::nvKelvinACSelectAlphaInput(a4, kelvinCombinerInputC, (unsigned int)pDevice, a3, 6u, 1, 0) | hr;
  return v5 | D3DK::nvKelvinACSelectAlphaInput(a4, kelvinCombinerInputD, (unsigned int)pDevice, a3, 7u, 0, 0);
}