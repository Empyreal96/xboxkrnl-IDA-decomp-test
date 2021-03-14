int __stdcall XCryptPKEncPublic(char *pbPubKey, char *pbInput, char *pbOutput)
{
  return BSafeEncPublic((BSAFE_PUB_KEY *const )pbPubKey, pbInput, pbOutput);
}