void __fastcall XepDecommitSectionPages(int a1, int a2, _XBEIMAGE_SECTION *Section)
{
  _XBEIMAGE_SECTION *v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax
  _XBEIMAGE_SECTION *v6; // ecx
  unsigned int RegionSize; // [esp+Ch] [ebp-4h]

  v3 = Section;
  if ( !*Section->HeadSharedPageReferenceCount )
    RtlAssert(
      a2,
      a1,
      0,
      (int)Section,
      "*Section->HeadSharedPageReferenceCount > 0",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x1CDu,
      0);
  if ( *v3->TailSharedPageReferenceCount <= 0u )
    RtlAssert(
      a2,
      a1,
      0,
      (int)v3,
      "*Section->TailSharedPageReferenceCount > 0",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x1CEu,
      0);
  v4 = v3->VirtualSize;
  Section = (_XBEIMAGE_SECTION *)v3->VirtualAddress;
  v5 = (unsigned int)Section + v4;
  --*v3->HeadSharedPageReferenceCount;
  if ( --*v3->TailSharedPageReferenceCount )
    v5 &= 0xFFFFF000;
  v6 = Section;
  if ( *v3->HeadSharedPageReferenceCount )
  {
    v6 = (_XBEIMAGE_SECTION *)((unsigned int)&Section[73].VirtualSize & 0xFFFFF000);
    Section = (_XBEIMAGE_SECTION *)((unsigned int)&Section[73].VirtualSize & 0xFFFFF000);
  }
  if ( v5 > (unsigned int)v6 )
  {
    RegionSize = v5 - (_DWORD)v6;
    NtFreeVirtualMemory(-4096, (int)v6, 0, (int)v3, (void **)&Section, &RegionSize, 0x4000u);
  }
}