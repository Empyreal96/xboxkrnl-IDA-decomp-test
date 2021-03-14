int __userpurge FscMapBuffer@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _FSCACHE_EXTENSION *CacheExtension, _IRP *Irp, unsigned __int64 ByteOffset, char MapAsReadWrite, void **ReturnedCacheBuffer)
{
  _FSCACHE_EXTENSION *v9; // edi
  _IRP *v10; // ecx
  _KTHREAD *v11; // esi
  int v12; // edx
  int v13; // ecx
  _FSCACHE_ELEMENT *v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  _FSCACHE_ELEMENT *v23; // esi
  int v24; // esi
  unsigned int v25; // esi
  unsigned int v26; // eax
  bool v27; // zf
  _LIST_ENTRY *v28; // ecx
  unsigned int v29; // ebx
  int v30; // edx
  int v31; // ecx
  _IO_STACK_LOCATION *v32; // eax
  _KEVENT *v33; // edx
  int v34; // esi
  unsigned int v35; // eax
  int v36; // edx
  int v37; // ecx
  int v38; // edx
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  int v42; // edx
  int v43; // ecx
  _FSCACHE_ELEMENT *v44; // edi
  int v45; // ecx
  _KEVENT IoEvent; // [esp+Ch] [ebp-1Ch]
  int status; // [esp+20h] [ebp-8h]
  unsigned int BlockNumber; // [esp+24h] [ebp-4h]
  KIRQL OldIrql_3; // [esp+33h] [ebp+Bh]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x34Fu,
      0);
  v9 = CacheExtension;
  v10 = Irp;
  LOBYTE(v10) = Irp->CurrentLocation;
  if ( (char)v10 <= CacheExtension->TargetDeviceObject->StackSize )
    RtlAssert(
      a1,
      (int)v10,
      (int *)CacheExtension,
      a4,
      "Irp->CurrentLocation > CacheExtension->TargetDeviceObject->StackSize",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x350u,
      0);
  if ( ByteOffset >= CacheExtension->PartitionLength.QuadPart )
    RtlAssert(
      a1,
      (int)v10,
      (int *)CacheExtension,
      SHIDWORD(ByteOffset),
      "ByteOffset < (ULONGLONG)CacheExtension->PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x351u,
      0);
  v11 = (_KTHREAD *)(HIDWORD(ByteOffset) >> 12);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  status = HIDWORD(ByteOffset) >> 12;
  BlockNumber = ByteOffset >> 12;
  v14 = FscLookupElement(v13, v12, v9, BlockNumber);
  if ( v14 )
  {
    BlockNumber = ByteOffset >> 12;
    while ( 1 )
    {
      v17 = (int)v14->CacheBuffer;
      if ( !(v17 & 0x100) )
        break;
      v18 = v17 | 0x200;
      v14->0 = ($E339EC3434257F768F3203BB3C26A88D)v18;
      v11 = thread;
      if ( (_BYTE)dword_8004C5D0 != 2 )
        RtlAssert(
          v15,
          v18,
          (int *)v9,
          (int)thread,
          "KeGetCurrentIrql() == DISPATCH_LEVEL",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x385u,
          0);
      if ( (unsigned __int8)OldIrql_3 > 1u )
        RtlAssert(
          v15,
          v18,
          (int *)v9,
          (int)v11,
          "(OldIrql) <= APC_LEVEL",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x385u,
          0);
      v11->WaitIrql = OldIrql_3;
      v11->WaitNext = 1;
      KeWaitForSingleObject(v18, v15, &FscCollidedMapBufferEvent, 0, 0, 0, 0);
      OldIrql_3 = KeRaiseIrqlToDpcLevel();
      v14 = FscLookupElement(v20, v19, v9, BlockNumber);
      if ( !v14 )
        goto LABEL_15;
    }
    ++*(_BYTE *)&v14->0;
    v25 = *(_DWORD *)&v14->0 & 0xFFFFF000;
    if ( MapAsReadWrite )
    {
      FscSetCacheBufferProtection((void *)(*(_DWORD *)&v14->0 & 0xFFFFF000), 1, (int *)v9);
    }
    else if ( *(_BYTE *)(((v25 >> 10) & 0x3FFFFC) - 0x40000000) & 2 )
    {
      RtlAssert(
        v15,
        v17,
        (int *)v9,
        v25,
        "MiGetPteAddress(CacheBuffer)->Hard.Write == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x36Eu,
        0);
    }
    *ReturnedCacheBuffer = (void *)(v25 + (ByteOffset & 0xFFF));
    v24 = 0;
  }
  else
  {
LABEL_15:
    v23 = FscAllocateElement(v15, v16, (int)v11);
    if ( v23 )
    {
      v26 = BlockNumber;
      v23->0 = ($E339EC3434257F768F3203BB3C26A88D)1;
      *((_BYTE *)&v23->0 + 1) |= 1u;
      v27 = (*((_BYTE *)&v23->0 + 1) & 2) == 0;
      v23->BlockNumber = v26;
      v23->CacheExtension = v9;
      if ( !v27 )
        RtlAssert(
          v21,
          v22,
          (int *)v9,
          (int)v23,
          "!Element->ReadWaiters",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x3A4u,
          0);
      v28 = FscLruList.Blink;
      v23->ListEntry.Flink = &FscLruList;
      v23->ListEntry.Blink = v28;
      v28->Flink = &v23->ListEntry;
      FscLruList.Blink = &v23->ListEntry;
      v29 = *(_DWORD *)&v23->0 & 0xFFFFF000;
      MmLockUnlockBufferPages(v21, (int)v28, (int *)v9, (int)v23, (void *)v29, 0x1000u, 0);
      KfLowerIrql(OldIrql_3);
      IoEvent.Header.SignalState = 0;
      IoEvent.Header.WaitListHead.Blink = &IoEvent.Header.WaitListHead;
      IoEvent.Header.WaitListHead.Flink = &IoEvent.Header.WaitListHead;
      IoEvent.Header.Type = 0;
      IoEvent.Header.Size = 4;
      if ( !FscSignalIoEventCompletion )
        RtlAssert(
          v30,
          v31,
          (int *)v9,
          (int)FscSignalIoEventCompletion,
          "(1) | (1) | (1) ? (FscSignalIoEventCompletion) != NULL : TRUE",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x3BDu,
          (char *)FscSignalIoEventCompletion);
      v32 = Irp->Tail.Overlay.CurrentStackLocation;
      v32[-1].CompletionRoutine = (int (__stdcall *)(_DEVICE_OBJECT *, _IRP *, void *))FscSignalIoEventCompletion;
      v32[-1].Control = -32;
      v33 = &IoEvent;
      v32[-1].Context = &IoEvent;
      v34 = Irp->Tail.Overlay.PacketType - 36;
      *(_QWORD *)(v34 + 12) = (unsigned __int64)BlockNumber << 12;
      *(_BYTE *)v34 = 2;
      *(_BYTE *)(v34 + 2) = -128;
      *(_DWORD *)(v34 + 8) = v29;
      v35 = (unsigned __int64)v9->PartitionLength.QuadPart >> 12;
      if ( BlockNumber >= v35 )
      {
        v45 = v9->PartitionLength.LowPart & 0xFFF;
        v27 = BlockNumber == v35;
        *(_DWORD *)(v34 + 4) = v45;
        if ( !v27 )
          RtlAssert(
            (int)&IoEvent,
            v45,
            (int *)v9,
            v34,
            "BlockNumber == EndingBlockNumber",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x3D9u,
            0);
        if ( !*(_DWORD *)(v34 + 4) )
          RtlAssert(
            (int)v33,
            v45,
            (int *)v9,
            (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            "IrpSp->Parameters.Read.Length != 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x3DAu,
            0);
      }
      else
      {
        *(_DWORD *)(v34 + 4) = 4096;
      }
      status = IofCallDriver(v9->TargetDeviceObject, Irp);
      if ( status == 259 )
      {
        KeWaitForSingleObject(v37, v36, &IoEvent, Spare2, 0, 0, 0);
        status = Irp->IoStatus.Status;
      }
      OldIrql_3 = KeRaiseIrqlToDpcLevel();
      MmLockUnlockBufferPages(
        v38,
        v39,
        (int *)v9,
        (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        (void *)v29,
        0x1000u,
        1);
      v44 = FscElementFromCacheBuffer(v40, v41, (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c", (void *)v29);
      if ( v44->BlockNumber != BlockNumber )
        RtlAssert(
          v42,
          v43,
          (int *)v44,
          (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          "Element->BlockNumber == BlockNumber",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x3F9u,
          0);
      if ( v44->0 != 1 )
        RtlAssert(
          v42,
          v43,
          (int *)v44,
          (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          "Element->UsageCount == 1",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x3FAu,
          0);
      if ( !(*((_BYTE *)&v44->0 + 1) & 1) )
        RtlAssert(
          v42,
          v43,
          (int *)v44,
          (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          "Element->ReadInProgress",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x3FBu,
          0);
      *((_BYTE *)&v44->0 + 1) &= 0xFEu;
      if ( *((_BYTE *)&v44->0 + 1) & 2 )
      {
        KePulseEvent(v43, v42, &FscCollidedMapBufferEvent, 1, 0);
        *((_BYTE *)&v44->0 + 1) &= 0xFDu;
      }
      if ( status < 0 )
      {
        FscDiscardBuffer((int *)v44, (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c", (void *)v29);
      }
      else
      {
        if ( MapAsReadWrite )
        {
          FscSetCacheBufferProtection((void *)v29, 1, (int *)v44);
        }
        else if ( *(_BYTE *)(((v29 >> 10) & 0x3FFFFC) - 0x40000000) & 2 )
        {
          RtlAssert(
            v42,
            v43,
            (int *)v44,
            (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            "MiGetPteAddress(CacheBuffer)->Hard.Write == 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x418u,
            0);
        }
        *ReturnedCacheBuffer = (void *)(v29 + (ByteOffset & 0xFFF));
      }
      v24 = status;
    }
    else
    {
      v24 = -1073741801;
    }
  }
  KfLowerIrql(OldIrql_3);
  return v24;
}