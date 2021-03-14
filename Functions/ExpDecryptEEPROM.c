int __usercall ExpDecryptEEPROM@<eax>(int a1@<edx>, int a2@<ecx>, _XBOX_ENCRYPTED_SETTINGS *a3@<edi>)
{
  int v3; // eax
  signed int v4; // ecx
  char *v5; // esi
  bool v6; // zf
  unsigned int v7; // eax
  int result; // eax
  char Rc4KeyStruct[258]; // [esp+8h] [ebp-16Ch]
  char Checksum[20]; // [esp+10Ch] [ebp-68h]
  char LocalKey[20]; // [esp+120h] [ebp-54h]
  _XBOX_ENCRYPTED_SETTINGS EncryptedSettings; // [esp+134h] [ebp-40h]
  unsigned int Length; // [esp+164h] [ebp-10h]
  unsigned int Type; // [esp+168h] [ebp-Ch]
  char Confounder[8]; // [esp+16Ch] [ebp-8h]

  v3 = ExQueryNonVolatileSetting(a2, a1, 0xFFFEu, &Type, &EncryptedSettings, 0x30u, &Length);
  if ( v3 < 0 )
    return DbgPrint((int *)a3->Checksum, "INIT: failed to decrypt EEPROM settings (status=%08x).\n", v3);
  if ( *(_QWORD *)EncryptedSettings.Confounder )
  {
    *(_DWORD *)&Confounder[4] = *(_DWORD *)&EncryptedSettings.Confounder[4];
    *(_DWORD *)Confounder = *(_DWORD *)EncryptedSettings.Confounder;
    XcHMAC(XboxEEPROMKey, 0x10u, EncryptedSettings.Checksum, 0x14u, 0, 0, LocalKey);
    XcRC4Key(Rc4KeyStruct, 0x14u, LocalKey);
    XcRC4Crypt(Rc4KeyStruct, 8u, Confounder);
    XcRC4Crypt(Rc4KeyStruct, 0x14u, EncryptedSettings.HDKey);
    XcHMAC(XboxEEPROMKey, 0x10u, Confounder, 8u, EncryptedSettings.HDKey, 0x14u, Checksum);
    v4 = 5;
    a3 = &EncryptedSettings;
    v5 = Checksum;
    v6 = 1;
    do
    {
      if ( !v4 )
        break;
      v6 = *(_DWORD *)v5 == *(_DWORD *)a3->Checksum;
      v5 += 4;
      a3 = (_XBOX_ENCRYPTED_SETTINGS *)((char *)a3 + 4);
      --v4;
    }
    while ( v6 );
    if ( !v6 )
    {
      v3 = -1073741279;
      return DbgPrint((int *)a3->Checksum, "INIT: failed to decrypt EEPROM settings (status=%08x).\n", v3);
    }
  }
  v7 = EncryptedSettings.GameRegion;
  v6 = EncryptedSettings.GameRegion == 0;
  *(_DWORD *)XboxHDKey = *(_DWORD *)EncryptedSettings.HDKey;
  *(_DWORD *)&XboxHDKey[4] = *(_DWORD *)&EncryptedSettings.HDKey[4];
  *(_DWORD *)&XboxHDKey[8] = *(_DWORD *)&EncryptedSettings.HDKey[8];
  *(_DWORD *)&XboxHDKey[12] = *(_DWORD *)&EncryptedSettings.HDKey[12];
  a3 = (_XBOX_ENCRYPTED_SETTINGS *)&XboxHDKey[16];
  XboxGameRegion = v7;
  if ( v6 )
  {
    v7 = 2147483648;
    XboxGameRegion = 2147483648;
  }
  result = v7 & 0x7FFFFFFF;
  if ( (result - 1) & result )
  {
    v3 = -1073414143;
    return DbgPrint((int *)a3->Checksum, "INIT: failed to decrypt EEPROM settings (status=%08x).\n", v3);
  }
  return result;
}