void __usercall IdexChannelCreate(int *a1@<edi>, int a2@<esi>)
{
  void *v2; // ecx
  unsigned int v3; // eax
  int v4; // edx
  int v5; // edx
  int v6; // ecx

  dword_80051350 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))IdexChannelStartPacketStock;
  dword_80051354 = (int (*)(void))IdexChannelStartNextPacketStock;
  KeInitializeDeviceQueue(&DeviceQueue);
  KeInitializeDpc(&stru_80051374, IdexChannelTimer, 0);
  KeInitializeTimerEx(&Timer, SynchronizationTimer);
  IdexChannelSetTimerPeriod(v2, 1000);
  KeInitializeDpc(&Dpc, IdexChannelDpcForIsr, 0);
  __outbyte(0x3F6u, 0);
  v3 = HalGetInterruptVector(0xEu, &NewIrql);
  KeInitializeInterrupt(v4, (unsigned __int8)NewIrql, a1, &Interrupt, IdexChannelInterrupt, 0, v3, NewIrql, Latched, 0);
  if ( !KeConnectInterrupt(&Interrupt) )
    IdexBugCheckWorker(0x20731u, 0xC0000001);
  if ( ((unsigned int)IdexChannelPhysicalRegionDescriptorTable ^ (unsigned int)&unk_8004BA48) & 0xFFFF0000 )
    RtlAssert(
      v5,
      v6,
      a1,
      (int)IdexChannelPhysicalRegionDescriptorTable,
      "((ULONG_PTR)PhysicalRegionDescriptor >> 16) == (ULONG_PTR)EndingPhysicalRegionDescriptor >> 16",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x73Eu,
      0);
  unk_80051370 = MmGetPhysicalAddress(v5, a1, IdexChannelPhysicalRegionDescriptorTable);
  if ( KeHasQuickBooted )
  {
    IdexDiskCreateQuick(a1);
    IdexCdRomCreateQuick(a1);
  }
  else
  {
    IdexDiskCreate((_LARGE_INTEGER *)a1);
    IdexCdRomCreate(a1, a2);
  }
}