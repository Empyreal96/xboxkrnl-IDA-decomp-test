void __stdcall XepExtractCertificateKeys()
{
  int v0; // esi
  char *v1; // edi
  char *v2; // esi
  signed int v3; // ebx

  v0 = MEMORY[0x10118];
  XepExtractCertificateKey((char *)(MEMORY[0x10118] + 176), XboxLANKey);
  XepExtractCertificateKey((char *)(v0 + 192), XboxSignatureKey);
  v1 = XboxAlternateSignatureKeys;
  v2 = (char *)(v0 + 208);
  v3 = 16;
  do
  {
    XepExtractCertificateKey(v2, v1);
    v1 += 16;
    v2 += 16;
    --v3;
  }
  while ( v3 );
}