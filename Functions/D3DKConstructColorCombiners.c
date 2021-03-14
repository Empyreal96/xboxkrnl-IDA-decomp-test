int __stdcall D3DK::ConstructColorCombiners(D3DK::CDevice *pDevice, unsigned int dwHWStage, unsigned int dwD3DStage)
{
  D3DK::CDevice *v3; // ebx
  D3DK::CDevice *v4; // esi
  unsigned int v5; // edi
  D3DK::CDevice *v6; // edx
  D3DK::CDevice *v7; // ecx
  int v8; // eax
  int bStageActive; // [esp+Ch] [ebp-14h]
  signed int bBias; // [esp+14h] [ebp-Ch]
  signed int bDotProduct; // [esp+18h] [ebp-8h]
  signed int dwShift; // [esp+1Ch] [ebp-4h]
  unsigned int dwD3DStagea; // [esp+30h] [ebp+10h]

  v3 = pDevice;
  v4 = (D3DK::CDevice *)dwD3DStage;
  v5 = dwHWStage;
  bStageActive = 1;
  v6 = (D3DK::CDevice *)(dwD3DStage << 7);
  pDevice->m_ColorICW[dwHWStage] = 0;
  pDevice->m_ColorOCW[dwHWStage] = 0;
  v7 = (D3DK::CDevice *)(D3D__TextureState[dwD3DStage][0] - 2);
  bDotProduct = 0;
  bBias = 0;
  dwShift = 0;
  dwD3DStagea = dwD3DStage << 7;
  switch ( (unsigned int)v7 )
  {
    case 0u:
      v8 = D3DK::nvKelvinCCSelectColorInput(pDevice, 0, dwHWStage, (unsigned int)v4, 2u, 0, 0, 0);
      pDevice->m_ColorICW[dwHWStage] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
      goto LABEL_15;
    case 1u:
      v8 = D3DK::nvKelvinCCSelect2(v7, dwHWStage, dwHWStage, pDevice, (unsigned int)v4);
      goto LABEL_15;
    case 2u:
      goto $L36573;
    case 3u:
      goto $L36572;
    case 4u:
      dwShift = 1;
$L36572:
      ++dwShift;
$L36573:
      v8 = D3DK::nvKelvinCCModulate(v6, (unsigned int)v4, pDevice, dwHWStage);
      goto LABEL_13;
    case 5u:
      goto $L36576;
    case 6u:
      goto $L36897;
    case 7u:
      dwShift = 1;
$L36897:
      bBias = 1;
$L36576:
      v8 = D3DK::nvKelvinCCAdd((D3DK::CDevice *)dwHWStage, (unsigned int)v6, (unsigned int)v4, pDevice);
      goto LABEL_13;
    case 8u:
      v8 = D3DK::nvKelvinCCSub((D3DK::CDevice *)dwHWStage, (unsigned int)v6, (unsigned int)v4, pDevice);
      goto LABEL_13;
    case 9u:
      v8 = D3DK::nvKelvinCCAddSmooth((D3DK::CDevice *)dwHWStage, (unsigned int)v6, (unsigned int)v4, pDevice);
      goto LABEL_13;
    case 0xAu:
      v8 = D3DK::nvKelvinCCBlendAlpha(v6, (unsigned int)v4, pDevice, dwHWStage, 0);
      goto LABEL_13;
    case 0xBu:
      v8 = D3DK::nvKelvinCCBlendAlpha(v6, (unsigned int)v4, pDevice, dwHWStage, 2u);
      goto LABEL_13;
    case 0xCu:
      v8 = D3DK::nvKelvinCCBlendAlpha(v6, (unsigned int)v4, pDevice, dwHWStage, 3u);
      goto LABEL_13;
    case 0xDu:
      v8 = D3DK::nvKelvinCCBlendAlpha(v6, (unsigned int)v4, pDevice, dwHWStage, 0xCAFEBEEF);
      goto LABEL_13;
    case 0xEu:
      v8 = D3DK::nvKelvinCCBlendAlpha(v6, (unsigned int)v4, pDevice, dwHWStage, 1u);
      goto LABEL_13;
    case 0xFu:
      v8 = D3DK::nvKelvinCCPremodulate((unsigned int)v4, (unsigned int)pDevice, dwHWStage);
      goto LABEL_14;
    case 0x10u:
      v8 = D3DK::nvKelvinCCModulateAlpha((D3DK::CDevice *)dwHWStage, (unsigned int)v6, (unsigned int)v4, pDevice, 0);
      goto LABEL_13;
    case 0x11u:
      v8 = D3DK::nvKelvinCCModulateColor((D3DK::CDevice *)dwHWStage, (int)pDevice, 0, (unsigned int)v4);
      goto LABEL_14;
    case 0x12u:
      v8 = D3DK::nvKelvinCCModulateAlpha((D3DK::CDevice *)dwHWStage, (unsigned int)v6, (unsigned int)v4, pDevice, 1);
      goto LABEL_13;
    case 0x13u:
      v8 = D3DK::nvKelvinCCModulateColor((D3DK::CDevice *)dwHWStage, (int)pDevice, 1, (unsigned int)v4);
      goto LABEL_14;
    case 0x14u:
      v8 = D3DK::nvKelvinCCDotProduct(v6, (unsigned int)v4, pDevice, dwHWStage);
      bDotProduct = 1;
      goto LABEL_13;
    case 0x15u:
      v8 = D3DK::nvKelvinCCMultiplyAdd((D3DK::CDevice *)dwHWStage, (int)v6, (unsigned int)v4, pDevice);
      goto LABEL_13;
    case 0x16u:
      v8 = D3DK::nvKelvinCCLerp(v6, (int)v4, pDevice, dwHWStage);
      goto LABEL_13;
    case 0x17u:
    case 0x18u:
      v8 = D3DK::nvKelvinBumpMap(v4, (unsigned int)v6, (unsigned int)pDevice, (unsigned int)v4, dwHWStage);
LABEL_13:
      v3 = pDevice;
LABEL_14:
      v5 = dwHWStage;
LABEL_15:
      if ( v8 == 1 )
      {
        if ( v5 )
          v3->m_ColorICW[v5] = 201326592;
        else
          v3->m_ColorICW[0] = 0x4000000;
        v3->m_ColorICW[v5] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
      }
      v6 = (D3DK::CDevice *)dwD3DStagea;
      goto LABEL_37;
    default:
      if ( dwHWStage )
      {
        bStageActive = 0;
        D3DK::nvConstructKelvinOutputColorCombiners(
          (int *)dwHWStage,
          pDevice,
          0,
          dwHWStage,
          0,
          0,
          0,
          0,
          *(int *)((char *)dword_800C21E8 + (_DWORD)v6) == 5);
      }
      else
      {
        pDevice->m_ColorICW[0] = 0x4000000;
        bStageActive = 0;
        pDevice->m_ColorICW[0] = (32 << SLOBYTE(kelvinCombinerInputShift[1])) | 0x4000000;
LABEL_37:
        D3DK::nvConstructKelvinOutputColorCombiners(
          (int *)v5,
          v3,
          1,
          v5,
          bBias,
          dwShift,
          bDotProduct,
          0,
          *(int *)((char *)dword_800C21E8 + (_DWORD)v6) == 5);
      }
      return bStageActive;
  }
}