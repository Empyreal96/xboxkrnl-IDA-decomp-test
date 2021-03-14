void __stdcall KdInitSystem(char InitializingSystem)
{
  unsigned int v1; // eax
  unsigned int v2; // eax
  _STRING NameString; // [esp+4h] [ebp-Ch]
  int Initialize; // [esp+Ch] [ebp-4h]

  if ( !KdDebuggerEnabled )
  {
    KiDebugRoutine = KdpStub;
    if ( InitializingSystem )
    {
      unk_80051560 = osfile;
      v1 = RtlImageNtHeader(osfile)->OptionalHeader.SizeOfImage;
      unk_8005158C = -1;
      unk_80051568 = v1;
      RtlInitUnicodeString(&stru_8005156C, L"xboxkrnl.exe");
      RtlInitUnicodeString(&stru_80051574, L"xboxkrnl.exe");
      unk_8005154C = KdLoadedModuleList.Blink;
      KdpNtosDataTableEntry.InLoadOrderLinks.Flink = &KdLoadedModuleList;
      KdLoadedModuleList.Blink->Flink = (_LIST_ENTRY *)&KdpNtosDataTableEntry;
      KdLoadedModuleList.Blink = (_LIST_ENTRY *)&KdpNtosDataTableEntry;
      InitializeListHead(&KdpDebuggerDataListHead);
      LODWORD(KdDebuggerDataBlock.KernBase) = osfile;
      HIDWORD(KdDebuggerDataBlock.KernBase) = 0;
      KdRegisterDebuggerDataBlock(0x4742444Bu, &KdDebuggerDataBlock.Header, 0x208u);
      HalPulseHardwareMonitorPin();
      LOBYTE(Initialize) = HalInitializeSuperIo();
    }
    else
    {
      LOBYTE(Initialize) = 1;
    }
    if ( KdPhysicalPort->Initialize(Initialize) && (_BYTE)Initialize )
    {
      if ( MEMORY[0xFFF0007B] < 0 )
        KdDebuggerNotPresent = 1;
      KiDebugRoutine = KdpTrap;
      if ( !KdpDebuggerStructuresInitialized )
      {
        KdpBreakpointInstruction = -52;
        KdpOweBreakpoint = 0;
        v2 = 0;
        do
        {
          KdpBreakpointTable[v2 / 2].Flags = 0;
          dword_8005C3B4[v2] = 0;
          v2 += 2;
        }
        while ( v2 < 64 );
        KdpDebuggerStructuresInitialized = 1;
      }
      KdPerformanceCounterRate.QuadPart = KeQueryPerformanceFrequency();
      KdTimerStart.QuadPart = 0i64;
      KdpNextPacketIdToSend = -2139092992;
      KdpPacketIdExpected = -2139095040;
      KdDebuggerEnabled = 1;
      if ( InitializingSystem )
      {
        RtlInitAnsiString(&NameString, "xboxkrnl.exe");
        DbgLoadImageSymbols(&NameString, osfile, 0xFFFFFFFF);
      }
    }
  }
}