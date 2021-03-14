int __stdcall RawxDismountVolume(_DEVICE_OBJECT *DeviceObject)
{
  _RAW_VOLUME_EXTENSION *v1; // esi
  int result; // eax
  KIRQL v3; // al
  int v4; // edx
  int *v5; // edi
  int v6; // edx
  int v7; // ecx

  v1 = (_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  RawxAcquireVolumeMutexExclusive((_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension);
  if ( v1->Dismounted )
  {
    RawxReleaseVolumeMutex(v1);
    result = -1073741202;
  }
  else
  {
    v1->Dismounted = 1;
    v3 = KeRaiseIrqlToDpcLevel();
    v1->TargetDeviceObject->MountedOrSelfDevice = 0;
    KfLowerIrql(v3);
    ObfDereferenceObject(v1->TargetDeviceObject, v4);
    v1->TargetDeviceObject = 0;
    v5 = (int *)(unsigned __int8)v1->ShareAccess.OpenCount;
    RawxReleaseVolumeMutex(v1);
    if ( v5 )
    {
      if ( (unsigned int)v5 > 2 )
        DbgPrint(v5, "RAWX: dismounting volume %p with %d open file handles\n", v1, v5);
    }
    else
    {
      RawxDeleteVolumeDevice(v7, v6, DeviceObject);
    }
    result = 0;
  }
  return result;
}