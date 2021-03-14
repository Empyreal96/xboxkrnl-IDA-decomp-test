int __usercall D3DK::nvKelvinACSub@<eax>(D3DK::CDevice *pDevice@<esi>, unsigned int dwD3DStage@<edx>, unsigned int a3@<ebx>, D3DK::CDevice *a4@<edi>)
{
  int hr; // ST1C_4
  unsigned int v5; // edx

  hr = D3DK::nvKelvinACSelectAlphaInput(a4, 0, (unsigned int)pDevice, a3, 6u, 0, 0);
  v5 = (32 << SLOBYTE(kelvinCombinerInputShift[1])) | a4->m_AlphaICW[(_DWORD)pDevice];
  a4->m_AlphaICW[(_DWORD)pDevice] = v5;
  a4->m_AlphaICW[(_DWORD)pDevice] = v5 | (64 << SLOBYTE(kelvinCombinerInputShift[2]));
  return hr | D3DK::nvKelvinACSelectAlphaInput(a4, kelvinCombinerInputD, (unsigned int)pDevice, a3, 7u, 0, 0);
}