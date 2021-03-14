void __stdcall XcBlockCryptCBC(unsigned int dwCipher, unsigned int dwInputLength, char *pbOutput, char *pbInput, char *pbKeyTable, unsigned int dwOp, char *pbFeedback)
{
  updatedCryptoVector.pXcBlockCryptCBC(dwCipher, dwInputLength, pbOutput, pbInput, pbKeyTable, dwOp, pbFeedback);
}