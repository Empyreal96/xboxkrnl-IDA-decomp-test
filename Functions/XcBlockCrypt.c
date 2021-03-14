void __stdcall XcBlockCrypt(unsigned int dwCipher, char *pbOutput, char *pbInput, char *pbKeyTable, unsigned int dwOp)
{
  updatedCryptoVector.pXcBlockCrypt(dwCipher, pbOutput, pbInput, pbKeyTable, dwOp);
}