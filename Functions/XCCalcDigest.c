void __stdcall XCCalcDigest(char *pbMsgData, unsigned int dwMsgDataLen, char *pbDigest)
{
  A_SHA_CTX SHAHash; // [esp+8h] [ebp-88h]
  char abSHADigest[20]; // [esp+7Ch] [ebp-14h]

  A_SHAInit(&SHAHash);
  A_SHAUpdate(&SHAHash, (char *)&dwMsgDataLen, 4u);
  A_SHAUpdate(&SHAHash, pbMsgData, dwMsgDataLen);
  A_SHAFinal(&SHAHash, abSHADigest);
  qmemcpy(pbDigest, abSHADigest, 0x14u);
}