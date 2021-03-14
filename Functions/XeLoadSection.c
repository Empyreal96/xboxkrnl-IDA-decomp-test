int *__stdcall XeLoadSection(_XBEIMAGE_SECTION *Section)
{
  int *v1; // edi
  void *v2; // ecx
  unsigned int v3; // eax
  int v4; // edx
  int v5; // edx
  void *ImageFileHandle; // [esp+Ch] [ebp-4h]

  v1 = 0;
  ImageFileHandle = 0;
  RtlEnterCriticalSectionAndRegion(&XepLoaderLock);
  v3 = Section->SectionReferenceCount;
  if ( v3 <= 0 )
  {
    v1 = XepOpenImageFile(0, (int)Section, &ImageFileHandle);
    if ( (signed int)v1 >= 0 )
    {
      v1 = XepLoadSection((int)v2, v4, ImageFileHandle, Section, 0);
      if ( (signed int)v1 >= 0 && !(Section->SectionFlags & 1) )
        XepMarkSectionPagesReadOnly((int)v2, v5, Section);
    }
  }
  else
  {
    Section->SectionReferenceCount = v3 + 1;
  }
  if ( ImageFileHandle )
    NtClose(v1, ImageFileHandle);
  RtlLeaveCriticalSectionAndRegion(v2, (_KEVENT *)&XepLoaderLock);
  return v1;
}