void __cdecl __noreturn main(char *LoadOptions, const char *CryptKeys)
{
  char buf[64]; // [esp+0h] [ebp-40h]

  strncpy(buf, LoadOptions, 0x40u);
  buf[63] = 0;
  _strupr(buf);
  if ( strstr(buf, "SHADOW") )
    XboxBootFlags |= 1u;
  if ( strstr(buf, "/HDBOOT") )
    XboxBootFlags |= 2u;
  if ( strstr(buf, "/CDBOOT") )
    XboxBootFlags |= 4u;
  if ( strstr(buf, "/DBBOOT") )
    LOBYTE(XboxBootFlags) = XboxBootFlags | 0x80;
  *(_DWORD *)XboxEEPROMKey = *(_DWORD *)CryptKeys;
  *(_DWORD *)&XboxEEPROMKey[4] = *((_DWORD *)CryptKeys + 1);
  *(_DWORD *)&XboxEEPROMKey[8] = *((_DWORD *)CryptKeys + 2);
  *(_DWORD *)&XboxEEPROMKey[12] = *((_DWORD *)CryptKeys + 3);
  *(_DWORD *)XboxCERTKey = *((_DWORD *)CryptKeys + 4);
  *(_DWORD *)&XboxCERTKey[4] = *((_DWORD *)CryptKeys + 5);
  *(_DWORD *)&XboxCERTKey[8] = *((_DWORD *)CryptKeys + 6);
  *(_DWORD *)&XboxCERTKey[12] = *((_DWORD *)CryptKeys + 7);
  memset((void *)0x80400000, 0, 0x6000u);
  KiSystemStartup();
}