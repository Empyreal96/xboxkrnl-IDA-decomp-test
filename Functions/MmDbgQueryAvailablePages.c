unsigned int __stdcall MmDbgQueryAvailablePages()
{
  return *MmDeveloperKitPteRange.AvailablePages;
}