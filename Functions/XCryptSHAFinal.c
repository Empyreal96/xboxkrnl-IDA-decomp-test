void __stdcall XCryptSHAFinal(char *pbSHAContext, char *pbDigest)
{
  A_SHAFinal((A_SHA_CTX *)pbSHAContext, pbDigest);
}