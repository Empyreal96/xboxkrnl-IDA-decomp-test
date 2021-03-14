int __usercall D3DK::nvKelvinCCLerp@<eax>(D3DK::CDevice *pDevice@<edx>, int hdStage@<esi>, D3DK::CDevice *a3@<ebx>, unsigned int a4@<edi>)
{
  int hr; // ST20_4
  int v5; // ST20_4
  int v6; // ST20_4

  hr = D3DK::nvKelvinCCSelectColorInput(a3, 0, a4, hdStage, 1u, 0, 0, 0);
  v5 = D3DK::nvKelvinCCSelectColorInput(a3, kelvinCombinerInputB, a4, hdStage, 2u, 0, 0, 0) | hr;
  v6 = D3DK::nvKelvinCCSelectColorInput(a3, kelvinCombinerInputC, a4, hdStage, 1u, 1, 0, 0) | v5;
  return v6 | D3DK::nvKelvinCCSelectColorInput(a3, kelvinCombinerInputD, a4, hdStage, 3u, 0, 0, 0);
}