unsigned int __stdcall XcCryptService(unsigned int dwOp, void *pArgs)
{
  return updatedCryptoVector.pXcCryptService(dwOp, pArgs);
}