int __usercall KeClockInterrupt@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  unsigned int v3; // ebx
  void *v4; // ebx
  unsigned __int64 v5; // rdi
  char v6; // al
  _DWORD *v7; // ecx
  _LIST_ENTRY *v8; // ebx
  _KTHREAD *v9; // ebx
  bool v10; // zf
  bool v11; // sf
  unsigned __int8 v12; // of
  int v14; // [esp+4h] [ebp-40h]
  int v15; // [esp+8h] [ebp-3Ch]
  int v16; // [esp+Ch] [ebp-38h]
  int v17; // [esp+10h] [ebp-34h]
  int v18; // [esp+14h] [ebp-30h]
  int v19; // [esp+20h] [ebp-24h]
  int v20; // [esp+24h] [ebp-20h]
  int v21; // [esp+28h] [ebp-1Ch]
  unsigned int v22; // [esp+2Ch] [ebp-18h]
  int v23; // [esp+3Ch] [ebp-8h]
  int retaddr; // [esp+44h] [ebp+0h]

  v21 = a1;
  v20 = a3;
  v19 = a2;
  v3 = KiPCR;
  KiPCR = -1;
  v22 = v3;
  v18 = a2;
  v17 = -1160049408;
  v15 = v23;
  v16 = retaddr;
  v14 = 0;
  ((void (__fastcall *)(_DWORD, signed int))HalBeginProfileInterrupt)(0, 28);
  if ( KiDbgClockInt )
    ((void (__stdcall *)(int *))KiDbgClockInt)(&v15);
  v4 = (void *)KeTickCount;
  v5 = *(_QWORD *)&KeInterruptTime.LowPart + 10000i64;
  KeInterruptTime.High2Time = (unsigned __int64)(*(_QWORD *)&KeInterruptTime.LowPart + 10000i64) >> 32;
  *(_QWORD *)&KeInterruptTime.LowPart += 10000i64;
  KeSystemTime.High2Time = (unsigned __int64)(*(_QWORD *)&KeSystemTime.LowPart + 10000i64) >> 32;
  *(_QWORD *)&KeSystemTime.LowPart += 10000i64;
  v6 = KeTickCount++;
  v7 = (_DWORD *)(8 * (v6 & 0x1F) - 2147152128);
  if ( v7 != (_DWORD *)*v7 && v5 >= *(_QWORD *)(*v7 - 8) && !KiTimerExpireDpc.Inserted )
  {
    _disable();
    KiTimerExpireDpc.Inserted = 1;
    KiTimerExpireDpc.SystemArgument1 = v4;
    v8 = (_LIST_ENTRY *)*((_DWORD *)&unk_8004C5FC + 1);
    *((_DWORD *)&unk_8004C5FC + 1) = (char *)&KiTimerExpireDpc + 4;
    v8->Flink = &KiTimerExpireDpc.DpcListEntry;
    KiTimerExpireDpc.DpcListEntry.Flink = (_LIST_ENTRY *)&unk_8004C5FC;
    KiTimerExpireDpc.DpcListEntry.Blink = v8;
    _enable();
    HalRequestSoftwareInterrupt(2);
  }
  if ( KdDebuggerEnabled && KdPollBreakIn() )
    DbgBreakPointWithStatus(1u);
  ++unk_8004C5E4;
  v9 = thread;
  if ( (unsigned __int8)v14 < 2u )
    goto LABEL_25;
  if ( (unsigned __int8)v14 > 2u )
  {
    ++unk_8004C5EC;
    goto Kutp55;
  }
  if ( !dword_8004C604 )
  {
LABEL_25:
    ++thread->KernelTime;
    goto Kutp55;
  }
  ++unk_8004C5E8;
  if ( ++unk_8004C5F0 >= KiDPCTimeout )
  {
    DbgPrint((int *)v5, "\n*** DPC routine > 1 sec --- This is not a break in KeUpdateSystemTime\n");
    if ( KdDebuggerEnabled )
      DbgBreakPoint();
    unk_8004C5F0 = 0;
  }
Kutp55:
  v12 = __OFSUB__(v9->Quantum, 3);
  v10 = v9->Quantum == 3;
  v11 = v9->Quantum - 3 < 0;
  v9->Quantum -= 3;
  if ( (unsigned __int8)(v11 ^ v12) | v10 && v9 != &KiIdleThread )
  {
    unk_8004C60C = &v14;
    HalRequestSoftwareInterrupt(2);
  }
  _disable();
  return HalEndSystemInterrupt(v14);
}