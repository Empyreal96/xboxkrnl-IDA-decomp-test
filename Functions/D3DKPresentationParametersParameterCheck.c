int __userpurge D3DK::PresentationParametersParameterCheck@<eax>(int *a1@<edi>, _D3DPRESENT_PARAMETERS_ *pPresentationParams)
{
  unsigned int v2; // ecx
  int result; // eax
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // eax
  _D3DSWAPEFFECT v8; // eax

  v2 = pPresentationParams->MultiSampleType;
  if ( v2 == 17 || !v2 )
    goto LABEL_26;
  if ( (v2 & 0xF0000) > 0x40000 )
  {
    D3DK::DXGRIP(a1, "Invalid D3DMULTISAMPLE_PREFILTER_FORMAT type");
    return -2005530516;
  }
  v4 = (unsigned __int8)v2 >> 4;
  if ( v4 < 1 || (v5 = pPresentationParams->MultiSampleType & 0xF, v5 < 1) || v4 > 3 || v5 > 3 )
  {
    D3DK::DXGRIP(a1, "Improper D3DMULTISAMPLE scale encoding");
    result = -2005530516;
  }
  else
  {
LABEL_26:
    v6 = pPresentationParams->FullScreen_PresentationInterval;
    if ( v6 <= 2 || v6 == 0x80000000 )
    {
      v7 = pPresentationParams->FullScreen_RefreshRateInHz;
      if ( v7 && v7 != 50 && v7 != 60 )
        D3DK::DXGRIP(a1, "FullScreen_RefreshRateInHz must be zero, 50 or 60");
      v8 = pPresentationParams->SwapEffect;
      if ( v8 != 1 && v8 != 2 && v8 )
      {
        D3DK::DXGRIP(a1, "Invalid SwapEffect value");
        result = -2005530516;
      }
      else if ( pPresentationParams->BackBufferCount <= 2 )
      {
        result = 0;
      }
      else
      {
        D3DK::DXGRIP(a1, "No point in more than 2 back buffers, due to throttling");
        result = -2005530516;
      }
    }
    else
    {
      D3DK::DXGRIP(a1, "Invalid FullScreen_PresentationInterval value");
      result = -2005530516;
    }
  }
  return result;
}