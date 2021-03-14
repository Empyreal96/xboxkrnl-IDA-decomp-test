void __stdcall KiVerifyDataSectionDigest()
{
  char DataSectionDigest[20]; // [esp+8h] [ebp-14h]

  XCCalcDigest(*(char **)&word_80010028[6], *(unsigned int *)&word_80010028[2], DataSectionDigest);
  if ( KeHasQuickBooted )
  {
    if ( memcmp(KiDataSectionDigest, DataSectionDigest, 0x14u) )
      HalHaltSystem();
  }
  else
  {
    qmemcpy(KiDataSectionDigest, DataSectionDigest, 0x14u);
  }
}