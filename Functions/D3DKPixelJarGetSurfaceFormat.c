unsigned int __userpurge D3DK::PixelJar::GetSurfaceFormat@<eax>(int *a1@<edi>, D3DPixelContainer *pRenderTarget, D3DPixelContainer *pZBuffer)
{
  signed int v3; // eax
  unsigned int result; // eax

  switch ( BYTE1(pRenderTarget->Format) )
  {
    case 3u:
      v3 = 1;
      goto LABEL_16;
    case 5u:
      v3 = 3;
      goto LABEL_16;
    case 6u:
      v3 = 8;
      goto LABEL_16;
    case 7u:
      v3 = 4;
      goto LABEL_16;
    case 0x11u:
      v3 = 3;
      goto LABEL_4;
    case 0x12u:
      v3 = 8;
      goto LABEL_4;
    case 0x13u:
      v3 = 9;
      goto LABEL_4;
    case 0x17u:
      v3 = 10;
      goto LABEL_4;
    case 0x1Cu:
      v3 = 1;
      goto LABEL_4;
    case 0x1Eu:
      v3 = 4;
      goto LABEL_4;
    default:
      D3DK::DXGRIP(a1, "Unexpected format");
      v3 = (signed int)pRenderTarget;
      if ( HIBYTE(pRenderTarget) )
LABEL_16:
        result = pRenderTarget->Format & 0xF000000 | ((pRenderTarget->Format & 0xF00000 | 0x2000) >> 4) | v3;
      else
LABEL_4:
        result = v3 | 0x100;
      if ( pZBuffer )
      {
        switch ( BYTE1(pZBuffer->Format) )
        {
          case 0x2Au:
          case 0x2Bu:
          case 0x2Eu:
          case 0x2Fu:
            goto $L36297;
          case 0x2Cu:
          case 0x2Du:
          case 0x30u:
          case 0x31u:
            goto $L36299;
          default:
            return result;
        }
      }
      else if ( (D3DK::g_TextureFormat[BYTE1(pRenderTarget->Format)] & 0x3C) == 32 )
      {
$L36297:
        result |= 0x20u;
      }
      else
      {
$L36299:
        result |= 0x10u;
      }
      return result;
  }
}