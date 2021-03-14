int __usercall D3DK::nvKelvinACLerp@<eax>(D3DK::CDevice *pDevice@<edx>, int hdStage@<esi>, D3DK::CDevice *a3@<ebx>, unsigned int a4@<edi>)
{
  int hr; // ST1C_4
  int v5; // ST1C_4
  int v6; // ST1C_4

  hr = D3DK::nvKelvinACSelectAlphaInput(a3, 0, a4, hdStage, 5u, 0, 0);
  v5 = D3DK::nvKelvinACSelectAlphaInput(a3, kelvinCombinerInputB, a4, hdStage, 6u, 0, 0) | hr;
  v6 = D3DK::nvKelvinACSelectAlphaInput(a3, kelvinCombinerInputC, a4, hdStage, 5u, 1, 0) | v5;
  return v6 | D3DK::nvKelvinACSelectAlphaInput(a3, kelvinCombinerInputD, a4, hdStage, 7u, 0, 0);
}