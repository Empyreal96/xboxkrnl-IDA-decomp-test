void __stdcall XCryptBlockCrypt(unsigned int dwCipher, char *pbOutput, char *pbInput, char *pbKeyTable, unsigned int dwOp)
{
  void (__stdcall *v5)(char *, char *, void *, int); // eax

  v5 = des;
  if ( dwCipher )
    v5 = tripledes;
  v5(pbOutput, pbInput, pbKeyTable, dwOp);
}