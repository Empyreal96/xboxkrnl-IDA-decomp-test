void __stdcall XcHMAC(char *pbKeyMaterial, unsigned int cbKeyMaterial, char *pbData, unsigned int cbData, char *pbData2, unsigned int cbData2, char *pbDigest)
{
  updatedCryptoVector.pXcHMAC(pbKeyMaterial, cbKeyMaterial, pbData, cbData, pbData2, cbData2, pbDigest);
}