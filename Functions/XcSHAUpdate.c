void __stdcall XcSHAUpdate(char *pbSHAContext, char *pbInput, unsigned int dwInputLength)
{
  updatedCryptoVector.pXcSHAUpdate(pbSHAContext, pbInput, dwInputLength);
}