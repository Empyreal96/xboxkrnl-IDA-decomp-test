void __stdcall FatxSignalDismountUnblockEvent(_FAT_VOLUME_EXTENSION *VolumeExtension)
{
  int v1; // edx
  int v2; // ecx
  KIRQL v3; // bl
  _KEVENT *v4; // eax

  v3 = KeRaiseIrqlToDpcLevel();
  v4 = VolumeExtension->DismountUnblockEvent;
  if ( v4 )
    KeSetEvent(v2, v1, v4, 0, 0);
  KfLowerIrql(v3);
}