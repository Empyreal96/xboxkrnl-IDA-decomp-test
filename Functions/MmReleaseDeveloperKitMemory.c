void __stdcall MmReleaseDeveloperKitMemory()
{
  KIRQL v0; // al

  v0 = KeRaiseIrqlToDpcLevel();
  MmAvailablePages += MmDeveloperKitPfnRegion.AvailablePages;
  MmDeveloperKitMemoryReleased = 1;
  KfLowerIrql(v0);
}