int __fastcall FscSetCacheSize(int a1, int a2, unsigned int NumberOfCachePages)
{
  int v3; // edx
  signed int v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  char OldIrql; // [esp+Fh] [ebp-1h]

  KeWaitForSingleObject(a1, a2, &FscSetCacheSizeEvent, 0, 0, 0, 0);
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( NumberOfCachePages <= 0x800 )
  {
    if ( NumberOfCachePages <= FscNumberOfCachePages )
    {
      if ( NumberOfCachePages >= FscNumberOfCachePages )
      {
        v4 = 0;
        goto LABEL_9;
      }
      v5 = FscShrinkCacheSize(v3, NumberOfCachePages, 0, (int)&FscSetCacheSizeEvent, NumberOfCachePages);
    }
    else
    {
      v5 = FscGrowCacheSize(v3, NumberOfCachePages, 0, (int)&FscSetCacheSizeEvent, NumberOfCachePages);
    }
    v4 = v5;
  }
  else
  {
    v4 = -1073741811;
  }
LABEL_9:
  KfLowerIrql(OldIrql);
  KeSetEvent(v7, v6, &FscSetCacheSizeEvent, 0, 0);
  return v4;
}