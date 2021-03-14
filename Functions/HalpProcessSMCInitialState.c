int __usercall HalpProcessSMCInitialState@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  int v3; // edx
  int v4; // ecx
  int *v5; // edi
  signed int v6; // ebx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  char v14; // bl
  int result; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  unsigned int FirmwareRevision[3]; // [esp+8h] [ebp-14h]
  unsigned int InterruptReason; // [esp+14h] [ebp-8h]
  char TrayEjectPending; // [esp+1Bh] [ebp-1h]

  TrayEjectPending = 0;
  if ( HalReadSMBusValue(a1, a2, a3, 32, 32, 4, 0, &InterruptReason) >= 0 )
    HalBootSMCVideoMode = InterruptReason & 7;
  v5 = (int *)FirmwareRevision;
  v6 = 3;
  do
  {
    HalReadSMBusValue(v3, v4, v5, 32, 32, 1, 0, (unsigned int *)v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  DbgPrint(v5, "HAL: SMC version %c%c%c\n", FirmwareRevision[0], FirmwareRevision[1], FirmwareRevision[2]);
  if ( HalReadSMBusValue(v7, v8, 0, 32, 32, 17, 0, &InterruptReason) >= 0 )
  {
    if ( InterruptReason & 0x20 )
      TrayEjectPending = 1;
    if ( InterruptReason & 4 || InterruptReason & 0x20 )
      HalWriteSMBusValue(v9, v10, 0, 32, 32, 13, 0, 4u);
  }
  v11 = HalReadSMBusValue(v9, v10, 0, 32, 32, 27, 0, &InterruptReason);
  v14 = InterruptReason;
  if ( v11 >= 0 && InterruptReason & 1 )
    TrayEjectPending = 1;
  result = HalWriteSMCScratchRegister(v12, v13, 0, 32, 4u);
  if ( v14 & 4 )
    XboxBootFlags |= 0x10u;
  if ( v14 & 2 )
    XboxBootFlags |= 0x20u;
  if ( v14 & 8 )
    LOBYTE(XboxBootFlags) = XboxBootFlags | 0x80;
  if ( TrayEjectPending )
  {
    XboxBootFlags |= 0x48u;
    HalWriteSMBusValue(v16, v17, 0, 32, 32, 25, 0, 1u);
    result = HalWriteSMBusValue(v18, v19, 0, 32, 32, 12, 0, 0);
    HalpTrayState = 32;
  }
  return result;
}