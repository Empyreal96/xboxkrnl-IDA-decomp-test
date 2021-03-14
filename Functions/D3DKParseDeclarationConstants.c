unsigned int __stdcall D3DK::ParseDeclarationConstants(const unsigned int *pDeclaration, unsigned int *pPushStart)
{
  unsigned int v2; // ebx
  unsigned int result; // eax
  const unsigned int *v4; // esi
  int *v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // ecx
  signed int v9; // edx
  char *v10; // edi
  unsigned int oldAddress; // [esp+14h] [ebp-Ch]
  unsigned int count; // [esp+18h] [ebp-8h]
  unsigned int size; // [esp+1Ch] [ebp-4h]
  const unsigned int *pDeclarationa; // [esp+28h] [ebp+8h]

  v2 = *pDeclaration;
  result = 0;
  v4 = pDeclaration + 1;
  v5 = (int *)pPushStart;
  oldAddress = -559038737;
  size = 0;
  pDeclarationa = pDeclaration + 1;
  if ( v2 != -1 )
  {
    do
    {
      v6 = v2 & 0xE0000000;
      if ( (v2 & 0xE0000000) != -1610612736 && BYTE1(v2) )
      {
        D3DK::DXGRIP(v5, "Invalid declaration token (missing D3DVSD_END?)");
        v6 = v2 & 0xE0000000;
      }
      if ( v6 == 0x80000000 )
      {
        v7 = (v2 >> 25) & 0xF;
        v2 = (unsigned __int8)v2;
        count = v7;
        if ( (unsigned __int8)v2 >= 0xC0u || v2 + v7 > 0xC0 )
        {
          D3DK::DXGRIP(v5, "Invalid constant address range (not between -96 and 95) (missing D3DVSD_END?)");
          v7 = count;
        }
        v8 = D3DK::g_pDevice->m_StateFlags;
        if ( !(v8 & 0x200) && v2 <= 0xFFFFFFDB && v2 + v7 > 0xFFFFFFDA )
        {
          D3DK::DXGRIP(
            v5,
            "Address range can't include reserved addresses -38 or -37 (D3DVS_XBOX_RESERVEDCONSTANT1 \n"
            "and D3DVS_XBOX_RESERVEDCONSTANT2)  (missing D3DVSD_END?)");
          v7 = count;
        }
        if ( v2 != oldAddress + 1 )
        {
          if ( v5 )
          {
            *v5 = 269988;
            v5[1] = v2;
            v5 += 2;
          }
          size += 2;
        }
        oldAddress = v2;
        do
        {
          v9 = v7;
          if ( v7 >= 8 )
            v9 = 8;
          if ( v5 )
          {
            *v5 = (v9 << 20) + 2944;
            v10 = (char *)(v5 + 1);
            qmemcpy(v10, v4, 4 * ((unsigned int)(16 * v9) >> 2));
            v4 = pDeclarationa;
            v5 = (int *)&v10[16 * v9];
            v7 = count;
          }
          v4 += 4 * v9;
          v7 -= v9;
          pDeclarationa = v4;
          size += 4 * v9 + 1;
          count = v7;
        }
        while ( v7 );
      }
      v2 = *v4;
      ++v4;
      pDeclarationa = v4;
    }
    while ( v2 != -1 );
    result = size;
  }
  if ( v5 )
  {
    if ( v5 != (int *)&pPushStart[result] )
    {
      D3DK::DXGRIP(v5, "Assertion failure: %s", "(pPush == NULL) || (pPush == pPushStart + size)");
      result = size;
    }
  }
  return result;
}