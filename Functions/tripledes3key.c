void __stdcall tripledes3key(_DES3TABLE *pDES3Table, char *pbKey)
{
  deskey(&pDES3Table->keytab1, pbKey);
  deskey(&pDES3Table->keytab2, pbKey + 8);
  deskey(&pDES3Table->keytab3, pbKey + 16);
}