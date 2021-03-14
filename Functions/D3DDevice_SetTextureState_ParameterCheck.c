// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_SetTextureState_ParameterCheck@<eax>(int *a1@<edi>, unsigned int Stage, _D3DTEXTURESTAGESTATETYPE Type, unsigned int Value)
{
  int result; // eax
  D3DBaseTexture *v5; // eax

  ++D3DK::g_PerfCounters.m_APICounters[168];
  if ( Stage >= 4 || (signed int)Type >= 32 )
  {
    D3DK::DXGRIP(a1, "Invalid texture stage or state index");
    result = -2005530516;
  }
  else
  {
    switch ( Type )
    {
      case 0:
      case 4:
        if ( *(float *)&Value != 0.0 && Value < 0x1B )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Invalid value for D3DTSS_COLOROP/ALPHAOP");
        result = -2005530516;
        break;
      case 1:
      case 2:
      case 3:
      case 5:
      case 6:
      case 7:
      case 8:
        if ( (Value & 0xF) < 6 )
        {
          if ( (Value & 0xFFFFFFF0) < 0x30 )
            goto LABEL_44;
          D3DK::DXGRIP(a1, "Invalid modifier for D3DTSS_COLORARGx/D3DTSS_ALPHAARGx.");
          result = -2005530516;
        }
        else
        {
          D3DK::DXGRIP(a1, "Invalid value selector for D3DTSS_COLORARGx/D3DTSS_ALPHAARGx.");
          result = -2005530516;
        }
        break;
      case 9:
        if ( (unsigned __int8)Value < 5u )
        {
          if ( !(Value & 0xFFFFFE00) )
            goto LABEL_44;
          D3DK::DXGRIP(a1, "Invalid flags for D3DTSS_TEXTURETRANSFORMFLAGS.");
          result = -2005530516;
        }
        else
        {
          D3DK::DXGRIP(a1, "Invalid coordinate count for D3DTSS_TEXTURETRANSFORMFLAGS.");
          result = -2005530516;
        }
        break;
      case 10:
      case 11:
      case 12:
        if ( *(float *)&Value == 0.0 || Value >= 6 )
        {
          D3DK::DXGRIP(a1, "Invalid value for D3DTSS_ADRESSx.");
          result = -2005530516;
        }
        else
        {
          if ( Value != 1 && Value != 2 )
            goto LABEL_44;
          v5 = D3DK::g_pDevice->m_Textures[Stage];
          if ( !v5 || !v5->Size )
            goto LABEL_44;
          D3DK::DXGRIP(a1, "Can't set an address mode of WRAP or MIRROR when a linear texture is set");
          result = -2005530516;
        }
        break;
      case 13:
      case 14:
        if ( Value >= 1 && Value <= 5 )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Invalid D3DTSS_MAGFILTER/D3DTSS_MINFILTER value.");
        result = -2005530516;
        break;
      case 15:
        if ( Value <= 2 )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Invalid D3DTSS_MIPFILTER value.");
        result = -2005530516;
        break;
      case 18:
        if ( Value <= 4 )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Maximum MAXANISOTROPY is 4");
        result = -2005530516;
        break;
      case 19:
        if ( Value < 4 )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Invalid D3DTSS_COLORKEYOP value.");
        result = -2005530516;
        break;
      case 20:
        if ( !(Value & 0xFFFFFFF) )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Invalid D3DTSS_COLORSIGN value.");
        result = -2005530516;
        break;
      case 21:
        if ( Value == 4 || *(float *)&Value == 0.0 )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Invalid D3DTSS_ALPHAKILL value.");
        result = -2005530516;
        break;
      case 22:
      case 23:
      case 24:
      case 25:
        if ( *(float *)&Value >= -8.0 && *(float *)&Value <= 8.0 )
          goto LABEL_44;
        D3DK::DXGRIP(a1, "Must be in the range [-8.0, 8.0]");
        result = -2005530516;
        break;
      case 28:
        if ( (unsigned __int16)Value <= 8u )
        {
          if ( (Value & 0xFFFF0000) <= 0x60000 )
            goto LABEL_44;
          D3DK::DXGRIP(a1, "Invalid texgen");
          result = -2005530516;
        }
        else
        {
          D3DK::DXGRIP(a1, "Texture coordinate index is too big");
          result = -2005530516;
        }
        break;
      default:
LABEL_44:
        result = 0;
        break;
    }
  }
  return result;
}