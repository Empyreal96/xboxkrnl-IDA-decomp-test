// write access to const memory has been detected, the output may be wrong!
void __thiscall D3DK::DebugSnapshot::WriteColor24(D3DK::DebugSnapshot *this, unsigned int val)
{
  unsigned int v2; // eax
  signed int v3; // edx
  unsigned int v4; // esi
  unsigned __int16 v5; // dx
  unsigned int i; // [esp+Ch] [ebp-4h]

  LOBYTE(v2) = HIBYTE(val);
  v3 = dwByteCnt;
  v4 = dwData;
  i = 0;
  do
  {
    if ( i )
    {
      if ( i == 1 )
      {
        v2 = val >> 8;
      }
      else if ( i == 2 )
      {
        v2 = val >> 16;
      }
    }
    else
    {
      LOBYTE(v2) = val;
    }
    switch ( v3 )
    {
      case 0:
        v4 |= (unsigned __int8)v2;
        v3 = 1;
        break;
      case 1:
        LOBYTE(v5) = 0;
        HIBYTE(v5) = v2;
        v4 |= v5;
        v3 = 2;
        break;
      case 2:
        v4 |= (unsigned __int8)v2 << 16;
        v3 = 3;
        break;
      case 3:
        if ( this->dwCaptureCount < 0x2000 )
        {
          *D3DK::g_pDevice->m_pShaderCapturePtr = v4 | ((unsigned __int8)v2 << 24);
          ++D3DK::g_pDevice->m_pShaderCapturePtr;
          ++this->dwCaptureCount;
        }
        v4 = 0;
        v3 = 0;
        break;
      default:
        break;
    }
    ++i;
  }
  while ( i < 3 );
  dwData = v4;
  dwByteCnt = v3;
}