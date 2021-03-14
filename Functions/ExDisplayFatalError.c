void __userpurge __noreturn ExDisplayFatalError(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int ErrorCode)
{
  int *v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // ebx
  int v12; // edx
  int v13; // ecx
  D3DDevice *v14; // eax
  int v15; // ecx
  D3DDevice *v16; // esi
  unsigned int v17; // ecx
  unsigned __int8 v18; // dl
  unsigned __int8 v19; // bl
  int *v20; // edi
  unsigned int v21; // ebx
  double v22; // st7
  float b; // ST08_4
  float a; // ST04_4
  _EEPROM_LAYOUT EEPROMData; // [esp+1Ch] [ebp-118h]
  unsigned int SettingLength; // [esp+11Ch] [ebp-18h]
  unsigned int v27; // [esp+120h] [ebp-14h]
  unsigned int SettingType; // [esp+124h] [ebp-10h]
  int v29; // [esp+128h] [ebp-Ch]
  unsigned int Segment; // [esp+12Ch] [ebp-8h]
  D3DDevice *v31; // [esp+130h] [ebp-4h]
  unsigned int ErrorCodea; // [esp+13Ch] [ebp+8h]

  *(_DWORD *)XboxCERTKey = 0;
  *(_DWORD *)&XboxCERTKey[4] = 0;
  *(_DWORD *)&XboxCERTKey[8] = 0;
  *(_DWORD *)&XboxCERTKey[12] = 0;
  v4 = 0;
  AniSetLogo(a2, a1, 0, 0);
  AniTerminateAnimation(v5, v6, 0, a3);
  v11 = ErrorCode;
  if ( ExQueryNonVolatileSetting(v8, v7, 0xFFFFu, &SettingType, &EEPROMData, 0x100u, &SettingLength) >= 0 )
  {
    if ( EEPROMData.UEMInfo[0] )
    {
      EEPROMData.UEMInfo[0] = 0;
    }
    else
    {
      if ( (XboxGameRegion & 0x80000000) != 0 )
      {
        EEPROMData.UEMInfo[0] = ErrorCode;
        v4 = (int *)1;
      }
      if ( ErrorCode >= 5 )
      {
        v10 = ErrorCode - 5;
        *(_WORD *)&EEPROMData.UEMInfo[2] |= 1 << (ErrorCode - 5);
      }
    }
    ExSaveNonVolatileSetting(v10, v9, 0xFFFFu, SettingType, &EEPROMData, SettingLength);
    if ( v4 )
      HalWriteSMBusValue(v12, v13, v4, 0xFFFF, 32, 2, 0, 0x40u);
  }
  v14 = InitD3D(0);
  v16 = v14;
  if ( v14 && InitVB(0, v15, v14) && InitTexture(0, (int)v16, v16) )
  {
    D3DDevice_DrawVertices(D3DPT_TRIANGLELIST, 0, 6u);
    D3DDevice_SetVertexShader(0, 0x44u);
    if ( !D3DDevice_SetTextureState_ParameterCheck(0, 0, 0, 3u) )
      D3DDevice_SetTextureState_Deferred(0, 0, 0, 3u);
    ErrorCodea = 0;
    do
    {
      v16 = (D3DDevice *)(80 - ErrorCodea);
      v17 = 0;
      Segment = 0;
      v18 = LEDCharDef[v11 % 0xA];
      v27 = v11 / 0xA;
      v29 = v18;
      do
      {
        v19 = LEDSegmentDef[v17];
        if ( (1 << v17) & v29 )
        {
          D3DDevice_Begin(D3DPT_LINELIST);
          v20 = (int *)v19;
          v21 = 0;
          do
          {
            v31 = (D3DDevice *)(16 * (((unsigned int)v20 >> v21) & 3) + 50);
            v22 = (double)(signed int)v31;
            v31 = &v16[12 * (((unsigned int)v20 >> (v21 + 2)) & 3)];
            b = v22;
            a = (double)(unsigned int)v31;
            D3DDevice_SetVertexData4f(v20, -1, a, b, 0.5, 2.0);
            v21 += 4;
          }
          while ( v21 < 8 );
          D3DDevice_End(v20);
        }
        v17 = Segment++ + 1;
      }
      while ( Segment < 7 );
      ErrorCodea += 25;
      v11 = v27;
    }
    while ( ErrorCodea < 0x32 );
    D3DDevice_Present(0, 0, 0, 0);
    D3DDevice_PersistDisplay(0);
  }
  PsTerminateSystemThread(0, (int)v16, 0);
  JUMPOUT(*(_DWORD *)_L27520);
}