unsigned int __stdcall XCCalcKeyLen(char *pbPubKey)
{
  return *((_DWORD *)pbPubKey + 1);
}