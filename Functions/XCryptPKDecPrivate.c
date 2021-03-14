int __stdcall XCryptPKDecPrivate(char *pbPrvKey, char *pbInput, char *pbOutput)
{
  return BSafeDecPrivate((BSAFE_PRV_KEY *const )pbPrvKey, pbInput, pbOutput);
}