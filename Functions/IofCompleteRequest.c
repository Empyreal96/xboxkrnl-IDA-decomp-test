void __usercall IofCompleteRequest(_IRP *Irp@<ecx>, int PriorityBoost@<edx>, int *a3@<edi>)
{
  _IRP *v3; // esi
  _IO_STACK_LOCATION *v4; // edi
  char v5; // al
  int v6; // ecx
  char v7; // al
  bool v8; // sf
  unsigned int v9; // eax
  int v10; // edi
  _IO_STATUS_BLOCK *v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  _FILE_OBJECT *v16; // edi
  int v17; // edx
  int v18; // ecx
  KIRQL v19; // cl
  _KTHREAD *v20; // eax
  _KAPC *v21; // esi
  int v22; // edx
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  _FILE_OBJECT *fileObject; // [esp+Ch] [ebp-Ch]
  char irql; // [esp+13h] [ebp-5h]
  char v28; // [esp+14h] [ebp-4h]

  v3 = Irp;
  v28 = PriorityBoost;
  if ( Irp->CurrentLocation > (char)(Irp->StackCount + 1) || Irp->Type != 6 )
    KeBugCheckEx(0x44u, (unsigned int)Irp, 0x330u, 0, 0);
  if ( Irp->IoStatus.Status == 259 )
    RtlAssert(
      (unsigned __int8)PriorityBoost,
      (int)Irp,
      a3,
      (int)Irp,
      "Irp->IoStatus.Status != STATUS_PENDING",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x340u,
      0);
  if ( v3->IoStatus.Status == -1 )
    RtlAssert(
      (unsigned __int8)PriorityBoost,
      (int)Irp,
      a3,
      (int)v3,
      "Irp->IoStatus.Status != 0xffffffff",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x348u,
      0);
  v4 = v3->Tail.Overlay.CurrentStackLocation;
  v5 = ++v3->CurrentLocation;
  v6 = (int)&v4[1];
  v3->Tail.Overlay.PacketType = (unsigned int)&v4[1];
  LOBYTE(v6) = v3->StackCount + 1;
  if ( v5 <= (char)v6 )
  {
    v4 = (_IO_STACK_LOCATION *)((char *)v4 + 3);
    do
    {
      if ( v4->MajorFunction & 2 )
      {
        if ( (_BYTE)dword_8004C5D0 != 2 )
          RtlAssert(
            (unsigned __int8)PriorityBoost,
            v6,
            (int *)&v4->MajorFunction,
            (int)v3,
            "KeGetCurrentIrql() == DISPATCH_LEVEL",
            "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
            0x362u,
            0);
        if ( !--IoPendingMustCompletePackets && HalIsResetOrShutdownPending() )
          HalMustCompletePacketsFinished(PriorityBoost, v6, (int *)&v4->MajorFunction);
      }
      v7 = v4->MajorFunction & 1;
      v8 = v3->IoStatus.Status < 0;
      v3->PendingReturned = v7;
      if ( v8 )
      {
        if ( v4->MajorFunction >= 0 )
        {
LABEL_17:
          if ( v7 && v3->CurrentLocation <= v3->StackCount )
            *(_BYTE *)(v3->Tail.Overlay.PacketType + 3) |= 1u;
          BYTE2(v4[-1].Context) = 0;
          HIBYTE(v4[-1].Context) = 0;
          v4->MajorFunction = 0;
          *(_DWORD *)&v4->MinorFunction = 0;
          *(unsigned int *)((char *)&v4->Parameters.Create.DesiredAccess + 1) = 0;
          *(_FILE_INFORMATION_CLASS *)((char *)&v4->Parameters.QueryFile.FileInformationClass + 1) = 0;
          *(unsigned int *)((char *)&v4->Parameters.FileSystemControl.InputBufferLength + 1) = 0;
          *(_DEVICE_OBJECT **)((char *)&v4->DeviceObject + 1) = 0;
          goto LABEL_21;
        }
      }
      else if ( !(v4->MajorFunction & 0x40) )
      {
        goto LABEL_17;
      }
      BYTE2(v4[-1].Context) = 0;
      HIBYTE(v4[-1].Context) = 0;
      v4->MajorFunction = 0;
      *(_DWORD *)&v4->MinorFunction = 0;
      *(unsigned int *)((char *)&v4->Parameters.Create.DesiredAccess + 1) = 0;
      *(_FILE_INFORMATION_CLASS *)((char *)&v4->Parameters.QueryFile.FileInformationClass + 1) = 0;
      *(unsigned int *)((char *)&v4->Parameters.FileSystemControl.InputBufferLength + 1) = 0;
      *(_DEVICE_OBJECT **)((char *)&v4->DeviceObject + 1) = 0;
      if ( v3->CurrentLocation == v3->StackCount + 1 )
        v15 = 0;
      else
        v15 = *(_DWORD *)(v3->Tail.Overlay.PacketType + 20);
      if ( (*(int (__stdcall **)(int, _IRP *, _DWORD))((char *)&v4->FileObject + 1))(
             v15,
             v3,
             *(int (__stdcall **)(_DEVICE_OBJECT *, _IRP *, void *))((char *)&v4->CompletionRoutine + 1)) == -1073741802 )
        return;
LABEL_21:
      v3->Tail.Overlay.PacketType += 36;
      ++v4;
      ++v3->CurrentLocation;
    }
    while ( v3->CurrentLocation <= (char)(v3->StackCount + 1) );
  }
  v9 = v3->Flags;
  if ( v9 & 0x42 )
  {
    v10 = v3->Flags & 2;
    v11 = v3->UserIosb;
    v11->Status = v3->IoStatus.Status;
    v12 = v3->IoStatus.Information;
    v11->Information = v12;
    KeSetEvent(v12, (unsigned __int8)PriorityBoost, v3->UserEvent, v28, 0);
    if ( v10 )
      IoFreeIrp(v14, v13, v3);
  }
  else
  {
    if ( v9 & 0x200 )
    {
      MmLockUnlockBufferPages(
        (unsigned __int8)PriorityBoost,
        v6,
        (int *)&v4->MajorFunction,
        (int)v3,
        v3->UserBuffer,
        v3->LockedBufferLength,
        1);
      BYTE1(v3->Flags) &= 0xFDu;
    }
    else if ( v3->SegmentArray )
    {
      MmUnlockSelectedIoPages((unsigned __int8)PriorityBoost, v6, (int)v3, v3);
    }
    if ( SLOBYTE(v3->Flags) >= 0 || v3->PendingReturned )
    {
      v16 = v3->Tail.Overlay.OriginalFileObject;
      fileObject = v3->Tail.Overlay.OriginalFileObject;
      if ( v3->Cancel )
      {
        v19 = KeRaiseIrqlToDpcLevel();
        v20 = &v3->Tail.Overlay.Thread->Tcb;
        irql = v19;
        if ( v20 )
        {
          v21 = (_KAPC *)&v3->Tail;
          KeInitializeApc(
            v21,
            v20,
            (void (__stdcall *)(_KAPC *, void (__stdcall **)(void *, void *, void *), void **, void **, void **))IopCompleteRequest,
            0,
            0,
            0,
            0);
          KeInsertQueueApc(v23, v22, v21, v16, 0, v28);
          KfLowerIrql(irql);
        }
        else
        {
          KfLowerIrql(v19);
          if ( !v3->Cancel )
            RtlAssert(
              (unsigned __int8)v24,
              v25,
              (int *)&v16->Type,
              (int)v3,
              "Irp->Cancel",
              "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
              0x430u,
              0);
          IopDropIrp(v25, v24, v3, v16);
        }
      }
      else
      {
        KeInitializeApc(
          (_KAPC *)&v3->Tail,
          &v3->Tail.Overlay.Thread->Tcb,
          (void (__stdcall *)(_KAPC *, void (__stdcall **)(void *, void *, void *), void **, void **, void **))IopCompleteRequest,
          0,
          0,
          0,
          0);
        KeInsertQueueApc(v18, v17, (_KAPC *)&v3->Tail, fileObject, 0, v28);
      }
    }
  }
}