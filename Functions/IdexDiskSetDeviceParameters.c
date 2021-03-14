int *__usercall IdexDiskSetDeviceParameters@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  int v4; // edx
  int v5; // edx
  int v6; // ecx
  int *result; // eax
  int v8; // [esp-2h] [ebp-4h]

  v8 = a2;
  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x7CCu,
      0);
  KfRaiseIrql(NewIrql);
  LOWORD(v4) = 502;
  __outbyte(0x1F6u, 0xA0u);
  if ( IdexChannelSpinWhileBusy((char *)&v8 + 3, v4, a3) )
  {
    __outbyte(0x1F6u, 0xAFu);
    __outbyte(0x1F2u, 0x3Fu);
    LOWORD(v5) = 503;
    __outbyte(0x1F7u, 0x91u);
    result = IdexChannelBlockOnInitCommand(v6, v5);
  }
  else
  {
    KfLowerIrql(0);
    result = (int *)-1073741643;
  }
  return result;
}