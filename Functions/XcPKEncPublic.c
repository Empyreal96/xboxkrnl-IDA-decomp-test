unsigned int __stdcall XcPKEncPublic(char *pbPubKey, char *pbInput, char *pbOutput)
{
  return updatedCryptoVector.pXcPKEncPublic(pbPubKey, pbInput, pbOutput);
}