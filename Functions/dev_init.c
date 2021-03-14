// write access to const memory has been detected, the output may be wrong!
int __usercall dev_init@<eax>(int *a1@<edi>)
{
  __int16 v1; // ax
  _WORD *v2; // ecx
  unsigned __int64 v3; // rax
  int v4; // ecx
  bool v5; // sf
  unsigned __int8 v6; // of
  int v7; // esi
  signed int v8; // esi
  signed int v9; // eax
  __int16 v10; // cx
  unsigned __int16 *v11; // eax
  char *v12; // ecx
  signed int v13; // eax
  __int16 v14; // dx
  signed int v15; // eax
  __int16 v16; // dx
  _DSBUFFERDESC dsbdesc; // [esp+0h] [ebp-44h]
  tWAVEFORMATEX wfFirst; // [esp+18h] [ebp-2Ch]
  int lVolumes[3]; // [esp+2Ch] [ebp-18h]
  unsigned int dwMixBinMask; // [esp+38h] [ebp-Ch]
  int j; // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]

  holdrand = 1003;
  do
  {
    v1 = rand();
    *v2 = v1;
  }
  while ( (signed int)(v2 + 1) < (signed int)&dsp_address );
  i = 0;
  do
  {
    v3 = (unsigned __int64)(sin((double)i * 0.04908734375) * 32767.0);
    v4 = i++;
    v6 = __OFSUB__(i, 128);
    v5 = i - 128 < 0;
    *(_WORD *)(2 * v4 - 2146237968) = v3;
  }
  while ( v5 ^ v6 );
  j = 0;
  v7 = 0;
  i = 0;
  do
  {
    if ( v7 >= 0x4000 )
      --j;
    else
      ++j;
    *(_WORD *)(2 * v7++ - 2146303512) = (unsigned __int64)(sin(
                                                             sin(0.0981746875 * (double)i)
                                                           * (double)j
                                                           * 0.00006103515625
                                                           + (double)i * 0.196349375)
                                                         * 32767.0);
    i = v7;
  }
  while ( v7 < 0x8000 );
  v8 = 0;
  do
  {
    dwMixBinMask = v8 - 64;
    *(_WORD *)(2 * v8 - 2146305632) = (unsigned __int64)((double)(v8 - 64) * 0.0078125 * 65536.0);
    ++v8;
  }
  while ( v8 < 128 );
  v9 = 0;
  do
  {
    LOBYTE(v10) = 0;
    HIBYTE(v10) = ThunEl16Data[v9++];
    *(_WORD *)(2 * v9 - 2146349298) = v10;
  }
  while ( v9 < 21824 );
  v11 = ReverseThunEl16;
  v12 = channel_level;
  do
  {
    *v11 = *(_WORD *)v12;
    ++v11;
    v12 -= 2;
  }
  while ( (signed int)v11 < (signed int)Noise8192 );
  v13 = 0;
  do
  {
    LOBYTE(v14) = 0;
    HIBYTE(v14) = GlockData[v13++] ^ 0x80;
    *(_WORD *)(2 * v13 - 2146164234) = v14;
  }
  while ( v13 < 3768 );
  v15 = 0;
  do
  {
    LOBYTE(v16) = 0;
    HIBYTE(v16) = BubbleData[v15++] ^ 0x80;
    *(_WORD *)(2 * v15 - 2146237714) = v16;
  }
  while ( v15 < 6719 );
  if ( DirectSoundCreate(a1, 0, 0, &m_pDSound, 0) < 0 )
    return 0;
  memset(&dsbdesc, 0, sizeof(dsbdesc));
  dsbdesc.dwFlags = 0;
  dsbdesc.dwBufferBytes = 0;
  i = 0;
  dsbdesc.dwSize = 24;
  wfFirst.wFormatTag = 1;
  wfFirst.nChannels = 1;
  wfFirst.nSamplesPerSec = 48000;
  wfFirst.wBitsPerSample = 16;
  wfFirst.nBlockAlign = 2;
  wfFirst.nAvgBytesPerSec = 96000;
  dsbdesc.lpwfxFormat = &wfFirst;
  j = (int)m_pDSBuffer;
  while ( 1 )
  {
    dsbdesc.dwMixBinMask = 3;
    dwMixBinMask = 3;
    lVolumes[2] = -2800;
    if ( i % 2 )
    {
      lVolumes[1] = 0;
      lVolumes[0] = -600;
    }
    else
    {
      lVolumes[0] = 0;
      lVolumes[1] = -600;
    }
    if ( (int *)j == dword_801201AC || (int *)j == dword_801201B4 )
    {
      lVolumes[0] = 0;
      lVolumes[2] = 0;
      lVolumes[1] = -100;
      dwMixBinMask = 2051;
      dsbdesc.dwMixBinMask = 2051;
    }
    if ( DirectSoundCreateBuffer((int *)0xFFFFF510, 3, &dsbdesc, (IDirectSoundBuffer **)j) < 0 )
      break;
    IDirectSoundBuffer_SetMixBinVolumes(*(IDirectSoundBuffer **)j, dwMixBinMask, lVolumes);
    j += 4;
    ++i;
    if ( j >= (signed int)&dsp_data )
    {
      put_fifo(1);
      return 1;
    }
  }
  return -2147467259;
}