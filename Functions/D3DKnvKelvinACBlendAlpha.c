int __userpurge D3DK::nvKelvinACBlendAlpha@<eax>(D3DK::CDevice *pDevice@<edx>, unsigned int dwHWStage@<esi>, D3DK::CDevice *a3@<ebx>, unsigned int a4@<edi>, unsigned int dwType)
{
  unsigned int v5; // ecx
  int *v6; // eax
  unsigned int dwTemp; // ST20_4
  int *v8; // eax
  unsigned int v9; // ST20_4
  int v10; // ST24_4
  int hr; // [esp+8h] [ebp-4h]

  hr = D3DK::nvKelvinACSelectAlphaInput(a3, 0, a4, dwHWStage, 6u, 0, 0);
  if ( dwType == -889274641 )
  {
    a3->m_AlphaICW[a4] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
    v5 = 2;
  }
  else
  {
    v6 = &dword_800C21E4[32 * dwHWStage];
    dwTemp = *v6;
    *v6 = dwType;
    hr |= D3DK::nvKelvinACSelectAlphaInput(a3, kelvinCombinerInputB, a4, dwHWStage, 7u, 0, 0);
    dword_800C21E4[32 * dwHWStage] = dwTemp;
    v5 = dwType;
  }
  v8 = &dword_800C21E0[32 * dwHWStage];
  v9 = *v8;
  *v8 = v5;
  v10 = D3DK::nvKelvinACSelectAlphaInput(a3, kelvinCombinerInputC, a4, dwHWStage, 6u, 1, 0) | hr;
  dword_800C21E0[32 * dwHWStage] = v9;
  return v10 | D3DK::nvKelvinACSelectAlphaInput(a3, kelvinCombinerInputD, a4, dwHWStage, 7u, 0, 0);
}