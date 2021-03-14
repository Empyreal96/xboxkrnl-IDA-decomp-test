int __userpurge FatxDismountVolume@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DEVICE_OBJECT *DeviceObject)
{
  _FAT_VOLUME_EXTENSION *v4; // esi
  char v5; // al
  int result; // eax
  int v7; // edx
  int v8; // ecx
  KIRQL v9; // bl
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  KIRQL v15; // al
  KIRQL v16; // al
  int v17; // edx
  unsigned int v18; // ebx
  int v19; // edx
  int v20; // ecx
  _KEVENT DismountUnblockEvent; // [esp+4h] [ebp-10h]

  v4 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  FatxAcquireVolumeMutexExclusive(a1, a2, a3, (int)v4, (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension);
  v5 = v4->Flags;
  if ( v5 & 1 )
  {
    FatxReleaseVolumeMutex(v4);
    result = -1073741202;
  }
  else
  {
    v4->Flags = v5 | 1;
    DismountUnblockEvent.Header.Type = 1;
    DismountUnblockEvent.Header.Size = 4;
    DismountUnblockEvent.Header.SignalState = 0;
    DismountUnblockEvent.Header.WaitListHead.Blink = &DismountUnblockEvent.Header.WaitListHead;
    DismountUnblockEvent.Header.WaitListHead.Flink = &DismountUnblockEvent.Header.WaitListHead;
    v9 = KeRaiseIrqlToDpcLevel();
    if ( v4->DismountUnblockEvent )
      RtlAssert(
        v7,
        v8,
        0,
        (int)v4,
        "VolumeExtension->DismountUnblockEvent == NULL",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fsctrl.c",
        0x6Fu,
        0);
    v4->DismountUnblockEvent = &DismountUnblockEvent;
    v10 = v4->DismountBlockCount;
    if ( v10 > 0 )
    {
      v4->DismountBlockCount = v10 - 1;
      KfLowerIrql(v9);
      FatxReleaseVolumeMutex(v4);
      KeWaitForSingleObject(v12, v11, &DismountUnblockEvent, 0, 0, 0, 0);
      FatxAcquireVolumeMutexExclusive(v13, v14, 0, (int)v4, v4);
      v15 = KeRaiseIrqlToDpcLevel();
      ++v4->DismountBlockCount;
      v9 = v15;
    }
    if ( v4->DismountUnblockEvent != &DismountUnblockEvent )
      RtlAssert(
        v7,
        v8,
        0,
        (int)v4,
        "VolumeExtension->DismountUnblockEvent == &DismountUnblockEvent",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fsctrl.c",
        0x96u,
        0);
    v4->DismountUnblockEvent = 0;
    KfLowerIrql(v9);
    FscInvalidateDevice(&v4->CacheExtension);
    v16 = KeRaiseIrqlToDpcLevel();
    v4->CacheExtension.TargetDeviceObject->MountedOrSelfDevice = 0;
    KfLowerIrql(v16);
    ObfDereferenceObject(v4->CacheExtension.TargetDeviceObject, v17);
    v18 = v4->FileObjectCount;
    v4->CacheExtension.TargetDeviceObject = 0;
    FatxReleaseVolumeMutex(v4);
    if ( v18 )
    {
      if ( v18 > 2 )
        DbgPrint(0, "FATX: dismounting volume %p with %d open file handles\n", v4, v18);
    }
    else
    {
      FatxDeleteVolumeDevice(v20, v19, DeviceObject);
    }
    result = 0;
  }
  return result;
}