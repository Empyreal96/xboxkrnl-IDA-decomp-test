void __stdcall XCryptKeyTable(unsigned int dwCipher, char *pbKeyTable, char *pbKey)
{
  if ( dwCipher )
    tripledes3key((_DES3TABLE *)pbKeyTable, pbKey);
  else
    deskey((_destable *)pbKeyTable, pbKey);
}