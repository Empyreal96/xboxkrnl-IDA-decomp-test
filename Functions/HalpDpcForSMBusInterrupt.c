void __userpurge HalpDpcForSMBusInterrupt(__int16 a1@<dx>, int *a2@<edi>, int a3@<esi>, _KDPC *Dpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  signed __int16 v10; // dx
  unsigned __int16 v11; // ax
  unsigned int v12; // esi
  unsigned __int8 v13; // al
  int v14; // esi
  unsigned __int8 v15; // al
  int v16; // esi
  unsigned __int8 v17; // al
  int v18; // esi
  unsigned __int8 v19; // al
  int v20; // ST0C_4
  int v21; // [esp-4h] [ebp-8h]

  if ( (unsigned __int8)SystemArgument1 & 6 )
  {
    if ( HalpSMBusRetries > 0 )
    {
      KeSetTimer(-1, a1, &HalpSMBusRetryTimer, (_LARGE_INTEGER)-20000i64, &HalpSMBusRetryDpc);
      --HalpSMBusRetries;
      return;
    }
    DbgPrint(a2, "HAL: exceeded retry count for SMBus transaction.\n");
  }
  if ( (unsigned __int8)SystemArgument1 & 0x10 )
  {
    v7 = 0;
  }
  else if ( (unsigned __int8)SystemArgument1 & 0x20 )
  {
    DbgPrint(a2, "HAL: SMBus transaction timed out.\n");
    v7 = -1073741643;
  }
  else
  {
    DbgPrint(a2, "HAL: SMBus transaction errored out.\n");
    v7 = -1073741435;
  }
  if ( HalpSMBusCompletionRoutine )
  {
    if ( HalpSMBusCompletionRoutine(v7) )
      return;
    HalpSMBusCompletionRoutine = 0;
  }
  else if ( HalpSMBusStatusBlock )
  {
    v10 = -16378;
    v11 = __inword(0xC006u);
    v21 = a3;
    v12 = v11;
    if ( v7 >= 0 && !HalpSMBusWriteTransaction && HalpSMBusNumberOfBytes == 4 )
    {
      if ( (v11 & 0x3F) == 4 )
      {
        v10 = -16375;
        v13 = __inbyte(0xC009u);
        v14 = v13;
        v15 = __inbyte(0xC009u);
        v16 = (v15 << 8) + v14;
        v17 = __inbyte(0xC009u);
        v18 = (v17 << 16) + v16;
        v19 = __inbyte(0xC009u);
        v12 = (v19 << 24) + v18;
      }
      else
      {
        DbgPrint(a2, "HAL: SMBus block read returned wrong number of bytes.\n");
        v7 = -1073741435;
      }
    }
    HalpSMBusStatusBlock->Status = v7;
    HalpSMBusStatusBlock->DataValue = v12;
    KeSetEvent(v7, v10, &HalpSMBusStatusBlock->CompletionEvent, 0, 0);
    HalpSMBusStatusBlock = 0;
    a3 = v21;
  }
  else
  {
    DbgPrint(a2, "HAL: Spurious SMBus interrupt.\n");
    v9 = v20;
  }
  HalpReleaseSMBusLock(v8, v9, a2, a3);
}