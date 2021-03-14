_DEVICE_OBJECT *__usercall IdexDiskCreateQuick@<eax>(int *a1@<edi>)
{
  signed int v1; // eax
  signed int v2; // eax
  int *v3; // eax
  char *v4; // ecx
  unsigned __int64 v5; // rax
  _DEVICE_OBJECT *result; // eax
  _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+4h] [ebp-18h]
  void *DiskDirectoryHandle; // [esp+10h] [ebp-Ch]
  void *DiskDirectoryObject; // [esp+14h] [ebp-8h]
  _DEVICE_OBJECT *DiskDeviceObject; // [esp+18h] [ebp-4h]

  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 80;
  ObjectAttributes.ObjectName = &IdexDiskDirectoryName;
  v1 = ObCreateObject(&IdexDiskDirectoryObjectType, &ObjectAttributes, 0, &DiskDirectoryObject);
  if ( v1 < 0 )
    IdexBugCheckWorker(0x30760u, v1);
  v2 = ObInsertObject(DiskDirectoryObject, &ObjectAttributes, 0, &DiskDirectoryHandle);
  if ( v2 < 0 )
    IdexBugCheckWorker(0x30767u, v2);
  NtClose(a1, DiskDirectoryHandle);
  v3 = IoCreateDevice(a1, 0, &IdexDiskDriverObject, 0x24u, 0, 7u, 0, &DiskDeviceObject);
  if ( (signed int)v3 < 0 )
    IdexBugCheckWorker(0x30774u, (unsigned int)v3);
  DiskDeviceObject->Flags |= 0x44u;
  DiskDeviceObject->Flags |= 1u;
  DiskDeviceObject->AlignmentRequirement = 1;
  DiskDeviceObject->SectorSize = 512;
  v4 = (char *)DiskDeviceObject->DeviceExtension;
  *(_DWORD *)v4 = DiskDeviceObject;
  v5 = (unsigned __int64)IdexDiskUserAddressableSectors << 9;
  *((_DWORD *)v4 + 6) = 0;
  *(_QWORD *)(v4 + 12) = v5;
  DiskDeviceObject->Flags &= 0xFFFFFFEF;
  result = DiskDeviceObject;
  IdexDiskPartitionArray[0] = DiskDeviceObject;
  return result;
}