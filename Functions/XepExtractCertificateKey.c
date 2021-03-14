void __stdcall XepExtractCertificateKey(char *InputKey, char *OutputKey)
{
  char Digest[20]; // [esp+8h] [ebp-14h]

  XcHMAC(XboxCERTKey, 0x10u, InputKey, 0x10u, 0, 0, Digest);
  *(_DWORD *)OutputKey = *(_DWORD *)Digest;
  *((_DWORD *)OutputKey + 1) = *(_DWORD *)&Digest[4];
  *((_DWORD *)OutputKey + 2) = *(_DWORD *)&Digest[8];
  *((_DWORD *)OutputKey + 3) = *(_DWORD *)&Digest[12];
}