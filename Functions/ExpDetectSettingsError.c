signed int __usercall ExpDetectSettingsError@<eax>(int *a1@<edi>)
{
  signed int v1; // esi
  int v2; // edx
  int v3; // ecx
  char v4; // al
  _XBOX_USER_SETTINGS userSettings; // [esp+4h] [ebp-70h]
  _LARGE_INTEGER time; // [esp+64h] [ebp-10h]
  unsigned int type; // [esp+6Ch] [ebp-8h]
  unsigned int length; // [esp+70h] [ebp-4h]

  v1 = 0;
  HalIsCmosValid();
  if ( !v4 )
    goto LABEL_5;
  KeQuerySystemTime(&time);
  if ( time.QuadPart < 126227808000000000i64 || time.QuadPart > 157784544000000000i64 )
  {
    DbgPrint(a1, "Bad real-time clock value: %08x%08x\n", time.HighPart, time.LowPart);
LABEL_5:
    v1 = 1;
  }
  if ( ExQueryNonVolatileSetting(v3, v2, 0xFFu, &type, &userSettings, 0x60u, &length) < 0 )
  {
    v1 |= 6u;
  }
  else
  {
    if ( !userSettings.Language )
      v1 |= 4u;
    if ( !userSettings.TimeZoneStdName[0] )
      v1 |= 2u;
  }
  if ( v1 )
    DbgPrint(a1, "INIT: invalid clock/timezone/language settings - %x\n", v1);
  return v1;
}