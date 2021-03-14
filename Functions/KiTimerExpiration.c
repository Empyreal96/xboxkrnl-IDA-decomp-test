void __userpurge KiTimerExpiration(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _KDPC *TimerDpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  int v8; // edx
  _LIST_ENTRY **v9; // ebx
  _LIST_ENTRY *v10; // edi
  _LIST_ENTRY *v11; // esi
  _LIST_ENTRY *v12; // esi
  _LIST_ENTRY *v13; // eax
  _ULARGE_INTEGER CurrentTime; // [esp+0h] [ebp-14h]
  _LIST_ENTRY ExpiredListHead; // [esp+8h] [ebp-Ch]
  int HandLimit; // [esp+10h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\dpcsup.c",
      0x106u,
      0);
  while ( 1 )
  {
    CurrentTime = *(_ULARGE_INTEGER *)&KeInterruptTime.LowPart;
    if ( KeInterruptTime.High1Time == KeInterruptTime.High2Time )
      break;
    _mm_pause();
  }
  HandLimit = KeTickCount;
  if ( KeTickCount - (unsigned int)SystemArgument1 < 0x20 )
  {
    LOBYTE(v8) = ((_BYTE)SystemArgument1 - 1) & 0x1F;
    HandLimit &= 0x1Fu;
  }
  else
  {
    LOBYTE(v8) = -1;
    HandLimit = 31;
  }
  ExpiredListHead.Blink = &ExpiredListHead;
  ExpiredListHead.Flink = &ExpiredListHead;
  do
  {
    v8 = ((_BYTE)v8 + 1) & 0x1F;
    v9 = (_LIST_ENTRY **)(8 * v8 - 2147152128);
    while ( 1 )
    {
      v13 = *v9;
      if ( *v9 == (_LIST_ENTRY *)v9 || *(_QWORD *)&v13[-1] > CurrentTime.QuadPart )
        break;
      v10 = v13->Blink;
      v11 = v13->Flink;
      v10->Flink = v13->Flink;
      v11->Blink = v10;
      v12 = ExpiredListHead.Blink;
      v13->Flink = &ExpiredListHead;
      v13->Blink = v12;
      v12->Flink = v13;
      ExpiredListHead.Blink = v13;
    }
  }
  while ( v8 != HandLimit );
  if ( !SystemArgument2 )
    KiCheckTimerTable(CurrentTime);
  KiTimerListExpire(&ExpiredListHead, 2);
}