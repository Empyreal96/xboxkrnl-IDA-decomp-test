void __stdcall XCryptSHAInit(char *pbSHAContext)
{
  A_SHAInit((A_SHA_CTX *)pbSHAContext);
}