void __userpurge FatxQueryNetworkOpenInformation(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FILE_OBJECT *FileObject, _FILE_NETWORK_OPEN_INFORMATION *NetworkOpenInformation)
{
  char *v5; // edi
  _LARGE_INTEGER v6; // rax
  unsigned __int8 v7; // al

  v5 = (char *)FileObject->FsContext;
  if ( *v5 & 1 )
    RtlAssert(
      a1,
      a2,
      (int *)v5,
      a3,
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x2Fu,
      0);
  NetworkOpenInformation->CreationTime = FatxFatTimestampToTime((_FAT_TIME_STAMP *)v5 + 15);
  NetworkOpenInformation->LastAccessTime = FatxFatTimestampToTime((_FAT_TIME_STAMP *)v5 + 16);
  v6 = FatxRoundToFatTime((_LARGE_INTEGER *)(v5 + 52));
  NetworkOpenInformation->LastWriteTime.LowPart = v6.LowPart;
  NetworkOpenInformation->ChangeTime.LowPart = v6.LowPart;
  NetworkOpenInformation->LastWriteTime.HighPart = v6.HighPart;
  NetworkOpenInformation->ChangeTime.HighPart = v6.HighPart;
  v7 = v5[3];
  if ( v7 )
    NetworkOpenInformation->FileAttributes = v7;
  else
    NetworkOpenInformation->FileAttributes = 128;
  if ( *v5 & 2 )
  {
    NetworkOpenInformation->AllocationSize.QuadPart = 0i64;
    NetworkOpenInformation->EndOfFile.LowPart = 0;
  }
  else
  {
    NetworkOpenInformation->AllocationSize.QuadPart = *((unsigned int *)v5 + 9);
    NetworkOpenInformation->EndOfFile.LowPart = *((_DWORD *)v5 + 9);
  }
  NetworkOpenInformation->EndOfFile.HighPart = 0;
}