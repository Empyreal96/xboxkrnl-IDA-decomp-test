int __stdcall XCVerifyPKCS1SigningFmt(BSAFE_PUB_KEY *pKey, char *pbDigest, char *pbPKCS1Format)
{
  unsigned int v3; // ecx
  char *v4; // eax
  char *v5; // ebx
  char *v6; // eax
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  char rgbTmpHash[36]; // [esp+0h] [ebp-24h]
  char **pbDigesta; // [esp+30h] [ebp+Ch]
  unsigned int cb; // [esp+34h] [ebp+10h]

  v3 = 0;
  v4 = pbDigest + 19;
  do
    rgbTmpHash[v3++] = *v4--;
  while ( v3 < 0x14 );
  v5 = pbPKCS1Format;
  if ( memcmp(rgbTmpHash, pbPKCS1Format, 0x14u) )
    return 0;
  v6 = shaEncodings[0];
  cb = 20;
  if ( *shaEncodings[0] )
  {
    pbDigesta = shaEncodings;
    while ( 1 )
    {
      v7 = (unsigned __int8)*v6;
      if ( !memcmp(v5 + 20, v6 + 1, v7) )
        break;
      ++pbDigesta;
      v6 = *pbDigesta;
      if ( !**pbDigesta )
        goto LABEL_10;
    }
    cb = v7 + 20;
  }
LABEL_10:
  if ( v5[cb] )
    return 0;
  v8 = pKey->datalen;
  if ( v5[v8] || v5[v8 - 1] != 1 )
    return 0;
  v9 = cb + 1;
  v10 = v8 - 1;
  while ( v9 < v10 )
  {
    if ( v5[v9] != -1 )
      return 0;
    ++v9;
  }
  return 1;
}