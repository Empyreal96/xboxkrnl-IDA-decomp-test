void __cdecl memcpy(char *dst, char *src, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // edx
  char *v5; // esi
  char *v6; // edi
  unsigned int v7; // ecx

  if ( dst <= src || dst >= &src[count] )
  {
    if ( !((unsigned __int8)dst & 3) )
    {
      v3 = count >> 2;
      v4 = count & 3;
      if ( count >> 2 < 8 )
      {
        switch ( v3 )
        {
          case 0u:
            goto UnwindUp0_0;
          case 1u:
            goto UnwindUp1_0;
          case 2u:
            goto UnwindUp2_0;
          case 3u:
            goto UnwindUp3_0;
          case 4u:
            goto UnwindUp4_0;
          case 5u:
            goto UnwindUp5_0;
          case 6u:
            goto UnwindUp6_0;
          case 7u:
            *(_DWORD *)&dst[4 * v3 - 28] = *(_DWORD *)&src[4 * v3 - 28];
UnwindUp6_0:
            *(_DWORD *)&dst[4 * v3 - 24] = *(_DWORD *)&src[4 * v3 - 24];
UnwindUp5_0:
            *(_DWORD *)&dst[4 * v3 - 20] = *(_DWORD *)&src[4 * v3 - 20];
UnwindUp4_0:
            *(_DWORD *)&dst[4 * v3 - 16] = *(_DWORD *)&src[4 * v3 - 16];
UnwindUp3_0:
            *(_DWORD *)&dst[4 * v3 - 12] = *(_DWORD *)&src[4 * v3 - 12];
UnwindUp2_0:
            *(_DWORD *)&dst[4 * v3 - 8] = *(_DWORD *)&src[4 * v3 - 8];
UnwindUp1_0:
            *(_DWORD *)&dst[4 * v3 - 4] = *(_DWORD *)&src[4 * v3 - 4];
UnwindUp0_0:
            JUMPOUT(__CS__, *(_DWORD *)(4 * v4 - 2147208312));
            return;
          default:
            break;
        }
      }
      qmemcpy(dst, src, 4 * v3);
      JUMPOUT(__CS__, *(_DWORD *)(4 * v4 - 2147208312));
    }
    if ( count >= 4 )
      JUMPOUT(__CS__, *(_DWORD *)(4 * ((unsigned __int8)dst & 3) - 2147208544));
    JUMPOUT(__CS__, *(_DWORD *)(4 * (count - 4) - 2147208296));
  }
  v5 = &src[count - 4];
  v6 = &dst[count - 4];
  if ( !((unsigned __int8)v6 & 3) )
  {
    v7 = count >> 2;
    if ( count >> 2 >= 8 )
    {
      while ( v7 )
      {
        *(_DWORD *)v6 = *(_DWORD *)v5;
        v5 -= 4;
        v6 -= 4;
        --v7;
      }
      JUMPOUT(__CS__, *(_DWORD *)(4 * (count & 3) - 2147207904));
    }
    JUMPOUT(__CS__, *(_DWORD *)(-4 * v7 - 2147207984));
  }
  if ( count < 4 )
  {
    switch ( count )
    {
      case 0u:
        return;
      case 1u:
        v6[3] = v5[3];
        return;
      case 2u:
        v6[3] = v5[3];
        v6[2] = v5[2];
        return;
      case 3u:
        v6[3] = v5[3];
        v6[2] = v5[2];
        v6[1] = v5[1];
        return;
      default:
        break;
    }
  }
  JUMPOUT(__CS__, *(_DWORD *)(4 * ((unsigned __int8)v6 & 3) - 2147208152));
}