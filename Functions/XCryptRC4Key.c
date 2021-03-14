void __stdcall XCryptRC4Key(char *pbKeyStruct, unsigned int dwKeyLength, char *pbKey)
{
  rc4_key((int)pbKeyStruct, dwKeyLength, pbKey);
}