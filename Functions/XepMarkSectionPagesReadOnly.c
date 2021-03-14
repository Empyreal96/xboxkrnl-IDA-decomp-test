void __fastcall XepMarkSectionPagesReadOnly(int a1, int a2, _XBEIMAGE_SECTION *Section)
{
  _XBEIMAGE_SECTION *v3; // esi
  _XBEIMAGE_SECTION *v4; // ecx
  _XBEIMAGE_SECTION *v5; // edx
  unsigned int v6; // eax
  int v7; // ecx
  bool v8; // zf
  int v9; // edx
  int v10; // ecx
  unsigned int OldProtect; // [esp+8h] [ebp-8h]
  unsigned int RegionSize; // [esp+Ch] [ebp-4h]

  v3 = Section;
  if ( !Section->SectionReferenceCount )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      (int)Section,
      "Section->SectionReferenceCount > 0",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x184u,
      0);
  if ( v3->SectionFlags & 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      (int)v3,
      "LdrxIsFlagClear(Section->SectionFlags, XBEIMAGE_SECTION_WRITEABLE)",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x185u,
      0);
  v4 = (_XBEIMAGE_SECTION *)v3->VirtualAddress;
  v5 = v4;
  v6 = (unsigned int)v4 + v3->VirtualSize;
  v7 = v3->SectionFlags;
  v8 = (v3->SectionFlags & 0x20) == 0;
  Section = v5;
  if ( v8 )
    v6 &= 0xFFFFF000;
  if ( !(v7 & 0x10) )
  {
    v5 = (_XBEIMAGE_SECTION *)((unsigned int)&v5[73].VirtualSize & 0xFFFFF000);
    Section = v5;
  }
  if ( v6 > (unsigned int)v5 )
  {
    RegionSize = v6 - (_DWORD)v5;
    if ( NtProtectVirtualMemory(
           (int)v5,
           v7,
           (int *)"d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
           -4096,
           (void **)&Section,
           &RegionSize,
           0x20u,
           &OldProtect) < 0 )
      RtlAssert(
        v9,
        v10,
        (int *)"d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
        -4096,
        "NT_SUCCESS(status)",
        "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
        0x1B1u,
        0);
  }
}