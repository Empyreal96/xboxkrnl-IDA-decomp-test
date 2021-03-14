int __usercall D3DK::nvKelvinCCModulate@<eax>(D3DK::CDevice *pDevice@<edx>, unsigned int dwHWStage@<esi>, D3DK::CDevice *a3@<ebx>, unsigned int a4@<edi>)
{
  int hr; // ST20_4

  hr = D3DK::nvKelvinCCSelectColorInput(a3, 0, a4, dwHWStage, 2u, 0, 0, 0);
  return hr | D3DK::nvKelvinCCSelectColorInput(a3, kelvinCombinerInputB, a4, dwHWStage, 3u, 0, 0, 0);
}