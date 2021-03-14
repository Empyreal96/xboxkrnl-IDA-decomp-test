void __stdcall IdexCdRomDecryptHostChallengeResponseTable(_DVDX2_CONTROL_DATA *ControlData)
{
  RC4_KEYSTRUCT RC4KeyStruct; // [esp+4h] [ebp-18Ch]
  A_SHA_CTX SHAHash; // [esp+108h] [ebp-88h]
  char SHADigest[20]; // [esp+17Ch] [ebp-14h]

  A_SHAInit(&SHAHash);
  A_SHAUpdate(&SHAHash, (char *)&ControlData->AuthoringTimeStamp, 0x2Cu);
  A_SHAFinal(&SHAHash, SHADigest);
  rc4_key((int)&RC4KeyStruct, 7u, SHADigest);
  rc4((int)&RC4KeyStruct, 0xFDu, ControlData->HostChallengeResponseTable.Entries);
}