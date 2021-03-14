void __stdcall XCryptBlockCryptCBC(unsigned int dwCipher, unsigned int dwInputLength, char *pbOutput, char *pbInput, char *pbKeyTable, unsigned int dwOp, char *pbFeedback)
{
  char *v7; // esi
  void (__stdcall *v8)(char *, char *, void *, int); // ebx

  v7 = pbInput;
  v8 = des;
  if ( dwCipher )
    v8 = tripledes;
  while ( v7 < &pbInput[dwInputLength] )
  {
    CBC(v8, 8u, pbOutput, v7, pbKeyTable, dwOp, pbFeedback);
    v7 += 8;
    pbOutput += 8;
  }
}