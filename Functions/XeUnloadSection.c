int __stdcall XeUnloadSection(_XBEIMAGE_SECTION *Section)
{
  int v1; // edx
  void *v2; // ecx
  unsigned int v3; // eax
  signed int v4; // esi
  unsigned int v5; // eax

  RtlEnterCriticalSectionAndRegion(&XepLoaderLock);
  v3 = Section->SectionReferenceCount;
  if ( v3 )
  {
    v5 = v3 - 1;
    Section->SectionReferenceCount = v5;
    if ( !v5 )
    {
      if ( XepSendSectionDebugNotifications )
        DebugService(8u, Section, 0);
      XepDecommitSectionPages((int)v2, v1, Section);
    }
    v4 = 0;
  }
  else
  {
    v4 = -1073741811;
  }
  RtlLeaveCriticalSectionAndRegion(v2, (_KEVENT *)&XepLoaderLock);
  return v4;
}