unsigned int __stdcall XcPKDecPrivate(char *pbPrvKey, char *pbInput, char *pbOutput)
{
  return updatedCryptoVector.pXcPKDecPrivate(pbPrvKey, pbInput, pbOutput);
}