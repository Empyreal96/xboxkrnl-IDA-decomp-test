char __stdcall XcVerifyPKCS1Signature(char *pbSig, char *pbPubKey, char *pbDigest)
{
  return updatedCryptoVector.pXcVerifyPKCS1Signature(pbSig, pbPubKey, pbDigest);
}