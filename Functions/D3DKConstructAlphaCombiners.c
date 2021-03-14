void __stdcall D3DK::ConstructAlphaCombiners(D3DK::CDevice *pDevice, unsigned int dwHWStage, unsigned int dwD3DStage, int bStageActive)
{
  unsigned int v4; // ebx
  D3DK::CDevice *v5; // esi
  unsigned int v6; // edi
  int v7; // eax
  signed int bBias; // [esp+Ch] [ebp-Ch]
  signed int dwShift; // [esp+14h] [ebp-4h]
  unsigned int pDevicea; // [esp+20h] [ebp+8h]

  v4 = dwD3DStage;
  v5 = pDevice;
  v6 = dwHWStage;
  dwShift = 0;
  bBias = 0;
  pDevice->m_AlphaICW[dwHWStage] = 0;
  pDevice->m_AlphaOCW[dwHWStage] = 0;
  if ( bStageActive )
  {
    switch ( dword_800C21D8[32 * dwD3DStage] )
    {
      case 2:
        v7 = D3DK::nvKelvinACSelectAlphaInput(pDevice, 0, dwHWStage, dwD3DStage, 6u, 0, 0);
        pDevice->m_AlphaICW[dwHWStage] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
        goto LABEL_15;
      case 3:
        v7 = D3DK::nvKelvinACSelect2(0, dwHWStage, dwHWStage, pDevice, dwD3DStage);
        goto LABEL_15;
      case 4:
        goto $L36373;
      case 5:
        goto $L36372;
      case 6:
        dwShift = 1;
$L36372:
        ++dwShift;
$L36373:
        pDevicea = D3DK::nvKelvinACSelectAlphaInput(pDevice, 0, dwHWStage, dwD3DStage, 6u, 0, 0);
        v7 = pDevicea | D3DK::nvKelvinACSelectAlphaInput(v5, kelvinCombinerInputB, dwHWStage, dwD3DStage, 7u, 0, 0);
        goto LABEL_15;
      case 7:
        goto $L36376;
      case 8:
        goto $L36375;
      case 9:
        dwShift = 1;
$L36375:
        bBias = 1;
$L36376:
        v7 = D3DK::nvKelvinACAdd((D3DK::CDevice *)dwHWStage, 1u, dwD3DStage, pDevice);
        break;
      case 10:
        v7 = D3DK::nvKelvinACSub((D3DK::CDevice *)dwHWStage, 1u, dwD3DStage, pDevice);
        break;
      case 11:
        v7 = D3DK::nvKelvinACAddSmooth((D3DK::CDevice *)dwHWStage, 1u, dwD3DStage, pDevice);
        break;
      case 12:
        v7 = D3DK::nvKelvinACBlendAlpha((D3DK::CDevice *)1, dwD3DStage, pDevice, dwHWStage, 0);
        break;
      case 13:
        v7 = D3DK::nvKelvinACBlendAlpha((D3DK::CDevice *)1, dwD3DStage, pDevice, dwHWStage, 2u);
        break;
      case 14:
        v7 = D3DK::nvKelvinACBlendAlpha((D3DK::CDevice *)1, dwD3DStage, pDevice, dwHWStage, 3u);
        break;
      case 15:
        v7 = D3DK::nvKelvinACBlendAlpha((D3DK::CDevice *)1, dwD3DStage, pDevice, dwHWStage, 0xCAFEBEEF);
        break;
      case 16:
        v7 = D3DK::nvKelvinACBlendAlpha((D3DK::CDevice *)1, dwD3DStage, pDevice, dwHWStage, 1u);
        break;
      case 17:
        v7 = D3DK::nvKelvinACPremodulate(dwHWStage, 1u, dwHWStage, dwD3DStage, pDevice);
        goto LABEL_14;
      case 23:
        v7 = D3DK::nvKelvinACMultiplyAdd((D3DK::CDevice *)dwHWStage, 1, dwD3DStage, pDevice);
        break;
      case 24:
        v7 = D3DK::nvKelvinACLerp((D3DK::CDevice *)1, dwD3DStage, pDevice, dwHWStage);
        break;
      default:
        goto LABEL_2;
    }
    v6 = dwHWStage;
    v4 = dwD3DStage;
LABEL_14:
    v5 = pDevice;
LABEL_15:
    if ( v7 == 1 )
    {
      if ( v6 )
        v5->m_AlphaICW[v6] = 469762048;
      else
        v5->m_AlphaICW[0] = 335544320;
      v5->m_AlphaICW[v6] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
    }
  }
  else
  {
LABEL_2:
    if ( dwHWStage )
    {
      D3DK::nvConstructKelvinOutputAlphaCombiners(
        pDevice,
        0,
        dwHWStage,
        dwD3DStage,
        0,
        0,
        dword_800C21E8[32 * dwD3DStage] == 5);
      return;
    }
    pDevice->m_AlphaICW[0] = 335544320;
    pDevice->m_AlphaICW[0] = (32 << SLOBYTE(kelvinCombinerInputShift[1])) | 0x14000000;
  }
  D3DK::nvConstructKelvinOutputAlphaCombiners(v5, 1, v6, v4, bBias, dwShift, dword_800C21E8[32 * v4] == 5);
}