void __stdcall XCryptHMAC(char *pbKeyMaterial, unsigned int cbKeyMaterial, char *pbData, unsigned int cbData, char *pbData2, unsigned int cbData2, char *HmacData)
{
  signed int v7; // edx
  unsigned int v8; // eax
  char HMACTmp[84]; // [esp+0h] [ebp-148h]
  A_SHA_CTX shaHash; // [esp+54h] [ebp-F4h]
  char Kipad[64]; // [esp+C8h] [ebp-80h]
  char Kopad[64]; // [esp+108h] [ebp-40h]

  v7 = cbKeyMaterial;
  if ( cbKeyMaterial > 0x40 )
    v7 = 64;
  memset(Kipad, 0, sizeof(Kipad));
  qmemcpy(Kipad, pbKeyMaterial, v7);
  memset(Kopad, 0, sizeof(Kopad));
  qmemcpy(Kopad, pbKeyMaterial, v7);
  v8 = 0;
  do
  {
    *(_DWORD *)&Kipad[v8] ^= 0x36363636u;
    *(_DWORD *)&Kopad[v8] ^= 0x5C5C5C5Cu;
    v8 += 4;
  }
  while ( v8 < 0x40 );
  A_SHAInit(&shaHash);
  A_SHAUpdate(&shaHash, Kipad, 0x40u);
  if ( cbData )
    A_SHAUpdate(&shaHash, pbData, cbData);
  if ( cbData2 )
    A_SHAUpdate(&shaHash, pbData2, cbData2);
  A_SHAFinal(&shaHash, &HMACTmp[64]);
  qmemcpy(HMACTmp, Kopad, 0x40u);
  A_SHAInit(&shaHash);
  A_SHAUpdate(&shaHash, HMACTmp, 0x54u);
  A_SHAFinal(&shaHash, HmacData);
}