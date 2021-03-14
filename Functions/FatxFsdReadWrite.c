int *__stdcall FatxFsdReadWrite(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v2; // ecx
  _FAT_VOLUME_EXTENSION *v3; // ebx
  _IO_STACK_LOCATION *v4; // esi
  int *v5; // edi
  char v6; // dl
  int *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // ecx
  _LARGE_INTEGER *v11; // esi
  unsigned int v12; // edx
  unsigned int v13; // esi
  _IO_STACK_LOCATION *v14; // esi
  int *v15; // edi
  int v16; // edx
  int v17; // ecx
  int v18; // ecx
  _IO_STACK_LOCATION *v19; // eax
  int v20; // esi
  unsigned int v21; // edx
  unsigned int v28; // ecx
  unsigned int v29; // eax
  unsigned int v30; // eax
  int v31; // edx
  int v32; // ecx
  unsigned int v33; // eax
  int v34; // ST1C_4
  int v35; // edx
  unsigned int v36; // eax
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  int v40; // eax
  int v41; // ecx
  _KTHREAD *v42; // eax
  unsigned int v43; // ecx
  int v45; // edx
  int v46; // ecx
  int v47; // edx
  int v48; // ecx
  _FAT_FCB *Fcb; // [esp+Ch] [ebp-24h]
  char NonCachedEndOfFileTransfer; // [esp+10h] [ebp-20h]
  int *v54; // [esp+14h] [ebp-1Ch]
  _IO_STACK_LOCATION *NextIrpSp; // [esp+18h] [ebp-18h]
  _IO_STACK_LOCATION *NextIrpSpa; // [esp+18h] [ebp-18h]
  unsigned int ClusterNumber; // [esp+1Ch] [ebp-14h]
  _FILE_OBJECT *FileObject; // [esp+20h] [ebp-10h]
  int MajorFunction; // [esp+24h] [ebp-Ch]
  unsigned int IoLength; // [esp+28h] [ebp-8h]
  char SynchronousIo; // [esp+2Fh] [ebp-1h]
  unsigned __int64 *DeviceObjecta; // [esp+38h] [ebp+8h]

  v2 = Irp;
  v3 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v4 = Irp->Tail.Overlay.CurrentStackLocation;
  NextIrpSp = v4 - 1;
  LOBYTE(MajorFunction) = v4->MajorFunction;
  v5 = (int *)v4->FileObject->FsContext;
  v6 = *(_BYTE *)v5;
  _ZF = (*(_BYTE *)v5 & 2) == 0;
  FileObject = v4->FileObject;
  v54 = (int *)&v4->Parameters;
  Fcb = (_FAT_FCB *)v5;
  IoLength = v4->Parameters.Create.DesiredAccess;
  NonCachedEndOfFileTransfer = 0;
  if ( !_ZF )
  {
    v8 = (int *)-1073741808;
CompleteAndExit:
    v2->IoStatus.Status = (int)v8;
    IofCompleteRequest(v2, 0, v8);
    return v8;
  }
  if ( !IoLength )
  {
    v8 = 0;
    Irp->IoStatus.Information = 0;
    goto CompleteAndExit;
  }
  if ( !(v6 & 1) )
  {
    if ( (_BYTE)MajorFunction == 2 )
      FatxAcquireFileMutexShared(v6, (int)Irp, v5, (_FAT_FCB *)v5);
    else
      FatxAcquireFileMutexExclusive(v6, (int)Irp, v5, (_FAT_FCB *)v5);
    _EAX = 1;
    _ECX = (int)&v3->DismountBlockCount;
    __asm { xadd    [ecx], eax }
    if ( v3->Flags & 1 )
    {
      v8 = (int *)-1073741202;
      goto UnlockFileAndExit;
    }
    if ( FileObject->Flags & 0x10 )
    {
      v8 = (int *)-1073741528;
      goto UnlockFileAndExit;
    }
    if ( (_BYTE)MajorFunction == 2 )
    {
      if ( v4->Parameters.Read.ByteOffset.HighPart
        || (v21 = v4->Parameters.Read.ByteOffset.LowPart, v5 = (int *)v5[9], v21 >= (unsigned int)v5) )
      {
        v8 = (int *)-1073741807;
        goto UnlockFileAndExit;
      }
      v28 = (unsigned int)v5 - v21;
      if ( IoLength >= (unsigned int)v5 - v21 )
      {
        v5 = (int *)((~(v3->CacheExtension.SectorSize - 1) & ((unsigned int)v5 + v3->CacheExtension.SectorSize - 1))
                   - v21);
        if ( IoLength >= (unsigned int)v5 )
          NonCachedEndOfFileTransfer = 1;
        IoLength = v28;
      }
      if ( !IoLength )
        RtlAssert(v21, v28, v5, (int)v4, "IoLength > 0", "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c", 0x5AEu, 0);
      SynchronousIo = FileObject->Flags & 1;
    }
    else
    {
      if ( v4->Parameters.Read.ByteOffset.LowPart == -1 && v4->Parameters.Read.ByteOffset.HighPart == -1 )
      {
        v29 = v5[9];
        v4->Parameters.Read.ByteOffset.HighPart = 0;
        v4->Parameters.Read.ByteOffset.LowPart = v29;
      }
      v30 = v4->Parameters.Read.ByteOffset.LowPart;
      v28 = v30 + IoLength;
      NextIrpSpa = (_IO_STACK_LOCATION *)(v30 + IoLength);
      if ( (unsigned __int64)(v30 + IoLength) <= v4->Parameters.Read.ByteOffset.QuadPart )
      {
        v8 = (int *)-1073741697;
        goto UnlockFileAndExit;
      }
      if ( v5[10] == -1 )
      {
        FatxAcquireVolumeMutexShared((unsigned __int8)v21, v28, v5, v3);
        v8 = (int *)FatxFileByteOffsetToCluster(
                      v31,
                      v32,
                      (int)v4,
                      v3,
                      Irp,
                      (_FAT_FCB *)v5,
                      0xFFFFFFFF,
                      &ClusterNumber,
                      0);
        FatxReleaseVolumeMutex(v3);
        if ( (signed int)v8 < 0 && v8 != (int *)-1073741807 )
          goto UnlockFileAndExit;
        v5 = (int *)&Fcb->Flags;
      }
      v33 = v5[10];
      if ( v5[9] > v33 )
      {
        v8 = (int *)-1073741566;
        goto UnlockFileAndExit;
      }
      if ( (unsigned int)NextIrpSpa > v33 )
      {
        FatxAcquireVolumeMutexExclusive((unsigned __int8)v21, v28, v5, (int)v4, v3);
        v34 = ~(v3->BytesPerCluster - 1) & ((unsigned int)NextIrpSpa + v3->BytesPerCluster - 1);
        v8 = FatxExtendFileAllocation(v34, v35, v3, Irp, (_FAT_FCB *)v5, v34);
        FatxReleaseVolumeMutex(v3);
        if ( (signed int)v8 < 0 )
          goto UnlockFileAndExit;
        v5 = (int *)&Fcb->Flags;
      }
      SynchronousIo = FileObject->Flags & 1;
      if ( !SynchronousIo && (unsigned int)NextIrpSpa > v5[9] )
        SynchronousIo = 1;
    }
    if ( v4->Parameters.Read.ByteOffset.HighPart )
      RtlAssert(
        v21,
        v28,
        v5,
        (int)v4,
        "IrpSp->Parameters.Read.ByteOffset.HighPart == 0",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
        0x61Fu,
        0);
    v36 = Irp->Flags;
    if ( v36 & 1 )
    {
      v37 = v3->CacheExtension.SectorSize - 1;
      if ( v37 & v4->Parameters.Read.ByteOffset.LowPart || v37 & *v54 )
      {
        v8 = (int *)-1073741811;
        goto UnlockFileAndExit;
      }
      IoLockUserBuffer(v21, *v54, (int)v4, Irp, *v54);
      if ( !SynchronousIo )
      {
        v8 = (int *)FatxNonCachedAsynchronousIo(
                      v38,
                      (int)v4,
                      DeviceObject,
                      Irp,
                      MajorFunction,
                      FileObject,
                      v4->Parameters.Read.ByteOffset.LowPart,
                      IoLength);
        v20 = 259;
        if ( v8 == (int *)259 )
          goto LABEL_67;
UnlockFileAndExit:
        _EAX = -1;
        _ECX = (int)&v3->DismountBlockCount;
        __asm { xadd    [ecx], eax }
        if ( _EAX - 1 < 0 )
          FatxSignalDismountUnblockEvent(v3);
        FatxReleaseFileMutex(v21, _ECX, v8, Fcb);
        goto LABEL_83;
      }
      v40 = FatxNonCachedSynchronousIo(
              v39,
              v38,
              DeviceObject,
              Irp,
              MajorFunction,
              FileObject,
              v4->Parameters.Read.ByteOffset.LowPart,
              0,
              IoLength,
              0);
    }
    else
    {
      if ( v36 & 0x400 )
        RtlAssert(
          v21,
          v28,
          (int *)&Irp->Type,
          (int)v4,
          "FatxIsFlagClear(Irp->Flags, IRP_SCATTER_GATHER_OPERATION)",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
          0x65Cu,
          0);
      if ( FscTestForFullyCachedIo(
             v21,
             v28,
             (int *)&Irp->Type,
             Irp,
             v4->Parameters.Read.ByteOffset.LowPart,
             IoLength,
             NonCachedEndOfFileTransfer) )
      {
        v40 = FatxFullyCachedSynchronousIo(
                v46,
                v45,
                DeviceObject,
                Irp,
                MajorFunction,
                FileObject,
                v4->Parameters.Read.ByteOffset.LowPart,
                0,
                IoLength,
                0);
      }
      else
      {
        IoLockUserBuffer(v45, v46, (int)v4, Irp, *v54);
        v40 = FatxPartiallyCachedSynchronousIo(
                v48,
                v47,
                DeviceObject,
                Irp,
                MajorFunction,
                FileObject,
                v4->Parameters.Read.ByteOffset.LowPart,
                IoLength,
                NonCachedEndOfFileTransfer);
      }
    }
    v8 = (int *)v40;
    if ( v40 == 259 )
      RtlAssert(
        v21,
        v41,
        (int *)0x103,
        (int)v4,
        "status != STATUS_PENDING",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
        0x67Au,
        0);
    goto UnlockFileAndExit;
  }
  if ( (_BYTE)MajorFunction == 2 )
    FatxAcquireVolumeMutexShared(v6, (int)Irp, v5, v3);
  else
    FatxAcquireVolumeMutexExclusive(v6, (int)Irp, v5, (int)v4, v3);
  if ( v3->Flags & 1 )
  {
    v8 = (int *)-1073741202;
UnlockVolumeAndExit:
    FatxReleaseVolumeMutex(v3);
LABEL_83:
    v2 = Irp;
    goto CompleteAndExit;
  }
  v9 = v3->CacheExtension.PartitionLength.HighPart;
  v10 = v3->CacheExtension.PartitionLength.LowPart;
  v11 = (_LARGE_INTEGER *)(&v4->Parameters.SetVolume + 1);
  v12 = v11->LowPart;
  DeviceObjecta = (unsigned __int64 *)&v11->LowPart;
  v13 = v11->HighPart;
  if ( v13 >= v9 && (v13 > v9 || v12 >= v10) )
  {
    v8 = (int *)-1073741807;
    goto UnlockVolumeAndExit;
  }
  if ( IoLength >= __PAIR__(v9, v10) - __PAIR__(v13, v12) )
    IoLength = v10 - v12;
  if ( IoLength <= 0 )
    RtlAssert(0, v10 - v12, v5, v13, "IoLength > 0", "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c", 0x51Fu, 0);
  v14 = Irp->Tail.Overlay.CurrentStackLocation;
  qmemcpy(&v14[-1], v14, 0x1Cu);
  v15 = (int *)&v14[-1].CompletionRoutine;
  v14[-1].Control = 0;
  IoLockUserBuffer((int)Irp, 0, (int)&v14->CompletionRoutine, Irp, *v54);
  if ( (_BYTE)MajorFunction == 3 )
    FscInvalidateByteRange(v16, v17, v15, &v3->CacheExtension, *DeviceObjecta, IoLength);
  v18 = IoLength;
  NextIrpSp->Parameters.Create.DesiredAccess = IoLength;
  if ( !FatxVolumeIoCompletion )
    RtlAssert(
      v16,
      v18,
      v15,
      (int)FatxVolumeIoCompletion,
      "(1) | (1) | (1) ? (FatxVolumeIoCompletion) != NULL : TRUE",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x545u,
      (char *)FatxVolumeIoCompletion);
  v19 = Irp->Tail.Overlay.CurrentStackLocation;
  v19[-1].Context = 0;
  --v19;
  v19->CompletionRoutine = (int (__stdcall *)(_DEVICE_OBJECT *, _IRP *, void *))FatxVolumeIoCompletion;
  v19->Control = -32;
  v20 = IofCallDriver(v3->CacheExtension.TargetDeviceObject, Irp);
LABEL_67:
  v42 = thread;
  v43 = thread->KernelApcDisable + 1;
  thread->KernelApcDisable = v43;
  if ( !v43 && (_KAPC_STATE *)v42->ApcState.ApcListHead[0].Flink != &v42->ApcState )
  {
    v42->ApcState.KernelApcPending = 1;
    HalRequestSoftwareInterrupt(1);
  }
  return (int *)v20;
}