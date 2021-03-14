int *__userpurge XepCommitSectionPages@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _XBEIMAGE_SECTION *Section)
{
  _XBEIMAGE_SECTION *v4; // esi
  int *v5; // edi
  int *result; // eax
  void *BaseAddress; // [esp+8h] [ebp-4h]

  v4 = Section;
  BaseAddress = (void *)Section->VirtualAddress;
  Section = (_XBEIMAGE_SECTION *)Section->VirtualSize;
  v5 = (int *)NtAllocateVirtualMemory(a1, a2, a3, (int)v4, &BaseAddress, 0, (unsigned int *)&Section, 0x1000u, 0x40u);
  if ( (signed int)v5 >= 0 )
  {
    ++*v4->HeadSharedPageReferenceCount;
    ++*v4->TailSharedPageReferenceCount;
    result = 0;
  }
  else
  {
    DbgPrint(v5, "LDRX: failed to commit memory for section %s (size=%08x).\n", v4->SectionName, v4->VirtualSize);
    result = v5;
  }
  return result;
}