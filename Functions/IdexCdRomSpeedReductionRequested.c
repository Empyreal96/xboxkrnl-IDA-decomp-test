char __usercall IdexCdRomSpeedReductionRequested@<al>(int *a1@<edi>, int a2@<esi>)
{
  _IO_STACK_LOCATION *v2; // eax
  int v3; // edx
  int v4; // ecx

  if ( !IdexCdRomCurrentSpindleSpeed )
    return 0;
  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v2->MajorFunction != 2 )
    return 0;
  IdexCdRomSpindleSlowdownSectorNumber = v2->Parameters.Read.ByteOffset.LowPart;
  DbgPrint(a1, "IDEX: slowing spindle speed to read sector %08x.\n", IdexCdRomSpindleSlowdownSectorNumber);
  DbgPrint(a1, "IDEX: last successful read was from sector %08x.\n", IdexCdRomDebugLastReadSectorNumber);
  IdexCdRomSetSpindleSpeed(
    v3,
    v4,
    a1,
    a2,
    IdexCdRomCurrentSpindleSpeed - 1,
    (void (__stdcall *)())IdexCdRomFinishSpeedReduction);
  return 1;
}