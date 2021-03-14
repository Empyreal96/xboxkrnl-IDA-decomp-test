void __stdcall XcKeyTable(unsigned int dwCipher, char *pbKeyTable, char *pbKey)
{
  updatedCryptoVector.pXcKeyTable(dwCipher, pbKeyTable, pbKey);
}