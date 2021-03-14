void __stdcall XCryptSHAUpdate(char *pbSHAContext, char *pbInput, unsigned int dwInputLength)
{
  A_SHAUpdate((A_SHA_CTX *)pbSHAContext, pbInput, dwInputLength);
}