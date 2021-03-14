int __stdcall D3DK::nvKelvinCCSelectColorInput(D3DK::CDevice *pDevice, D3DK::_kelvinCombinerInput eInput, unsigned int dwCombinerStage, unsigned int dwD3DStage, unsigned int dwD3DTSSArg, int bComplement, int bExpandNormal, int bAlphaReplicate)
{
  int *v8; // edi
  int v9; // esi
  int v11; // esi
  int v12; // eax

  v8 = (int *)(4 * (dwD3DTSSArg + 32 * dwD3DStage) - 2146688568);
  v9 = 0;
  switch ( *v8 & 0xF )
  {
    case 0:
      goto $L36767;
    case 1:
      if ( dwCombinerStage )
        v9 = 12;
      else
$L36767:
        v9 = 4;
      goto LABEL_12;
    case 2:
      if ( !pDevice->m_Textures[dwD3DStage] )
        return 1;
      v9 = ((_BYTE)dwD3DStage - 8) & 0xF;
LABEL_12:
      v11 = ((bAlphaReplicate | *v8 & 0x20) != 0 ? 0x10 : 0) | v9;
      if ( bExpandNormal )
        v12 = (*v8 & 0x10) != (bComplement != 0 ? 0x10 : 0) ? 96 : 64;
      else
        v12 = (*v8 & 0x10) != (bComplement != 0 ? 0x10 : 0) ? 0x20 : 0;
      pDevice->m_ColorICW[dwCombinerStage] |= (v12 | v11) << *(_DWORD *)(4 * eInput - 2146700516);
      return 0;
    case 3:
      v9 = 1;
      goto LABEL_12;
    case 4:
      v9 = 5;
      pDevice->m_StateFlags |= 0x40u;
      goto LABEL_12;
    case 5:
      v9 = 13;
      goto LABEL_12;
    default:
      D3DK::DXGRIP(v8, "unknown / illegal color argument '%d' in nvKelvinCCSelectColorInput", *v8 & 0xF);
      goto LABEL_12;
  }
}