void __userpurge XeLoadDashboardImageWithReason(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, unsigned int Reason, unsigned int Parameter1)
{
  _LAUNCH_DATA_PAGE *v5; // eax
  _DWORD *v6; // eax

  v5 = LaunchDataPage;
  if ( LaunchDataPage
    || (v5 = (_LAUNCH_DATA_PAGE *)MmAllocateContiguousMemory(a1, a2, 4096, 0x1000u), (LaunchDataPage = v5) != 0) )
  {
    MmPersistContiguousMemory(a1, a2, 4096, v5, 0x1000u, 1);
    memset(LaunchDataPage, 0, sizeof(_LAUNCH_DATA_PAGE));
    LaunchDataPage->Header.dwLaunchDataType = 1;
    v6 = LaunchDataPage->LaunchData;
    *v6 = Reason;
    v6[2] = Parameter1;
  }
  XeLoadDashboardImage(a3, 4096);
}