int *__usercall ExpCopyLastUEMError@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  int *result; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  _EEPROM_LAYOUT EEPROMData; // [esp+4h] [ebp-108h]
  unsigned int SettingLength; // [esp+104h] [ebp-8h]
  unsigned int SettingType; // [esp+108h] [ebp-4h]

  result = (int *)ExQueryNonVolatileSetting(a2, a1, 0xFFFFu, &SettingType, &EEPROMData, 0x100u, &SettingLength);
  if ( (signed int)result >= 0 )
  {
    if ( EEPROMData.UEMInfo[0] )
    {
      HalWriteSMBusValue(v4, v5, a3, 0xFFFF, 32, 14, 0, (unsigned __int8)EEPROMData.UEMInfo[0]);
      EEPROMData.UEMInfo[0] = 0;
      result = ExSaveNonVolatileSetting(v7, v6, 0xFFFFu, SettingType, &EEPROMData, SettingLength);
    }
  }
  return result;
}