int __usercall D3DK::nvKelvinCCPremodulate@<eax>(unsigned int dwHWStage@<edi>, unsigned int dwD3DStage@<esi>, unsigned int a3@<eax>)
{
  unsigned int v3; // ebx
  int hr; // ST28_4
  int *v5; // ebx
  unsigned int dwTemp; // ST24_4
  int v7; // eax
  int result; // eax

  v3 = a3;
  if ( a3 )
  {
    result = D3DK::nvKelvinCCSelectColorInput((D3DK::CDevice *)dwD3DStage, 0, a3, dwHWStage, 2u, 0, 0, 0);
    *(_DWORD *)(dwD3DStage + 4 * v3 + 1364) |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
  }
  else
  {
    hr = D3DK::nvKelvinCCSelectColorInput((D3DK::CDevice *)dwD3DStage, 0, 0, dwHWStage, 2u, 0, 0, 0);
    v5 = &dword_800C21D4[32 * dwHWStage];
    dwTemp = dword_800C21D4[32 * dwHWStage];
    *v5 = 2;
    v7 = D3DK::nvKelvinCCSelectColorInput((D3DK::CDevice *)dwD3DStage, kelvinCombinerInputB, 0, dwHWStage, 3u, 0, 0, 0);
    *v5 = dwTemp;
    result = v7 | hr;
  }
  return result;
}