bool __stdcall XCVerifyDigest(char *pbSig, char *pbPublicKey, char *pbWorkspace, char *pbCompareDigest)
{
  int v4; // ecx
  int v5; // edx
  bool result; // al

  v4 = *((_DWORD *)pbPublicKey + 1);
  v5 = *((_DWORD *)pbPublicKey + 2);
  memset(&pbWorkspace[v4], 0, *((_DWORD *)pbPublicKey + 1));
  qmemcpy(&pbWorkspace[v4], pbSig, (unsigned int)(v5 + 7) >> 3);
  if ( BSafeEncPublic((BSAFE_PUB_KEY *const )pbPublicKey, &pbWorkspace[v4], pbWorkspace) )
    result = XCVerifyPKCS1SigningFmt((BSAFE_PUB_KEY *)pbPublicKey, pbCompareDigest, pbWorkspace) != 0;
  else
    result = 0;
  return result;
}