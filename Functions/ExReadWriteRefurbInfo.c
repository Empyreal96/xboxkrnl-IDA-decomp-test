int *__userpurge ExReadWriteRefurbInfo@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _XBOX_REFURB_INFO *RefurbInfo, unsigned int ValueLength, char DoWrite)
{
  int v7; // edx
  _XBOX_REFURB_INFO *v8; // edi
  char buf[512]; // [esp+8h] [ebp-228h]
  _STRING objname; // [esp+208h] [ebp-28h]
  _OBJECT_ATTRIBUTES oa; // [esp+210h] [ebp-20h]
  _IO_STATUS_BLOCK iosb; // [esp+21Ch] [ebp-14h]
  _LARGE_INTEGER offset; // [esp+224h] [ebp-Ch]
  void *disk; // [esp+22Ch] [ebp-4h]
  int *status; // [esp+23Ch] [ebp+Ch]

  if ( !RefurbInfo )
    RtlAssert(a1, a2, a3, 0, "RefurbInfo != NULL", "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\settings.c", 0x299u, 0);
  if ( ValueLength != 16 )
    return (int *)-1073741811;
  RtlInitAnsiString(&objname, "\\Device\\Harddisk0\\partition0");
  oa.ObjectName = &objname;
  oa.RootDirectory = 0;
  oa.Attributes = 64;
  status = NtOpenFile(
             a3,
             (int)RefurbInfo,
             &disk,
             (unsigned int)dword_80100000 | (DoWrite != 0 ? 0x40000000 : 0),
             &oa,
             &iosb,
             3u,
             0x10u);
  if ( (signed int)status >= 0 )
  {
    memset(buf, 0, sizeof(buf));
    v8 = (_XBOX_REFURB_INFO *)&objname;
    offset.QuadPart = 1536i64;
    if ( DoWrite )
    {
      *(_DWORD *)buf = RefurbInfo->Signature;
      *(_DWORD *)&buf[4] = RefurbInfo->PowerCycleCount;
      *(_QWORD *)&buf[8] = RefurbInfo->FirstSetTime.QuadPart;
      v8 = (_XBOX_REFURB_INFO *)&buf[16];
      *(_DWORD *)buf = 1380340290;
      status = (int *)NtWriteFile(v7, 0, (int)&RefurbInfo[1], disk, 0, 0, 0, &iosb, buf, 0x200u, &offset);
    }
    else
    {
      status = (int *)NtReadFile(v7, 0, (int)RefurbInfo, disk, 0, 0, 0, &iosb, buf, 0x200u, &offset);
      if ( (signed int)status >= 0 )
      {
        if ( *(_DWORD *)buf == 1380340290 )
        {
          RefurbInfo->Signature = 1380340290;
          RefurbInfo->PowerCycleCount = *(_DWORD *)&buf[4];
          RefurbInfo->FirstSetTime.QuadPart = *(_QWORD *)&buf[8];
        }
        else
        {
          RefurbInfo->Signature = 0;
          RefurbInfo->PowerCycleCount = 0;
          RefurbInfo->FirstSetTime.QuadPart = 0i64;
        }
        v8 = RefurbInfo + 1;
      }
    }
    NtClose((int *)v8, disk);
  }
  return status;
}