int __userpurge FatxNonCachedAsynchronousIoCompletion@<eax>(int a1@<edx>, int *a2@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, void *Context)
{
  _FAT_VOLUME_EXTENSION *v5; // ebx
  int v7; // edi
  int *v15; // [esp-4h] [ebp-Ch]

  v5 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  if ( Irp->IoStatus.Status >= 0 )
  {
    if ( *((_DWORD *)Context + 2) )
    {
      FatxStartNextAsynchronousIoEntry(v5, Irp, (_FAT_ASYNC_IO_DESCRIPTOR *)Context);
      return -1073741802;
    }
    if ( *(_DWORD *)Context == 3 )
    {
      v15 = a2;
      v7 = *((_DWORD *)Context + 5);
      if ( !(*(_BYTE *)v7 & 8) )
      {
        KeQuerySystemTime((_LARGE_INTEGER *)(v7 + 52));
        *(_BYTE *)v7 |= 0x40u;
      }
      a2 = v15;
    }
    Irp->IoStatus.Information = *((_DWORD *)Context + 1);
  }
  _EAX = -1;
  _ECX = (int)&v5->DismountBlockCount;
  __asm { xadd    [ecx], eax }
  if ( _EAX - 1 < 0 )
    FatxSignalDismountUnblockEvent(v5);
  FatxDpcReleaseFileMutex(a1, _ECX, a2, *((_FAT_FCB **)Context + 5));
  ExFreePool(Context);
  return 0;
}