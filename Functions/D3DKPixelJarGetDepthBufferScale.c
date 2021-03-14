void __userpurge D3DK::PixelJar::GetDepthBufferScale(int *a1@<edi>, D3DPixelContainer *pPixels, float *pScale)
{
  if ( !(D3DK::g_TextureFormat[BYTE1(pPixels->Format)] & 0x40) )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "IsValidDepthBufferD3DFORMAT(GetFormat(pPixels))");
  switch ( BYTE1(pPixels->Format) )
  {
    case 0x2Au:
    case 0x2Eu:
      *pScale = 16777215.0;
      break;
    case 0x2Bu:
    case 0x2Fu:
      *pScale = 1.0e30;
      break;
    case 0x2Cu:
    case 0x30u:
      *pScale = 65535.0;
      break;
    case 0x2Du:
    case 0x31u:
      *pScale = 511.9375;
      break;
    default:
      D3DK::DXGRIP(a1, "PixelJar::GetDepthBufferScale - unknown depth buffer format.");
      break;
  }
}