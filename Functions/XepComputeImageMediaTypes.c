int __userpurge XepComputeImageMediaTypes@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *ImageFileHandle, unsigned int *ReturnedImageMediaTypes)
{
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // esi
  int result; // eax
  unsigned int v11; // eax
  char v12; // al
  char ReadStructureOutput[24]; // [esp+8h] [ebp-40h]
  DVD_READ_STRUCTURE ReadStructure; // [esp+20h] [ebp-28h]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+38h] [ebp-10h]
  _FILE_FS_DEVICE_INFORMATION DeviceInformation; // [esp+40h] [ebp-8h]

  v6 = NtQueryVolumeInformationFile(
         a1,
         a2,
         a3,
         a4,
         ImageFileHandle,
         &IoStatusBlock,
         &DeviceInformation,
         8u,
         FileFsDeviceInformation);
  v9 = v6;
  if ( v6 < 0 )
  {
    DbgPrint(a3, "LDRX: failed to query device information (status=%08x).\n", v6);
    return v9;
  }
  v11 = 2;
  if ( DeviceInformation.DeviceType != 2 )
  {
    if ( DeviceInformation.DeviceType != 7 )
      RtlAssert(
        v7,
        v8,
        a3,
        v9,
        "DeviceInformation.DeviceType == FILE_DEVICE_DISK",
        "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
        0x3B5u,
        0);
    *ReturnedImageMediaTypes = 1;
    return 0;
  }
  if ( IdexCdRomDVDX2Authenticated )
    goto LABEL_14;
  memset(&ReadStructure, 0, sizeof(ReadStructure));
  memset(ReadStructureOutput, 0, sizeof(ReadStructureOutput));
  ReadStructure.Format = 0;
  result = NtDeviceIoControlFile(
             v7,
             0,
             (int *)&ReadStructure,
             v9,
             ImageFileHandle,
             0,
             0,
             0,
             &IoStatusBlock,
             0x335140u,
             &ReadStructure,
             0x18u,
             ReadStructureOutput,
             0x18u);
  if ( result != -1073741804 )
  {
    if ( result < 0 )
      return result;
    v12 = ReadStructureOutput[6] & 0x60;
    if ( (ReadStructureOutput[6] & 0xF) == 1 )
      v11 = v12 != 0 ? 36 : 20;
    else
      v11 = v12 != 0 ? 132 : 68;
LABEL_14:
    *ReturnedImageMediaTypes = v11;
    return 0;
  }
  *ReturnedImageMediaTypes = 12;
  return 0;
}