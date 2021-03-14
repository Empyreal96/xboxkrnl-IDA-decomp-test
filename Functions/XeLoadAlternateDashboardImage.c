int *__usercall XeLoadAlternateDashboardImage@<eax>(int *a1@<edi>, int a2@<esi>)
{
  int *result; // eax
  int v3; // edx
  int v4; // ecx
  int *v5; // edi
  char *v6; // eax
  char RedirectionBuffer[361]; // [esp+4h] [ebp-184h]
  _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+170h] [ebp-18h]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+17Ch] [ebp-Ch]
  void *RedirectionFileHandle; // [esp+184h] [ebp-4h]

  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = &XepDashboardRedirectionPath;
  result = NtOpenFile(a1, a2, &RedirectionFileHandle, 0x80000000, &ObjectAttributes, &IoStatusBlock, 1u, 0x60u);
  if ( (signed int)result >= 0 )
  {
    v5 = (int *)NtReadFile(v3, v4, 360, RedirectionFileHandle, 0, 0, 0, &IoStatusBlock, RedirectionBuffer, 0x168u, 0);
    NtClose(v5, RedirectionFileHandle);
    if ( (signed int)v5 >= 0 )
    {
      if ( IoStatusBlock.Information == 360 )
      {
        RedirectionBuffer[360] = 0;
        v6 = strchr(RedirectionBuffer, 59);
        if ( v6 )
          *v6 = 92;
        result = XeLoadImage(v5, RedirectionBuffer, 1, 0);
      }
      else
      {
        result = (int *)-1073741566;
      }
    }
    else
    {
      result = v5;
    }
  }
  return result;
}