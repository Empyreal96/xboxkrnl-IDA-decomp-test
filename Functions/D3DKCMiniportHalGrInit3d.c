void __thiscall D3DK::CMiniport::HalGrInit3d(D3DK::CMiniport *this)
{
  _DWORD *v1; // esi
  unsigned int v2; // ecx
  int *v3; // edi
  _DWORD *v4; // eax
  signed int v5; // ecx
  _DWORD *v6; // eax
  signed int v7; // ecx
  _DWORD *v8; // eax
  signed int v9; // ecx
  _DWORD *v10; // eax
  signed int v11; // ecx
  _DWORD *v12; // eax
  signed int v13; // ecx
  _DWORD *v14; // eax
  signed int v15; // ecx
  _DWORD *v16; // eax
  signed int v17; // ecx
  signed int v18; // eax
  _DWORD *v19; // ecx
  signed int v20; // edx
  _DWORD *v21; // ecx
  signed int v22; // edx
  _DWORD *v23; // ecx
  signed int v24; // edx
  _DWORD *v25; // ecx
  _DWORD *v26; // eax
  signed int v27; // ecx
  _DWORD *v28; // ecx
  signed int v29; // edx
  signed int v30; // eax
  _DWORD *v31; // edx
  _DWORD *v32; // edx
  unsigned int v33; // ecx
  int v34; // eax
  _DWORD *v35; // edx
  bool v36; // zf
  int v37; // eax
  _DWORD *v38; // edx
  int v39; // eax
  _DWORD *v40; // edx
  int v41; // eax
  _DWORD *v42; // edx
  int v43; // eax
  _DWORD *v44; // edx
  int v45; // eax
  _DWORD *v46; // edx
  int v47; // eax
  _DWORD *v48; // edx
  int v49; // eax
  _DWORD *v50; // edx
  int v51; // eax
  _DWORD *v52; // edx
  int v53; // eax
  _DWORD *v54; // edx
  int v55; // eax
  int v56; // ecx
  int v57; // ecx
  int v58; // ecx
  int v59; // ecx
  int v60; // ecx
  int v61; // ecx
  int v62; // ecx
  int v63; // ecx
  int v64; // ecx
  int v65; // eax
  D3DK::CMiniport *v66; // [esp+Ch] [ebp-20h]
  unsigned int zoserC1Offset; // [esp+10h] [ebp-1Ch]
  unsigned int zoserC0Offset; // [esp+14h] [ebp-18h]
  unsigned int grCtxBuffer; // [esp+18h] [ebp-14h]
  signed int v70; // [esp+1Ch] [ebp-10h]
  signed int v71; // [esp+1Ch] [ebp-10h]
  signed int v72; // [esp+1Ch] [ebp-10h]
  signed int v73; // [esp+1Ch] [ebp-10h]
  signed int v74; // [esp+1Ch] [ebp-10h]
  signed int v75; // [esp+1Ch] [ebp-10h]
  signed int v76; // [esp+1Ch] [ebp-10h]
  signed int v77; // [esp+1Ch] [ebp-10h]
  signed int v78; // [esp+1Ch] [ebp-10h]
  signed int v79; // [esp+20h] [ebp-Ch]
  signed int v80; // [esp+20h] [ebp-Ch]
  int v81; // [esp+20h] [ebp-Ch]
  int v82; // [esp+20h] [ebp-Ch]
  int v83; // [esp+20h] [ebp-Ch]
  int v84; // [esp+20h] [ebp-Ch]
  int v85; // [esp+20h] [ebp-Ch]
  int v86; // [esp+20h] [ebp-Ch]
  int v87; // [esp+20h] [ebp-Ch]
  int v88; // [esp+20h] [ebp-Ch]
  int v89; // [esp+20h] [ebp-Ch]
  unsigned int zoserCtxAoffset; // [esp+24h] [ebp-8h]
  unsigned int zoserCtxAoffseta; // [esp+24h] [ebp-8h]
  unsigned int cheopsCtxOffset; // [esp+28h] [ebp-4h]

  v1 = this->m_RegisterBase;
  v66 = this;
  v2 = this->m_HalInfo.GrCtxTable[this->m_HalInfo.FifoChID];
  v3 = (int *)(4 * (v2 + 458752));
  v1[4 * (v2 + 458752)] |= 1u;
  v1[(_DWORD)v3 + 207] = -65536;
  v1[(_DWORD)v3 + 208] = 0;
  v1[(_DWORD)v3 + 209] = 0;
  v1[(_DWORD)v3 + 210] = 0;
  v1[(_DWORD)v3 + 211] = 0;
  v1[(_DWORD)v3 + 212] = 0;
  v1[(_DWORD)v3 + 213] = 0;
  v1[(_DWORD)v3 + 214] = 0;
  v1[(_DWORD)v3 + 215] = 0;
  v1[(_DWORD)v3 + 216] = 0;
  v1[(_DWORD)v3 + 217] = 0;
  v1[(_DWORD)v3 + 218] = 0;
  v1[(_DWORD)v3 + 219] = 0;
  v1[(_DWORD)v3 + 220] = 0;
  v1[(_DWORD)v3 + 221] = 0;
  v1[(_DWORD)v3 + 222] = 0;
  v1[(_DWORD)v3 + 223] = 0;
  v1[(_DWORD)v3 + 224] = 0;
  v1[(_DWORD)v3 + 225] = 0;
  v1[(_DWORD)v3 + 226] = 0;
  v1[(_DWORD)v3 + 227] = 0;
  v1[(_DWORD)v3 + 228] = 0;
  v1[(_DWORD)v3 + 229] = 0;
  v1[(_DWORD)v3 + 230] = 0;
  v1[(_DWORD)v3 + 231] = 0;
  v1[(_DWORD)v3 + 232] = 268369920;
  v1[(_DWORD)v3 + 233] = 268369920;
  v1[(_DWORD)v3 + 234] = 0;
  v1[(_DWORD)v3 + 235] = 0;
  v1[(_DWORD)v3 + 236] = 0;
  v1[(_DWORD)v3 + 237] = 0;
  v1[(_DWORD)v3 + 238] = 0;
  v1[(_DWORD)v3 + 239] = 0;
  v1[(_DWORD)v3 + 240] = 0;
  v1[(_DWORD)v3 + 241] = 0;
  v1[(_DWORD)v3 + 242] = 0;
  v1[(_DWORD)v3 + 243] = 0;
  v1[(_DWORD)v3 + 244] = 0;
  v1[(_DWORD)v3 + 245] = 0;
  v1[(_DWORD)v3 + 246] = 0;
  v1[(_DWORD)v3 + 247] = 0;
  v1[(_DWORD)v3 + 248] = 0;
  v1[(_DWORD)v3 + 249] = 0;
  v1[(_DWORD)v3 + 250] = 0;
  v1[(_DWORD)v3 + 251] = 0;
  v1[(_DWORD)v3 + 252] = 0;
  v1[(_DWORD)v3 + 253] = 0;
  v1[(_DWORD)v3 + 254] = 0;
  v1[(_DWORD)v3 + 255] = 0;
  v1[(_DWORD)v3 + 256] = 0;
  v1[(_DWORD)v3 + 257] = 0;
  v1[(_DWORD)v3 + 258] = 0;
  v1[(_DWORD)v3 + 259] = 0;
  v1[(_DWORD)v3 + 260] = 0;
  v1[(_DWORD)v3 + 261] = 0;
  v1[(_DWORD)v3 + 262] = 0;
  v1[(_DWORD)v3 + 263] = 0;
  v1[(_DWORD)v3 + 264] = 0;
  v1[(_DWORD)v3 + 265] = 0;
  v1[(_DWORD)v3 + 266] = 0;
  v1[(_DWORD)v3 + 267] = 0;
  v1[(_DWORD)v3 + 268] = 0;
  grCtxBuffer = v2;
  v1[(_DWORD)v3 + 269] = 0;
  v1[(_DWORD)v3 + 270] = 0;
  v1[(_DWORD)v3 + 271] = 0;
  v1[(_DWORD)v3 + 272] = 0;
  v1[(_DWORD)v3 + 273] = 0;
  v1[(_DWORD)v3 + 274] = 0;
  v1[(_DWORD)v3 + 275] = 0;
  v1[(_DWORD)v3 + 276] = 0;
  v1[(_DWORD)v3 + 277] = 0;
  v1[(_DWORD)v3 + 278] = 0;
  v1[(_DWORD)v3 + 279] = 0;
  v1[(_DWORD)v3 + 280] = 0;
  v1[(_DWORD)v3 + 281] = 0;
  v1[(_DWORD)v3 + 282] = 0;
  v1[(_DWORD)v3 + 283] = 0;
  v1[(_DWORD)v3 + 284] = 0;
  v1[(_DWORD)v3 + 285] = 0;
  v1[(_DWORD)v3 + 286] = 0;
  v1[(_DWORD)v3 + 287] = 257;
  v1[(_DWORD)v3 + 288] = 0;
  v1[(_DWORD)v3 + 289] = 0;
  v1[(_DWORD)v3 + 290] = 0;
  v1[(_DWORD)v3 + 291] = 0;
  v1[(_DWORD)v3 + 292] = 273;
  v1[(_DWORD)v3 + 293] = 0;
  v1[(_DWORD)v3 + 294] = 0;
  v1[(_DWORD)v3 + 295] = 0;
  v1[(_DWORD)v3 + 296] = 0;
  v1[(_DWORD)v3 + 297] = 0;
  v1[(_DWORD)v3 + 298] = 1145044992;
  v1[(_DWORD)v3 + 299] = 0;
  v1[(_DWORD)v3 + 300] = 0;
  v1[(_DWORD)v3 + 301] = 0;
  v1[(_DWORD)v3 + 302] = 0;
  v1[(_DWORD)v3 + 303] = 0;
  v1[(_DWORD)v3 + 304] = 0;
  v1[(_DWORD)v3 + 305] = 0;
  v1[(_DWORD)v3 + 306] = 0;
  v1[(_DWORD)v3 + 307] = 0;
  v1[(_DWORD)v3 + 308] = 0;
  v1[(_DWORD)v3 + 309] = 197379;
  v1[(_DWORD)v3 + 310] = 197379;
  v1[(_DWORD)v3 + 311] = 197379;
  v1[(_DWORD)v3 + 312] = 197379;
  v1[(_DWORD)v3 + 313] = 0;
  v1[(_DWORD)v3 + 314] = 0;
  v1[(_DWORD)v3 + 315] = 0;
  v1[(_DWORD)v3 + 316] = 0;
  v1[(_DWORD)v3 + 317] = 0x80000;
  v1[(_DWORD)v3 + 318] = 0x80000;
  v1[(_DWORD)v3 + 319] = 0x80000;
  v1[(_DWORD)v3 + 320] = 0x80000;
  v1[(_DWORD)v3 + 321] = 0;
  v1[(_DWORD)v3 + 322] = 0;
  v1[(_DWORD)v3 + 323] = 16850944;
  v1[(_DWORD)v3 + 324] = 16850944;
  v1[(_DWORD)v3 + 325] = 16850944;
  v1[(_DWORD)v3 + 326] = 16850944;
  v1[(_DWORD)v3 + 327] = 67000;
  v1[(_DWORD)v3 + 328] = 67000;
  v1[(_DWORD)v3 + 329] = 67000;
  v1[(_DWORD)v3 + 330] = 67000;
  v1[(_DWORD)v3 + 331] = 524296;
  v1[(_DWORD)v3 + 332] = 524296;
  v1[(_DWORD)v3 + 333] = 524296;
  v1[(_DWORD)v3 + 334] = 524296;
  v1[(_DWORD)v3 + 335] = 0;
  v1[(_DWORD)v3 + 336] = 0;
  v1[(_DWORD)v3 + 337] = 0;
  v1[(_DWORD)v3 + 338] = 0;
  v1[(_DWORD)v3 + 339] = 0;
  v1[(_DWORD)v3 + 340] = 0;
  v1[(_DWORD)v3 + 341] = 0;
  v1[(_DWORD)v3 + 342] = 0;
  v4 = &v1[4 * v2 + 1835351];
  v5 = 8;
  do
  {
    *v4 = 134152192;
    ++v4;
    --v5;
  }
  while ( v5 );
  v6 = &v1[(_DWORD)v3 + 351];
  v7 = 8;
  do
  {
    *v6 = 134152192;
    ++v6;
    --v7;
  }
  while ( v7 );
  v1[(_DWORD)v3 + 359] = 0;
  v1[(_DWORD)v3 + 360] = 0;
  v1[(_DWORD)v3 + 361] = 1266679807;
  v1[(_DWORD)v3 + 362] = 0;
  v1[(_DWORD)v3 + 363] = 0;
  v1[(_DWORD)v3 + 364] = 0;
  v1[(_DWORD)v3 + 365] = 0;
  v1[(_DWORD)v3 + 366] = 0;
  v1[(_DWORD)v3 + 367] = 0;
  v1[(_DWORD)v3 + 368] = 0;
  v1[(_DWORD)v3 + 369] = 0;
  v1[(_DWORD)v3 + 370] = 0;
  v1[(_DWORD)v3 + 371] = 0;
  v1[(_DWORD)v3 + 372] = 0;
  v1[(_DWORD)v3 + 373] = 0;
  v1[(_DWORD)v3 + 374] = 0;
  v1[(_DWORD)v3 + 375] = 0;
  v1[(_DWORD)v3 + 376] = 0;
  v1[(_DWORD)v3 + 377] = 0;
  v1[(_DWORD)v3 + 378] = 0;
  v1[(_DWORD)v3 + 379] = 0;
  v1[(_DWORD)v3 + 380] = 0;
  v1[(_DWORD)v3 + 381] = 0;
  v1[(_DWORD)v3 + 382] = 0;
  v1[(_DWORD)v3 + 383] = 1;
  v1[(_DWORD)v3 + 384] = 0;
  v1[(_DWORD)v3 + 385] = 0x4000;
  v1[(_DWORD)v3 + 386] = 0;
  v1[(_DWORD)v3 + 387] = 0;
  v1[(_DWORD)v3 + 388] = 1;
  v1[(_DWORD)v3 + 389] = 0;
  v1[(_DWORD)v3 + 390] = 0x40000;
  v1[(_DWORD)v3 + 391] = 0x10000;
  v1[(_DWORD)v3 + 392] = 0;
  v1[(_DWORD)v3 + 393] = 0;
  v1[(_DWORD)v3 + 394] = 0;
  v8 = &v1[(_DWORD)v3 + 395];
  v9 = 35;
  do
  {
    *v8 = 0;
    ++v8;
    --v9;
  }
  while ( v9 );
  v10 = &v1[(_DWORD)v3 + 430];
  v11 = 29;
  do
  {
    *v10 = 0;
    ++v10;
    --v11;
  }
  while ( v11 );
  v12 = &v1[(_DWORD)v3 + 459];
  v13 = 29;
  do
  {
    *v12 = 0;
    ++v12;
    --v13;
  }
  while ( v13 );
  v14 = &v1[(_DWORD)v3 + 488];
  v15 = 29;
  do
  {
    *v14 = 0;
    ++v14;
    --v15;
  }
  while ( v15 );
  v16 = &v1[(_DWORD)v3 + 517];
  v17 = 2;
  do
  {
    *v16 = 0;
    ++v16;
    --v17;
  }
  while ( v17 );
  v18 = 128;
  v19 = &v1[(_DWORD)v3 + 519];
  v20 = 128;
  do
  {
    *v19 = 0;
    ++v19;
    --v20;
  }
  while ( v20 );
  v21 = &v1[(_DWORD)v3 + 647];
  v22 = 128;
  do
  {
    *v21 = 0;
    ++v21;
    --v22;
  }
  while ( v22 );
  v23 = &v1[(_DWORD)v3 + 775];
  v24 = 128;
  do
  {
    *v23 = 0;
    ++v23;
    --v24;
  }
  while ( v24 );
  v25 = &v1[(_DWORD)v3 + 903];
  do
  {
    *v25 = 0;
    ++v25;
    --v18;
  }
  while ( v18 );
  v26 = &v1[(_DWORD)v3 + 1031];
  v27 = 192;
  do
  {
    *v26 = 0;
    ++v26;
    --v27;
  }
  while ( v27 );
  v28 = &v1[(_DWORD)v3 + 1223];
  v29 = 480;
  v30 = 1703;
  do
  {
    *v28 = 0;
    ++v28;
    --v29;
  }
  while ( v29 );
  v31 = &v1[(_DWORD)v3 + 1703];
  v79 = 136;
  do
  {
    *v31 = 275779577;
    v32 = v31 + 1;
    *v32 = 70649964;
    ++v32;
    *v32 = 786459;
    ++v32;
    *v32 = 0;
    v30 += 4;
    v31 = v32 + 1;
    --v79;
  }
  while ( v79 );
  v33 = v30;
  cheopsCtxOffset = v30;
  zoserCtxAoffset = (unsigned int)&v1[(_DWORD)v3 + v30];
  v80 = 768;
  v34 = v30 + 768;
  do
  {
    v35 = (_DWORD *)zoserCtxAoffset;
    zoserCtxAoffset += 4;
    v36 = v80-- == 1;
    *v35 = 0;
  }
  while ( !v36 );
  zoserCtxAoffseta = v34;
  v81 = (int)&v1[(_DWORD)v3 + v34];
  v70 = 104;
  v37 = v34 + 104;
  do
  {
    v38 = (_DWORD *)v81;
    v81 += 4;
    v36 = v70-- == 1;
    *v38 = 0;
  }
  while ( !v36 );
  v82 = (int)&v1[(_DWORD)v3 + v37];
  v71 = 208;
  v39 = v37 + 208;
  do
  {
    v40 = (_DWORD *)v82;
    v82 += 4;
    v36 = v71-- == 1;
    *v40 = 0;
  }
  while ( !v36 );
  zoserC0Offset = v39;
  v83 = (int)&v1[(_DWORD)v3 + v39];
  v72 = 4;
  v41 = v39 + 4;
  do
  {
    v42 = (_DWORD *)v83;
    v83 += 4;
    v36 = v72-- == 1;
    *v42 = 0;
  }
  while ( !v36 );
  zoserC1Offset = v41;
  v84 = (int)&v1[(_DWORD)v3 + v41];
  v73 = 20;
  v43 = v41 + 20;
  do
  {
    v44 = (_DWORD *)v84;
    v84 += 4;
    v36 = v73-- == 1;
    *v44 = 0;
  }
  while ( !v36 );
  v85 = (int)&v1[(_DWORD)v3 + v43];
  v74 = 15;
  v45 = v43 + 15;
  do
  {
    v46 = (_DWORD *)v85;
    v85 += 4;
    v36 = v74-- == 1;
    *v46 = 0;
  }
  while ( !v36 );
  v86 = (int)&v1[(_DWORD)v3 + v45];
  v75 = 14;
  v47 = v45 + 14;
  do
  {
    v48 = (_DWORD *)v86;
    v86 += 4;
    v36 = v75-- == 1;
    *v48 = 0;
  }
  while ( !v36 );
  v87 = (int)&v1[(_DWORD)v3 + v47];
  v76 = 68;
  v49 = v47 + 68;
  do
  {
    v50 = (_DWORD *)v87;
    v87 += 4;
    v36 = v76-- == 1;
    *v50 = 0;
  }
  while ( !v36 );
  v88 = (int)&v1[(_DWORD)v3 + v49];
  v77 = 32;
  v51 = v49 + 32;
  do
  {
    v52 = (_DWORD *)v88;
    v88 += 4;
    v36 = v77-- == 1;
    *v52 = 0;
  }
  while ( !v36 );
  v89 = (int)&v1[(_DWORD)v3 + v51];
  v78 = 15;
  v53 = v51 + 15;
  do
  {
    v54 = (_DWORD *)v89;
    v89 += 4;
    v36 = v78-- == 1;
    *v54 = 0;
  }
  while ( !v36 );
  v1[(_DWORD)v3 + v53] = 0;
  if ( v53 != 3495 )
  {
    D3DK::DXGRIP(
      v3,
      "Assertion failure: %s",
      "offset + 4 == (sizeof(GRCTX3D_NV20) + sizeof(GRCTXCMN_NV20) + sizeof(GRCTXPIPE_NV2A)) / 4");
    v33 = cheopsCtxOffset;
  }
  v1[(_DWORD)v3 + v33 + 224] = 1065353216;
  v1[(_DWORD)v3 + v33 + 225] = 0;
  v1[(_DWORD)v3 + v33 + 226] = 0;
  v55 = 4 * grCtxBuffer;
  v1[4 * grCtxBuffer + 1835235 + v33] = 0;
  v1[(_DWORD)v3 + v33 + 240] = 0x40000000;
  v1[(_DWORD)v3 + v33 + 241] = 1065353216;
  v1[(_DWORD)v3 + v33 + 242] = 1056964608;
  v1[v55 + 1835251 + v33] = 0;
  v1[(_DWORD)v3 + cheopsCtxOffset + 244] = 0x40000000;
  v1[(_DWORD)v3 + cheopsCtxOffset + 245] = 1065353216;
  v56 = cheopsCtxOffset + 246;
  v1[(_DWORD)v3 + v56] = 0;
  v1[v55 + 1835009 + v56] = -1082130432;
  v1[(_DWORD)v3 + cheopsCtxOffset + 248] = 0;
  v1[(_DWORD)v3 + cheopsCtxOffset + 249] = -1082130432;
  v57 = cheopsCtxOffset + 250;
  v1[(_DWORD)v3 + v57] = 0;
  v1[v55 + 1835009 + v57] = 0;
  v1[(_DWORD)v3 + cheopsCtxOffset + 228] = 0;
  v1[(_DWORD)v3 + cheopsCtxOffset + 229] = 1065353216;
  v58 = cheopsCtxOffset + 230;
  v1[(_DWORD)v3 + v58] = 0;
  v1[v55 + 1835009 + v58] = 0;
  v1[(_DWORD)v3 + cheopsCtxOffset + 252] = 0;
  v1[(_DWORD)v3 + cheopsCtxOffset + 253] = 0;
  v59 = cheopsCtxOffset + 254;
  v1[(_DWORD)v3 + v59] = 0;
  v1[v55 + 1835009 + v59] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 88] = 0;
  v60 = zoserCtxAoffseta + 90;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 89] = 0;
  v1[(_DWORD)v3 + v60] = 0;
  v1[v55 + 1835009 + v60] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 64] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 65] = 0;
  v61 = zoserCtxAoffseta + 66;
  v1[(_DWORD)v3 + v61] = 1040384;
  v1[v55 + 1835009 + v61] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 68] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 69] = 0;
  v62 = zoserCtxAoffseta + 70;
  v1[(_DWORD)v3 + v62] = 0;
  v1[v55 + 1835009 + v62] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 76] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 77] = 0;
  v63 = zoserCtxAoffseta + 78;
  v1[(_DWORD)v3 + v63] = 0;
  v1[v55 + 1835009 + v63] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 96] = 0;
  v1[(_DWORD)v3 + zoserCtxAoffseta + 97] = 1016;
  v64 = zoserCtxAoffseta + 98;
  v1[(_DWORD)v3 + v64] = 0;
  v1[v55 + 1835009 + v64] = 0;
  v1[v55 + 1835009 + zoserC0Offset] = 3137536;
  v65 = zoserC1Offset + 4 * grCtxBuffer;
  v1[zoserC1Offset + 4 * grCtxBuffer + 1835012] = 1856124;
  v1[v65 + 1835013] = 1856124;
  v1[v65 + 1835014] = 1856124;
  v1[v65 + 1835015] = 1856124;
  v1[zoserC1Offset + 4 * grCtxBuffer + 1835016] = 1856124;
  v1[v65 + 1835017] = 1856124;
  v1[v65 + 1835018] = 1856124;
  v1[v65 + 1835019] = 1856124;
  if ( v66->m_HalInfo.GrChID == v66->m_HalInfo.FifoChID )
    D3DK::DXGRIP((int *)grCtxBuffer, "Assertion failure: %s", "m_HalInfo.GrChID != (ULONG)m_HalInfo.FifoChID");
}