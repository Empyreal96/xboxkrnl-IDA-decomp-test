void __userpurge IdexCdRomSetSpindleSpeed(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, unsigned int SpindleSpeedControl, void (__stdcall *FinishIoRoutine)())
{
  int v6; // edx
  _CDB Cdb; // [esp+8h] [ebp-10h]
  int savedregs; // [esp+18h] [ebp+0h]

  if ( SpindleSpeedControl > IdexCdRomMaximumSpindleSpeed )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "SpindleSpeedControl <= IdexCdRomMaximumSpindleSpeed",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x297u,
      0);
  DbgPrint(a3, "IDEX: setting spindle speed to %d.\n", SpindleSpeedControl);
  IdexCdRomSpindleSlowdownSectorsRemaining = *(_DWORD *)(4 * SpindleSpeedControl - 2147392740);
  IdexCdRomStaticTransferBuffer = 0;
  *(&IdexCdRomStaticTransferBuffer + 1) = 0;
  *(&IdexCdRomStaticTransferBuffer + 2) = 0;
  *(&IdexCdRomStaticTransferBuffer + 3) = 0;
  *(&IdexCdRomStaticTransferBuffer + 4) = 0;
  byte_80051308 = byte_80051308 & 0xE0 | 0x20;
  *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
  *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
  Cdb.CDB10.LogicalBlock = 32;
  IdexCdRomCurrentSpindleSpeed = SpindleSpeedControl;
  LOWORD(IdexCdRomStaticTransferBuffer) = 4608;
  byte_80051309 = 10;
  byte_8005130A = SpindleSpeedControl;
  Cdb.CDB6GENERIC.OperationCode = 85;
  *(_WORD *)((char *)&Cdb.CDB6VERIFY + 7) = 5120;
  IdexCdRomIssueAtapiRequest(
    v6,
    (int)&IdexCdRomStaticTransferBuffer,
    &savedregs,
    &Cdb,
    &IdexCdRomStaticTransferBuffer,
    0x14u,
    1,
    FinishIoRoutine);
}