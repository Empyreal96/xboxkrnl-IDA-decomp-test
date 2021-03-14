char *__userpurge ExpWriteEEPROM@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, unsigned int Offset, unsigned int Count, const void *Buffer)
{
  char *v6; // esi
  unsigned int v7; // ebx
  char *v8; // esi
  unsigned int v9; // ecx
  int *v10; // edi
  unsigned int v11; // ST0C_4
  int v12; // eax
  unsigned int Counta; // [esp+18h] [ebp+Ch]

  v6 = (char *)Buffer;
  if ( Count & 1 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Buffer,
      "Count % EEPROM_RW_BLOCK == 0",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\settings.c",
      0xA7u,
      0);
  v7 = Offset;
  if ( EEPROMShadowIsValid )
  {
    qmemcpy(&EEPROMShadow[Offset], Buffer, 4 * (Count >> 2));
    v8 = (char *)Buffer + 4 * (Count >> 2);
    v9 = Count & 3;
    qmemcpy(&EEPROMShadow[4 * (Count >> 2) + Offset], v8, v9);
    v6 = &v8[v9];
    a2 = 0;
  }
  Counta = Offset + Count;
  if ( Offset >= Counta )
    return 0;
  v10 = (int *)Buffer;
  while ( 1 )
  {
    v11 = *(unsigned __int16 *)v10;
    v10 = (int *)((char *)v10 + 2);
    v12 = HalWriteSMBusValue(a1, a2, v10, (int)v6, 168, v7, 1, v11);
    v6 = (char *)v12;
    if ( v12 < 0 )
      break;
    v7 += 2;
    if ( v7 >= Counta )
      return 0;
  }
  DbgPrint(v10, "EX: failed to write EEPROM offset %02x, status=%08x\n", v7, v12);
  EEPROMShadowIsValid = 0;
  return v6;
}