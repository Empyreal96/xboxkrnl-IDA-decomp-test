void __stdcall XCryptDESKeyParity(char *pbKey, unsigned int dwKeyLength)
{
  desparityonkey(pbKey, dwKeyLength);
}