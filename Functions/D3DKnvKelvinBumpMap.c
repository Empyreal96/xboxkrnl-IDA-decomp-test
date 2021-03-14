int __usercall D3DK::nvKelvinBumpMap@<eax>(D3DK::CDevice *pDevice@<esi>, unsigned int dwHWStage@<edx>, unsigned int dwD3DStage@<edi>, unsigned int a4@<eax>, unsigned int a5@<ebx>)
{
  int result; // eax
  int *v6; // esi
  unsigned int dwArg1Cache; // ST24_4

  if ( *(_DWORD *)(dwD3DStage + 4 * a4 + 2976) )
  {
    v6 = &dword_800C21D0[32 * a4];
    dwArg1Cache = dword_800C21D0[32 * a4];
    *v6 = 1;
    result = D3DK::nvKelvinCCSelectColorInput((D3DK::CDevice *)dwD3DStage, 0, a5, a4, 2u, 0, 0, 0);
    *v6 = dwArg1Cache;
    *(_DWORD *)(dwD3DStage + 4 * a5 + 1364) |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
  }
  else
  {
    D3DK::DXGRIP((int *)dwD3DStage, "Setup failure");
    result = 1;
  }
  return result;
}