int __usercall IdexCdRomTrayOpenNotification@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  int result; // eax

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0xF92u,
      0);
  LODWORD(IdexCdRomPartitionLength) = -1;
  IdexCdRomDebugReadsFinished = 0;
  result = 0;
  IdexCdRomDebugErrors[0] = 0;
  IdexCdRomDebugErrors[1] = 0;
  HIDWORD(IdexCdRomPartitionLength) = 0x7FFFFFFF;
  IdexCdRomDVDX2Authenticated = 0;
  return result;
}