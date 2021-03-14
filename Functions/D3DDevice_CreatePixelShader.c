// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_CreatePixelShader@<eax>(int *a1@<edi>, _D3DPixelShaderDef *pPSDef, unsigned int *pHandle)
{
  int v3; // edx
  int v4; // ecx
  int *v5; // eax

  ++D3DK::g_PerfCounters.m_APICounters[28];
  if ( !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[0], "PSAlphaInputs[0]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[1], "PSAlphaInputs[1]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[2], "PSAlphaInputs[2]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[3], "PSAlphaInputs[3]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[4], "PSAlphaInputs[4]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[5], "PSAlphaInputs[5]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[6], "PSAlphaInputs[6]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSAlphaInputs[7], "PSAlphaInputs[7]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[0], "PSRGBInputs[0]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[1], "PSRGBInputs[1]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[2], "PSRGBInputs[2]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[3], "PSRGBInputs[3]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[4], "PSRGBInputs[4]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[5], "PSRGBInputs[5]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[6], "PSRGBInputs[6]")
    || !D3DK::ValidCombinerInputs(a1, pPSDef->PSRGBInputs[7], "PSRGBInputs[7]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[0], "PSAlphaOutputs[0]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[1], "PSAlphaOutputs[1]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[2], "PSAlphaOutputs[2]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[3], "PSAlphaOutputs[3]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[4], "PSAlphaOutputs[4]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[5], "PSAlphaOutputs[5]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[6], "PSAlphaOutputs[6]")
    || !D3DK::ValidAlphaOutputs(a1, pPSDef->PSAlphaOutputs[7], "PSAlphaOutputs[7]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[0], "PSRGBOutputs[0]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[1], "PSRGBOutputs[1]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[2], "PSRGBOutputs[2]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[3], "PSRGBOutputs[3]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[4], "PSRGBOutputs[4]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[5], "PSRGBOutputs[5]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[6], "PSRGBOutputs[6]")
    || !D3DK::ValidRGBOutputs(a1, pPSDef->PSRGBOutputs[7], "PSRGBOutputs[7]")
    || !D3DK::ValidFinalCombinerABCD(a1, pPSDef->PSFinalCombinerInputsABCD, "PSFinalCombinerInputsABCD")
    || !D3DK::ValidFinalCombinerEFG(a1, pPSDef->PSFinalCombinerInputsEFG, "PSFinalCombinerInputsEFG")
    || !D3DK::ValidTextureModes(a1, pPSDef->PSTextureModes, "PSTextureModes")
    || !D3DK::ValidInputTexture(a1, pPSDef->PSInputTexture, "PSInputTexture")
    || !D3DK::ValidCombinerCount(a1, pPSDef->PSCombinerCount, "PSCombinerCount")
    || !D3DK::ValidDotMapping(a1, pPSDef->PSDotMapping, "PSDotMapping")
    || !D3DK::ValidCompareMode(a1, pPSDef->PSCompareMode, "PSCompareMode")
    || !D3DK::ValidFinalCombinerConstants(a1, pPSDef->PSFinalCombinerConstants, "PSFinalCombinerConstants") )
  {
    D3DK::DXGRIP(a1, "D3DDevice_CreatePixelShader - Invalid pixel shader definition.");
  }
  v5 = D3DK::MemAlloc(v3, v4, (int)pPSDef, 0x100u);
  if ( !v5 )
    return -2147024882;
  v5[1] = 1;
  v5[2] = 1;
  v5[3] = (int)(v5 + 4);
  *v5 = 1349740644;
  qmemcpy(v5 + 4, pPSDef, 0xF0u);
  *pHandle = (unsigned int)v5;
  return 0;
}