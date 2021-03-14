void __stdcall GdfxQueryNetworkOpenInformation(_GDF_VOLUME_EXTENSION *VolumeExtension, _FILE_OBJECT *FileObject, _FILE_NETWORK_OPEN_INFORMATION *NetworkOpenInformation)
{
  unsigned int *v3; // esi
  unsigned int v4; // ecx
  int v5; // edx

  v3 = (unsigned int *)FileObject->FsContext;
  v4 = VolumeExtension->TimeStamp.LowPart;
  v5 = VolumeExtension->TimeStamp.HighPart;
  NetworkOpenInformation->CreationTime.LowPart = v4;
  NetworkOpenInformation->CreationTime.HighPart = v5;
  NetworkOpenInformation->LastAccessTime.LowPart = v4;
  NetworkOpenInformation->LastAccessTime.HighPart = v5;
  NetworkOpenInformation->LastWriteTime.LowPart = v4;
  NetworkOpenInformation->LastWriteTime.HighPart = v5;
  NetworkOpenInformation->ChangeTime.LowPart = v4;
  NetworkOpenInformation->ChangeTime.HighPart = v5;
  if ( v3[8] & 2 )
  {
    NetworkOpenInformation->FileAttributes = 17;
    NetworkOpenInformation->AllocationSize.QuadPart = 0i64;
    NetworkOpenInformation->EndOfFile.LowPart = 0;
  }
  else
  {
    NetworkOpenInformation->FileAttributes = 1;
    NetworkOpenInformation->AllocationSize.QuadPart = v3[1];
    NetworkOpenInformation->EndOfFile.LowPart = v3[1];
  }
  NetworkOpenInformation->EndOfFile.HighPart = 0;
}