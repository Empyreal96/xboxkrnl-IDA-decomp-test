int __userpurge D3DK::nvKelvinCCBlendAlpha@<eax>(D3DK::CDevice *pDevice@<edx>, unsigned int dwHWStage@<esi>, D3DK::CDevice *a3@<ebx>, unsigned int a4@<edi>, unsigned int dwType)
{
  unsigned int v5; // ecx
  int *v6; // eax
  unsigned int dwTemp; // ST24_4
  int *v8; // eax
  unsigned int v9; // ST24_4
  int v10; // ST28_4
  int hr; // [esp+8h] [ebp-4h]

  hr = D3DK::nvKelvinCCSelectColorInput(a3, 0, a4, dwHWStage, 2u, 0, 0, 0);
  if ( dwType == -889274641 )
  {
    a3->m_ColorICW[a4] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
    v5 = 2;
  }
  else
  {
    v6 = &dword_800C21D4[32 * dwHWStage];
    dwTemp = *v6;
    *v6 = dwType;
    hr |= D3DK::nvKelvinCCSelectColorInput(a3, kelvinCombinerInputB, a4, dwHWStage, 3u, 0, 0, 1);
    dword_800C21D4[32 * dwHWStage] = dwTemp;
    v5 = dwType;
  }
  v8 = &dword_800C21D0[32 * dwHWStage];
  v9 = *v8;
  *v8 = v5;
  v10 = D3DK::nvKelvinCCSelectColorInput(a3, kelvinCombinerInputC, a4, dwHWStage, 2u, 1, 0, 1) | hr;
  dword_800C21D0[32 * dwHWStage] = v9;
  return v10 | D3DK::nvKelvinCCSelectColorInput(a3, kelvinCombinerInputD, a4, dwHWStage, 3u, 0, 0, 0);
}