void __stdcall XCryptRC4Crypt(char *pbKeyStruct, unsigned int dwInputLength, char *pbInput)
{
  rc4((int)pbKeyStruct, dwInputLength, pbInput);
}