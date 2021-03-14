int __userpurge D3DK::nvKelvinCCModulateColor@<eax>(D3DK::CDevice *pDevice@<esi>, int bComplement@<edi>, int a3@<eax>, unsigned int dwD3DStage)
{
  int v4; // ebx
  int v5; // ebx
  int v6; // eax

  v4 = D3DK::nvKelvinCCSelectColorInput(
         (D3DK::CDevice *)bComplement,
         0,
         (unsigned int)pDevice,
         dwD3DStage,
         2u,
         a3,
         0,
         0);
  v5 = D3DK::nvKelvinCCSelectColorInput(
         (D3DK::CDevice *)bComplement,
         kelvinCombinerInputB,
         (unsigned int)pDevice,
         dwD3DStage,
         3u,
         0,
         0,
         0) | v4;
  v6 = D3DK::nvKelvinCCSelectColorInput(
         (D3DK::CDevice *)bComplement,
         kelvinCombinerInputC,
         (unsigned int)pDevice,
         dwD3DStage,
         2u,
         0,
         0,
         1);
  *(_DWORD *)(bComplement + 4 * (_DWORD)pDevice + 1364) |= 32 << SLOBYTE(kelvinCombinerInputShift[3]);
  return v6 | v5;
}