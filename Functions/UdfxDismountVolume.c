int __stdcall UdfxDismountVolume(_DEVICE_OBJECT *DeviceObject)
{
  void *v1; // ecx
  void *v2; // esi
  signed int v3; // esi
  KIRQL v4; // al
  int v5; // edx
  unsigned int v6; // eax

  RtlEnterCriticalSectionAndRegion(&UdfxGlobalMutex);
  v2 = DeviceObject->DeviceExtension;
  if ( *((_BYTE *)v2 + 40) )
  {
    v3 = -1073741202;
  }
  else
  {
    *((_BYTE *)v2 + 40) = 1;
    v4 = KeRaiseIrqlToDpcLevel();
    *(_DWORD *)(*(_DWORD *)v2 + 12) = 0;
    KfLowerIrql(v4);
    v6 = *((_DWORD *)v2 + 9);
    if ( v6 )
    {
      if ( v6 > 1 )
        DbgPrint(
          (int *)UdfxGlobalMutex.Synchronization.RawEvent,
          "UDFX: dismounting volume %p with %d open file handles\n",
          v2,
          *((_DWORD *)v2 + 9));
    }
    else
    {
      UdfxDeleteVolumeDevice((int)v1, v5, DeviceObject);
    }
    v3 = 0;
  }
  RtlLeaveCriticalSectionAndRegion(v1, (_KEVENT *)&UdfxGlobalMutex);
  return v3;
}