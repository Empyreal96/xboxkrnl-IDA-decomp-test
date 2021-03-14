void __stdcall UdfxQueryNetworkOpenInformation(_FILE_OBJECT *FileObject, _FILE_NETWORK_OPEN_INFORMATION *NetworkOpenInformation)
{
  _FILE_NETWORK_OPEN_INFORMATION *v2; // esi
  char *v3; // edi
  _LARGE_INTEGER v4; // rax
  int v5; // eax

  v2 = NetworkOpenInformation;
  v3 = (char *)FileObject->FsContext;
  v4 = UdfxUdfTimestampToTime((TIMESTAMP *)(v3 + 16));
  NetworkOpenInformation->ChangeTime.LowPart = v4.LowPart;
  NetworkOpenInformation->LastWriteTime = v4;
  v2->LastAccessTime.LowPart = v2->ChangeTime.LowPart;
  NetworkOpenInformation->LastAccessTime.HighPart = v4.HighPart;
  v2->CreationTime.LowPart = v2->ChangeTime.LowPart;
  NetworkOpenInformation->ChangeTime.HighPart = v4.HighPart;
  NetworkOpenInformation->CreationTime.HighPart = v4.HighPart;
  if ( *v3 & 2 )
  {
    v5 = 0;
    NetworkOpenInformation->FileAttributes = 17;
    NetworkOpenInformation->AllocationSize.QuadPart = 0i64;
    NetworkOpenInformation->EndOfFile.LowPart = 0;
  }
  else
  {
    NetworkOpenInformation->FileAttributes = 1;
    NetworkOpenInformation->AllocationSize.QuadPart = *((_QWORD *)v3 + 1);
    NetworkOpenInformation->EndOfFile.LowPart = *((_DWORD *)v3 + 2);
    v5 = *((_DWORD *)v3 + 3);
  }
  NetworkOpenInformation->EndOfFile.HighPart = v5;
}