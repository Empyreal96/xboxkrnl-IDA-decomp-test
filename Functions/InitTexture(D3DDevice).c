// write access to const memory has been detected, the output may be wrong!
int __userpurge InitTexture@<eax>(int *a1@<edi>, D3DDevice *pDev)
{
  unsigned int v2; // esi
  char *v4; // ebx
  char *v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // edi
  unsigned int v11; // eax
  _D3DLOCKED_RECT lock; // [esp+4h] [ebp-18h]
  D3DTexture *pTex; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int x; // [esp+14h] [ebp-8h]
  unsigned int dwAddr; // [esp+18h] [ebp-4h]

  v2 = 0;
  x = 0;
  if ( D3DDevice_CreateTexture(a1, 0, 0x64u, 0x11u, 1u, 0, D3DFMT_LIN_X8R8G8B8, 0, &pTex) < 0 )
    return 0;
  g_pTexMicrosoftLogo = pTex;
  D3DTexture_LockRect(pTex, 0, &lock, 0, 0);
  v4 = (char *)lock.pBits;
  dwAddr = (unsigned int)lock.pBits;
  if ( g_ImageLogoSize > 0 )
  {
    while ( 1 )
    {
      v5 = &g_ImageLogo[v2];
      v6 = *(_DWORD *)&g_ImageLogo[v2];
      if ( v6 & 1 )
        break;
      v9 = *(_DWORD *)v5;
      if ( *(_DWORD *)v5 & 2 )
      {
        v7 = (v9 >> 2) & 0x3FF;
        v8 = (unsigned __int16)v9 >> 12;
        v2 += 2;
LABEL_8:
        v10 = v8;
        if ( v7 )
        {
          v14 = v7;
          do
          {
            if ( v10 )
            {
              v11 = ColorFromIntensity(v10);
              *(_DWORD *)dwAddr = v11;
            }
            else
            {
              *(_DWORD *)dwAddr = -16777216;
            }
            if ( x < 0x63 )
            {
              ++x;
              dwAddr += 4;
            }
            else
            {
              x = 0;
              v4 += lock.Pitch;
              dwAddr = (unsigned int)v4;
            }
            --v14;
          }
          while ( v14 );
        }
      }
      if ( v2 >= g_ImageLogoSize )
        return 1;
    }
    v7 = (v6 >> 1) & 7;
    v8 = (unsigned __int8)v6 >> 4;
    ++v2;
    goto LABEL_8;
  }
  return 1;
}