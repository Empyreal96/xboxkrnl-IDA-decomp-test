// local variable allocation has failed, the output may be wrong!
int *__userpurge IdexChannelIdentifyDevice@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, char TargetDevice, char IdentifyCommand, _IDE_IDENTIFY_DATA *IdentifyData)
{
  int v7; // edx
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  int v10; // edx
  int v11; // ecx
  int *v12; // esi

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x62Eu,
      0);
  KfRaiseIrql(NewIrql);
  __outbyte(0x1F6u, 16 * (TargetDevice | 0xFA));
  __outbyte(0x1F4u, 0x5Au);
  __outbyte(0x1F5u, 0xA5u);
  v8 = __inbyte(0x1F4u);
  if ( v8 != 90 || (LOWORD(v7) = 501, v9 = __inbyte(0x1F5u), v9 != -91) )
  {
    v12 = (int *)-1073741632;
    goto LABEL_10;
  }
  if ( !IdexChannelSpinWhileBusy(&TargetDevice + 3, v7, a3) )
  {
    v12 = (int *)-1073741643;
LABEL_10:
    KfLowerIrql(0);
    return v12;
  }
  LOWORD(v10) = 503;
  __outbyte(0x1F7u, IdentifyCommand);
  v12 = IdexChannelBlockOnInitCommand(v11, v10);
  if ( (signed int)v12 >= 0 )
    READ_PORT_BUFFER_ULONG((PULONG)0x1F0, (PULONG)&IdentifyData->GeneralConfiguration, 0x80u);
  return v12;
}