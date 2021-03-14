int *__fastcall IopMountVolume(int a1, int a2, _DEVICE_OBJECT *DeviceObject, char AllowRawMount)
{
  _DEVICE_OBJECT *v4; // esi
  int v5; // edx
  int v6; // ecx
  int *v7; // edi
  int *v8; // eax
  _KEVENT *DeviceObjecta; // [esp+14h] [ebp+8h]

  v4 = DeviceObject;
  DeviceObjecta = &DeviceObject->DeviceLock;
  KeWaitForSingleObject(a1, a2, DeviceObjecta, 0, 0, 0, 0);
  if ( v4->MountedOrSelfDevice )
  {
    v7 = 0;
    goto LABEL_13;
  }
  if ( v4->Flags & 1 )
  {
    v7 = (int *)-1073741489;
    goto LABEL_9;
  }
  if ( v4->DeviceType != 2 )
  {
    v8 = FatxMountVolume(v4);
    goto LABEL_6;
  }
  v7 = (int *)GdfxMountVolume(v4);
  if ( v7 == (int *)-1073741489 )
  {
    v8 = UdfxMountVolume(v4);
LABEL_6:
    v7 = v8;
  }
LABEL_9:
  if ( (signed int)v7 < 0 && AllowRawMount )
    v7 = RawxMountVolume(v7, v4);
LABEL_13:
  KeSetEvent(v6, v5, DeviceObjecta, 0, 0);
  return v7;
}