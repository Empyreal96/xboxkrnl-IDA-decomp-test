int __userpurge XepResolveImageImports@<eax>(int *a1@<edi>, void *ExportBaseAddress, _IMAGE_THUNK_DATA32 *ImageThunkData)
{
  char *v3; // eax
  int v4; // edx
  void *v5; // ecx
  char *v6; // ebx
  int result; // eax
  _IMAGE_THUNK_DATA32 *v8; // esi
  int *v9; // edi
  unsigned int v10; // eax
  int v11; // eax
  unsigned int ExportDirectorySize; // [esp+4h] [ebp-4h]

  v3 = RtlImageDirectoryEntryToData(ExportBaseAddress, 1, 0, &ExportDirectorySize);
  v6 = v3;
  if ( v3 )
  {
    v8 = ImageThunkData;
    v9 = (int *)((char *)ExportBaseAddress + *((_DWORD *)v3 + 7));
    while ( 1 )
    {
      if ( !v8->u1.ForwarderString )
        return 0;
      if ( (v8->u1.Ordinal & 0x80000000) == 0 )
        RtlAssert(
          v4,
          (int)v5,
          v9,
          (int)v8,
          "IMAGE_SNAP_BY_ORDINAL(ImageThunkData->u1.Ordinal)",
          "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
          0x43Bu,
          0);
      v10 = (v8->u1.ForwarderString & 0xFFFF) - *((_DWORD *)v6 + 4);
      if ( v10 >= *((_DWORD *)v6 + 5) )
        break;
      v11 = v9[v10];
      if ( !v11 )
        break;
      v5 = ExportBaseAddress;
      v8->u1.ForwarderString = (unsigned int)ExportBaseAddress + v11;
      ++v8;
    }
    DbgPrint(v9, "LDRX: cannot import ordinal %d from image %p.\n", v8->u1.ForwarderString & 0xFFFF, ExportBaseAddress);
    result = -1073741512;
  }
  else
  {
    DbgPrint(a1, "LDRX: cannot import from image %p.\n", ExportBaseAddress);
    result = -1073741512;
  }
  return result;
}