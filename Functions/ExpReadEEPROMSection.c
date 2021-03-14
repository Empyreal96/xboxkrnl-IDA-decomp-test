int __userpurge ExpReadEEPROMSection@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, unsigned int Offset, unsigned int Count, void *Buffer, char DoChecksum)
{
  int result; // eax

  if ( !EEPROMShadowIsValid )
  {
    result = ExpReadEEPROMIntoCache(a2, a1);
    if ( result < 0 )
      return result;
    EEPROMShadowIsValid = 1;
  }
  qmemcpy(Buffer, &EEPROMShadow[Offset], Count);
  if ( !DoChecksum || XConfigChecksum(Buffer, Count) == -1 )
    return 0;
  DbgPrint(a3, "Corrupted EEPROM data!!!\n");
  return -1073741668;
}