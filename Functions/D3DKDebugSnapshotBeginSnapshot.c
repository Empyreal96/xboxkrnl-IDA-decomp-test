void __thiscall D3DK::DebugSnapshot::BeginSnapshot(D3DK::DebugSnapshot *this, unsigned int dwPX, unsigned int dwPY)
{
  D3DK::DebugSnapshot *v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // eax
  unsigned int v46; // eax
  unsigned int v47; // eax
  int *v48; // edi

  v3 = this;
  this->dwY = dwPY;
  this->dwX = dwPX;
  this->dwCaptureCount = 0;
  *D3DK::g_pDevice->m_pShaderCapturePtr = 16777218;
  ++D3DK::g_pDevice->m_pShaderCapturePtr;
  v4 = this->dwCaptureCount + 1;
  this->dwCaptureCount = v4;
  if ( v4 < 0x2000 )
  {
    *D3DK::g_pDevice->m_pShaderCapturePtr = this->dwX | (this->dwY << 16);
    ++D3DK::g_pDevice->m_pShaderCapturePtr;
    ++this->dwCaptureCount;
  }
  this->UserStateCount = 0;
  this->UserState[0].Enum = 60;
  v5 = this->UserStateCount + 1;
  this->UserStateCount = v5;
  this->UserState[v5].Enum = 124;
  v6 = this->UserStateCount + 1;
  this->UserStateCount = v6;
  this->UserState[v6].Enum = 123;
  v7 = this->UserStateCount + 1;
  this->UserStateCount = v7;
  this->UserState[v7].Enum = 59;
  v8 = this->UserStateCount + 1;
  this->UserStateCount = v8;
  this->UserState[v8].Enum = 62;
  v9 = this->UserStateCount + 1;
  this->UserStateCount = v9;
  this->UserState[v9].Enum = 63;
  v10 = this->UserStateCount + 1;
  this->UserStateCount = v10;
  this->UserState[v10].Enum = 67;
  v11 = this->UserStateCount + 1;
  this->UserStateCount = v11;
  this->UserState[v11].Enum = 8;
  v12 = this->UserStateCount + 1;
  this->UserStateCount = v12;
  this->UserState[v12].Enum = 9;
  v13 = this->UserStateCount + 1;
  this->UserStateCount = v13;
  this->UserState[v13].Enum = 53;
  v14 = this->UserStateCount + 1;
  this->UserStateCount = v14;
  this->UserState[v14].Enum = 34;
  v15 = this->UserStateCount + 1;
  this->UserStateCount = v15;
  this->UserState[v15].Enum = 35;
  v16 = this->UserStateCount + 1;
  this->UserStateCount = v16;
  this->UserState[v16].Enum = 36;
  v17 = this->UserStateCount + 1;
  this->UserStateCount = v17;
  this->UserState[v17].Enum = 37;
  v18 = this->UserStateCount + 1;
  this->UserStateCount = v18;
  this->UserState[v18].Enum = 38;
  v19 = this->UserStateCount + 1;
  this->UserStateCount = v19;
  this->UserState[v19].Enum = 39;
  v20 = this->UserStateCount + 1;
  this->UserStateCount = v20;
  this->UserState[v20].Enum = 40;
  v21 = this->UserStateCount + 1;
  this->UserStateCount = v21;
  this->UserState[v21].Enum = 41;
  v22 = this->UserStateCount + 1;
  this->UserStateCount = v22;
  this->UserState[v22].Enum = 0;
  v23 = this->UserStateCount + 1;
  this->UserStateCount = v23;
  this->UserState[v23].Enum = 1;
  v24 = this->UserStateCount + 1;
  this->UserStateCount = v24;
  this->UserState[v24].Enum = 2;
  v25 = this->UserStateCount + 1;
  this->UserStateCount = v25;
  this->UserState[v25].Enum = 3;
  v26 = this->UserStateCount + 1;
  this->UserStateCount = v26;
  this->UserState[v26].Enum = 4;
  v27 = this->UserStateCount + 1;
  this->UserStateCount = v27;
  this->UserState[v27].Enum = 5;
  v28 = this->UserStateCount + 1;
  this->UserStateCount = v28;
  this->UserState[v28].Enum = 6;
  v29 = this->UserStateCount + 1;
  this->UserStateCount = v29;
  this->UserState[v29].Enum = 7;
  v30 = this->UserStateCount + 1;
  this->UserStateCount = v30;
  this->UserState[v30].Enum = 45;
  v31 = this->UserStateCount + 1;
  this->UserStateCount = v31;
  this->UserState[v31].Enum = 46;
  v32 = this->UserStateCount + 1;
  this->UserStateCount = v32;
  this->UserState[v32].Enum = 47;
  v33 = this->UserStateCount + 1;
  this->UserStateCount = v33;
  this->UserState[v33].Enum = 48;
  v34 = this->UserStateCount + 1;
  this->UserStateCount = v34;
  this->UserState[v34].Enum = 49;
  v35 = this->UserStateCount + 1;
  this->UserStateCount = v35;
  this->UserState[v35].Enum = 50;
  v36 = this->UserStateCount + 1;
  this->UserStateCount = v36;
  this->UserState[v36].Enum = 51;
  v37 = this->UserStateCount + 1;
  this->UserStateCount = v37;
  this->UserState[v37].Enum = 52;
  v38 = this->UserStateCount + 1;
  this->UserStateCount = v38;
  this->UserState[v38].Enum = 26;
  v39 = this->UserStateCount + 1;
  this->UserStateCount = v39;
  this->UserState[v39].Enum = 27;
  v40 = this->UserStateCount + 1;
  this->UserStateCount = v40;
  this->UserState[v40].Enum = 28;
  v41 = this->UserStateCount + 1;
  this->UserStateCount = v41;
  this->UserState[v41].Enum = 29;
  v42 = this->UserStateCount + 1;
  this->UserStateCount = v42;
  this->UserState[v42].Enum = 30;
  v43 = this->UserStateCount + 1;
  this->UserStateCount = v43;
  this->UserState[v43].Enum = 31;
  v44 = this->UserStateCount + 1;
  this->UserStateCount = v44;
  this->UserState[v44].Enum = 32;
  v45 = this->UserStateCount + 1;
  this->UserStateCount = v45;
  this->UserState[v45].Enum = 33;
  v46 = this->UserStateCount + 1;
  this->UserStateCount = v46;
  this->UserState[v46].Enum = 8;
  v47 = this->UserStateCount + 1;
  this->UserStateCount = v47;
  this->UserState[v47].Enum = 9;
  v48 = (int *)(this->UserStateCount + 1);
  this->UserStateCount = (unsigned int)v48;
  D3DDevice_GetBackBuffer(0, 0, &this->pBackBuffer);
  D3DDevice_GetDepthStencilSurface(v48, &v3->pDepthBuffer);
  v3->dwXScale = 0;
  v3->dwYScale = 0;
}