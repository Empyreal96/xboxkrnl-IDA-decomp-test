void __usercall D3DK::PRIMITIVE_LAUNCH_STATE_TEST2(int *a1@<edi>)
{
  D3DK::CDevice *v1; // edx
  signed int v2; // esi
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int *v6; // edi
  signed int v7; // esi
  int v8; // ebx
  D3DK::CDevice *v9; // edx
  signed int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int *v14; // edi
  signed int v15; // esi
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int *v20; // edi
  signed int v21; // esi
  int v22; // ebx
  unsigned int v23; // eax
  D3DK::CDevice *v24; // ebx
  signed int v25; // esi
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int *v31; // edi
  int *v32; // esi
  int v33; // eax
  int v34; // eax
  int v35; // edx
  int v36; // eax
  int v37; // eax
  unsigned int v38; // ecx
  unsigned int *v39; // esi
  int *v40; // edi
  unsigned int v41; // ecx
  int v42; // ecx
  unsigned int v43; // esi
  int *v44; // edi
  int v45; // edx
  D3DK::CDevice *v46; // ebx
  unsigned int v47; // ecx
  int v48; // eax
  unsigned int v49; // ecx
  unsigned int v50; // esi
  int v51; // eax
  unsigned int v52; // eax
  unsigned int v53; // eax
  D3DK::CDevice *pDevice; // [esp+0h] [ebp-4h]

  D3DK::GetSurfaceFormat(a1);
  v1 = D3DK::g_pDevice;
  v2 = 2976;
  do
  {
    if ( *(unsigned int **)((char *)&v1->m_Pusher.m_pPut + v2) )
      v3 = *(_DWORD *)((char *)v1 + v2 - 1744);
    else
      v3 = 0;
    v4 = *(int *)((char *)&v1->m_Pusher.m_pPut + v2);
    if ( v4 )
      v5 = *(_DWORD *)(v4 + 12);
    else
      v5 = 0;
    if ( v3 & 0x30 && (v5 & 0xF0000000 || (v5 & 0xF0) == 48) && v3 & 0xC0000000 )
    {
      D3DK::DXGRIP(a1, "No aniso support for 3D textures");
      v1 = D3DK::g_pDevice;
    }
    v2 += 4;
  }
  while ( v2 < 2992 );
  v6 = 0;
  v7 = 1232;
  do
  {
    if ( *(_DWORD *)((char *)&D3DK::g_pDevice->m_ModelViewTransform[3]._41 + v7) )
      v8 = *(int *)((char *)&D3DK::g_pDevice->m_Pusher.m_pPut + v7);
    else
      v8 = 0;
    if ( (v8 & 0xC0000000) == 0x40000000 && D3DK::GetTextureImageRect((unsigned int)v6) & 1 && v8 & 8 )
      D3DK::DXGRIP(v6, "Invalid height with field enable");
    v7 += 4;
    v6 = (int *)((char *)v6 + 1);
  }
  while ( v7 < 1248 );
  v9 = D3DK::g_pDevice;
  v10 = 2976;
  do
  {
    if ( *(unsigned int **)((char *)&v9->m_Pusher.m_pPut + v10) )
      v11 = *(_DWORD *)((char *)v9 + v10 - 1744);
    else
      v11 = 0;
    v12 = *(int *)((char *)&v9->m_Pusher.m_pPut + v10);
    if ( v12 )
      v13 = *(_DWORD *)(v12 + 12);
    else
      LOBYTE(v13) = 0;
    v14 = (int *)(v11 & 0xC0000000);
    if ( (v11 & 0xC0000000) == 0x40000000 && !(v13 & 8) && v11 & 8 )
    {
      D3DK::DXGRIP((int *)0x40000000, "Can't use ImageFieldEnable with border data in the texture");
      v9 = D3DK::g_pDevice;
    }
    v10 += 4;
  }
  while ( v10 < 2992 );
  v15 = 2976;
  do
  {
    if ( *(unsigned int **)((char *)&v9->m_Pusher.m_pPut + v15) )
      v16 = *(_DWORD *)((char *)v9 + v15 - 1744);
    else
      v16 = 0;
    v17 = *(int *)((char *)&v9->m_Pusher.m_pPut + v15);
    if ( v17 )
      v18 = *(_DWORD *)(v17 + 12);
    else
      LOWORD(v18) = 0;
    if ( v16 & 8 )
    {
      if ( v16 & 0xC0000000 )
      {
        v19 = (unsigned __int16)v18 >> 8;
        if ( v19 != 16
          && v19 != 17
          && v19 != 18
          && v19 != 19
          && v19 != 20
          && v19 != 21
          && v19 != 22
          && v19 != 23
          && v19 != 24
          && v19 != 27
          && v19 != 28
          && v19 != 29
          && v19 != 30
          && v19 != 31
          && v19 != 32
          && v19 != 36
          && v19 != 37
          && v19 != 38
          && v19 != 46
          && v19 != 47
          && v19 != 48
          && v19 != 49
          && v19 != 52
          && v19 != 53
          && v19 != 54
          && v19 != 55
          && v19 != 61
          && v19 != 62
          && v19 != 63
          && v19 != 64
          && v19 != 65 )
        {
          D3DK::DXGRIP(v14, "Can't use ImageFieldEnable unless texture is a linear format");
          v9 = D3DK::g_pDevice;
        }
      }
    }
    v15 += 4;
  }
  while ( v15 < 2992 );
  v20 = 0;
  v21 = 1232;
  do
  {
    if ( *(_DWORD *)((char *)&D3DK::g_pDevice->m_ModelViewTransform[3]._41 + v21) )
      v22 = *(int *)((char *)&D3DK::g_pDevice->m_Pusher.m_pPut + v21);
    else
      v22 = 0;
    v23 = D3DK::GetTextureFilter((unsigned int)v20);
    if ( v22 & 0x30 && ((v23 & 0xFF0000) == 458752 || (v23 & 0xF000000) == 0x4000000) && v22 & 0xC0000000 )
      D3DK::DXGRIP(v20, "No aniso support for convolution filter");
    v21 += 4;
    v20 = (int *)((char *)v20 + 1);
  }
  while ( v21 < 1248 );
  v24 = D3DK::g_pDevice;
  v25 = 2976;
  do
  {
    v26 = *(int *)((char *)&v24->m_Pusher.m_pPut + v25);
    if ( v26 )
      v27 = *(_DWORD *)(v26 + 12);
    else
      LOWORD(v27) = 0;
    if ( *(unsigned int **)((char *)&v24->m_Pusher.m_pPut + v25) )
      v28 = *(_DWORD *)((char *)v24 + v25 - 1744);
    else
      v28 = 0;
    v29 = (unsigned __int16)v27 >> 8;
    if ( v29 == 12 || v29 == 14 || v29 == 15 )
    {
      if ( v28 & 0xC0000000 )
      {
        v30 = v28 & 3;
        if ( v30 == 1 || v30 == 2 || v30 == 3 )
        {
          D3DK::DXGRIP(v20, "No color-key support for compressed texture formats");
          v24 = D3DK::g_pDevice;
        }
      }
    }
    v25 += 4;
  }
  while ( v25 < 2992 );
  v31 = (int *)2976;
  v32 = dword_800C21F4;
  do
  {
    v33 = *(int *)((char *)&v24->m_Pusher.m_pPut + (_DWORD)v31);
    if ( v33 )
      v34 = *(_DWORD *)(v33 + 12);
    else
      LOWORD(v34) = 0;
    if ( *(unsigned int **)((char *)&v24->m_Pusher.m_pPut + (_DWORD)v31) )
      v35 = *(_DWORD *)((char *)v24 + (_DWORD)v31 - 1744);
    else
      v35 = 0;
    v36 = (unsigned __int16)v34 >> 8;
    if ( v36 == 16
      || v36 == 17
      || v36 == 18
      || v36 == 19
      || v36 == 20
      || v36 == 21
      || v36 == 22
      || v36 == 23
      || v36 == 24
      || v36 == 27
      || v36 == 28
      || v36 == 29
      || v36 == 30
      || v36 == 31
      || v36 == 32
      || v36 == 61
      || v36 == 62
      || v36 == 63
      || v36 == 64
      || v36 == 65
      || v36 == 36
      || v36 == 37
      || v36 == 46
      || v36 == 47
      || v36 == 48
      || v36 == 49
      || v36 == 52
      || v36 == 53
      || v36 == 54
      || v36 == 55
      || v36 == 38 )
    {
      if ( v35 & 0xC0000000 )
      {
        *(_BYTE *)v32;
        v37 = (*((_BYTE *)v32 - 4) | *(_BYTE *)(4 * (v32[17] & 0xFFFF) - 2146687704)) & 0xF;
        if ( v37 == 1
          || v37 == 2
          || (v38 = ((*(v32 - 1) | *(_DWORD *)(4 * (v32[17] & 0xFFFF) - 2146687704) | ((*v32 | (unsigned int)(v32[1] << 8)) << 8)) >> 8) & 0xF,
              v38 == 1)
          || (((*(v32 - 1) | *(_DWORD *)(4 * (v32[17] & 0xFFFF) - 2146687704) | ((*v32 | (unsigned int)(v32[1] << 8)) << 8)) >> 8) & 0xF) == 2 )
        {
          D3DK::DXGRIP(v31, "No wrap or mirror if texture is a linear format");
          v24 = D3DK::g_pDevice;
        }
      }
    }
    v32 += 32;
    ++v31;
  }
  while ( (signed int)v32 < (signed int)dword_800C23F4 );
  v39 = D3DK::g_pDevice->m_ColorOCW;
  v40 = (int *)7;
  do
  {
    v41 = *v39;
    if ( (*v39 & 0xFFF80000) == 0x80000 && (unsigned __int8)v41 >> 4 && !((unsigned __int8)v41 >> 4)
      || v41 & 0x40000 && (v42 = *v39 & 0xF) != 0 && !v42 )
    {
      D3DK::DXGRIP(v40, "Can't have Color OCW combiner and Alpha OCW combiner going to same destination");
    }
    ++v39;
    v40 = (int *)((char *)v40 - 1);
  }
  while ( v40 );
  if ( D3DK::g_pDevice->m_pPixelShader )
  {
    v43 = D3DK::GetShaderStageProgram();
    v44 = (int *)((v43 >> 10) & 0x1F);
    if ( (v44 == (int *)9
       || v44 == (int *)10
       || v44 == (int *)11
       || v44 == (int *)6
       || v44 == (int *)7
       || v44 == (int *)15
       || v44 == (int *)16
       || v44 == (int *)17)
      && ((v43 & 0x1F) == 5 || !(v43 & 0x1F)) )
    {
      D3DK::DXGRIP(v44, "Need a color in this stage");
    }
    v45 = (v43 >> 15) & 0x1F;
    pDevice = (D3DK::CDevice *)((v43 >> 15) & 0x1F);
    if ( (v45 == 9
       || v45 == 10
       || v45 == 12
       || v45 == 18
       || v45 == 13
       || v45 == 14
       || v45 == 6
       || v45 == 7
       || v45 == 15
       || v45 == 16)
      && ((v43 & 0x1F) == 5 || !(v43 & 0x1F)) )
    {
      D3DK::DXGRIP(v44, "Need a color in this stage");
      v45 = (v43 >> 15) & 0x1F;
    }
    v46 = D3DK::g_pDevice;
    if ( D3DK::g_pDevice->m_Textures[0] )
      v47 = D3DK::g_pDevice->m_TextureControl0Enabled[0];
    else
      v47 = 0;
    v48 = v43 & 0x1F;
    if ( v48 != 5 && v48 != 4 && v43 & 0x1F && !(v47 & 0xC0000000) )
    {
      D3DK::DXGRIP(v44, "Stage requires a texture but none enabled");
      v46 = D3DK::g_pDevice;
      v45 = (v43 >> 15) & 0x1F;
    }
    if ( v46->m_Textures[1] )
      v49 = v46->m_TextureControl0Enabled[1];
    else
      v49 = 0;
    v50 = v43 >> 5;
    v51 = v50 & 0x1F;
    if ( v51 != 5 && v51 != 4 && v51 != 17 && v50 & 0x1F && !(v49 & 0xC0000000) )
    {
      D3DK::DXGRIP(v44, "Stage requires a texture but none enabled");
      v46 = D3DK::g_pDevice;
      v45 = (int)pDevice;
    }
    if ( v46->m_Textures[2] )
      v52 = v46->m_TextureControl0Enabled[2];
    else
      v52 = 0;
    if ( v44 != (int *)5 && v44 != (int *)4 && v44 != (int *)17 && v44 != (int *)10 && v44 && !(v52 & 0xC0000000) )
    {
      D3DK::DXGRIP(v44, "Stage requires a texture but none enabled");
      v46 = D3DK::g_pDevice;
      v45 = (int)pDevice;
    }
    if ( v46->m_Textures[3] )
      v53 = v46->m_TextureControl0Enabled[3];
    else
      v53 = 0;
    if ( v45 != 5 && v45 != 4 && v44 != (int *)10 && v45 && !(v53 & 0xC0000000) )
      D3DK::DXGRIP(v44, "Stage requires a texture but none enabled");
  }
}