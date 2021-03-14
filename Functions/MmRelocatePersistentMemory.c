void __usercall MmRelocatePersistentMemory(int a1@<edx>, int *a2@<edi>)
{
  _LAUNCH_DATA_PAGE *v2; // esi
  unsigned int v3; // eax
  int v4; // edx
  int v5; // ecx
  int *v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // ecx
  void *v10; // eax
  int v11; // edx
  void *v12; // esi
  unsigned int v13; // ebx
  int v14; // edx
  signed int v15; // esi
  unsigned int v16; // eax
  void *v17; // eax
  int v18; // ecx
  void *v19; // eax
  int v20; // edx
  int v21; // ecx
  _LAUNCH_DATA_PAGE *OldLaunchDataPage; // [esp+Ch] [ebp-8h]
  _LAUNCH_DATA_PAGE *NewLaunchDataPage; // [esp+10h] [ebp-4h]

  v2 = LaunchDataPage;
  OldLaunchDataPage = LaunchDataPage;
  if ( LaunchDataPage )
  {
    v3 = MmGetPhysicalAddress(a1, a2, osfile);
    v6 = (int *)MmAllocateContiguousMemoryEx(v4, v5, (int)v2, 0x1000u, 0, v3 - 1, 0, 4u);
    NewLaunchDataPage = (_LAUNCH_DATA_PAGE *)v6;
    if ( v6 )
    {
      qmemcpy(v6, v2, 0x1000u);
      a2 = v6 + 1024;
      MmPersistContiguousMemory(v7, 0, (int)&v2[1], v6, 0x1000u, 1);
      LaunchDataPage = NewLaunchDataPage;
      MmFreeContiguousMemory(v8, v9, a2, OldLaunchDataPage);
    }
    else
    {
      DbgPrint(a2, "MM: cannot relocate launch data page\n");
    }
  }
  v10 = AvGetSavedDataAddress();
  v12 = v10;
  if ( v10 )
  {
    v13 = MmGetPhysicalAddress(v11, a2, v10);
    if ( v13 != MmTopOfKernelPhysicalAddress )
    {
      v15 = MmQueryAllocationSize(v12);
      v16 = MmTopOfKernelPhysicalAddress;
      if ( v13 < MmTopOfKernelPhysicalAddress + v15 )
      {
        v17 = (void *)MmAllocateContiguousMemoryEx(
                        v14,
                        MmTopOfKernelPhysicalAddress + v15,
                        v15,
                        v15,
                        MmTopOfKernelPhysicalAddress,
                        0xFFFFFFFF,
                        0,
                        0x404u);
        if ( v17 )
          AvRelocateSavedDataAddress(v14, v18, (int *)0x404, v15, v17, v15);
        v16 = MmTopOfKernelPhysicalAddress;
      }
      v19 = (void *)MmAllocateContiguousMemoryEx(v14, v16 + v15 - 1, v15, v15, v16, v16 + v15 - 1, 0, 0x404u);
      if ( v19 )
        AvRelocateSavedDataAddress(v20, v21, (int *)0x404, v15, v19, v15);
      else
        DbgPrint((int *)0x404, "MM: cannot relocate persist display surface\n");
    }
  }
}