int __fastcall ExpReadEEPROMIntoCache(int a1, int a2)
{
  unsigned int v2; // esi
  int v3; // eax
  int v4; // ebx
  unsigned int v5; // eax
  unsigned int val; // [esp+Ch] [ebp-4h]

  v2 = 0;
  do
  {
    v3 = HalReadSMBusValue(a2, a1, (int *)0x100, v2, 169, v2, 1, &val);
    v4 = v3;
    if ( v3 < 0 )
    {
      DbgPrint((int *)0x100, "EX: failed to read EEPROM offset %02x, status=%08x\n", v2, v3);
      return v4;
    }
    *(_WORD *)&EEPROMShadow[v2] = val;
    v2 += 2;
  }
  while ( v2 < 0x100 );
  v5 = 0;
  while ( *(_WORD *)&EEPROMShadow[v5] == -1 )
  {
    v5 += 2;
    if ( v5 >= 0x100 )
    {
      DbgPrint((int *)0x100, "Uninitialized EEPROM data!!!\n");
      return -1073741436;
    }
  }
  return 0;
}