bool __stdcall XCryptVerifyPKCS1Signature(char *pbSig, char *pbPubKey, char *pbDigest)
{
  void *v3; // esp
  bool result; // al
  int v5; // [esp+0h] [ebp-4h]

  v3 = alloca(2 * *((_DWORD *)pbPubKey + 1));
  if ( &v5 )
    result = XCVerifyDigest(pbSig, pbPubKey, (char *)&v5, pbDigest);
  else
    result = 0;
  return result;
}