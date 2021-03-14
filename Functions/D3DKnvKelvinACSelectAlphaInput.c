int __stdcall D3DK::nvKelvinACSelectAlphaInput(D3DK::CDevice *pDevice, D3DK::_kelvinCombinerInput eInput, unsigned int dwCombinerStage, unsigned int dwD3DStage, unsigned int dwD3DTSSArg, int bComplement, int bExpandNormal)
{
  int *v7; // edi
  int v8; // esi
  int v10; // esi
  int v11; // eax

  v7 = (int *)(4 * (dwD3DTSSArg + 32 * dwD3DStage) - 2146688568);
  v8 = 0;
  switch ( *v7 & 0xF )
  {
    case 0:
      goto $L36645;
    case 1:
      if ( dwCombinerStage )
        v8 = 12;
      else
$L36645:
        v8 = 4;
      goto LABEL_12;
    case 2:
      if ( !pDevice->m_Textures[dwD3DStage] )
        return 1;
      v8 = ((_BYTE)dwD3DStage - 8) & 0xF;
LABEL_12:
      v10 = v8 | 0x10;
      if ( bExpandNormal )
        v11 = (*v7 & 0x10) != (bComplement != 0 ? 0x10 : 0) ? 96 : 64;
      else
        v11 = (*v7 & 0x10) != (bComplement != 0 ? 0x10 : 0) ? 0x20 : 0;
      pDevice->m_AlphaICW[dwCombinerStage] |= (v11 | v10) << *(_DWORD *)(4 * eInput - 2146700516);
      return 0;
    case 3:
      v8 = 1;
      goto LABEL_12;
    case 4:
      v8 = 5;
      pDevice->m_StateFlags |= 0x40u;
      goto LABEL_12;
    case 5:
      v8 = 13;
      goto LABEL_12;
    default:
      D3DK::DXGRIP(v7, "unknown / illegal alpha argument '%d' in nvKelvinACSelectAlphaInput", *v7 & 0xF);
      goto LABEL_12;
  }
}