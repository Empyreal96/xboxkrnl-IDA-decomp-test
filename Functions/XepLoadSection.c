int *__fastcall XepLoadSection(int a1, int a2, void *ImageFileHandle, _XBEIMAGE_SECTION *Section, char Preloading)
{
  int *v5; // edi
  int *result; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int *v11; // esi
  signed int v12; // ecx
  char *v13; // esi
  bool v14; // zf
  int v15; // edx
  int v16; // ecx
  char SectionDigest[20]; // [esp+Ch] [ebp-14h]

  v5 = 0;
  if ( Section->SectionReferenceCount )
    RtlAssert(
      a2,
      a1,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      "Section->SectionReferenceCount == 0",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x21Fu,
      0);
  if ( Section->SizeOfRawData > Section->VirtualSize )
    RtlAssert(
      a2,
      a1,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      "Section->SizeOfRawData <= Section->VirtualSize",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x220u,
      0);
  result = XepCommitSectionPages(a2, a1, 0, Section);
  if ( (signed int)result >= 0 )
  {
    v11 = (int *)XepReadImageFile(
                   v7,
                   v8,
                   (int)"d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
                   ImageFileHandle,
                   (void *)Section->VirtualAddress,
                   Section->SizeOfRawData,
                   Section->PointerToRawData);
    if ( (signed int)v11 >= 0 )
    {
      memset(
        (void *)(Section->SizeOfRawData + Section->VirtualAddress),
        0,
        Section->VirtualSize - Section->SizeOfRawData);
      XCCalcDigest((char *)Section->VirtualAddress, Section->SizeOfRawData, SectionDigest);
      v12 = 5;
      v5 = (int *)SectionDigest;
      v13 = Section->SectionDigest;
      v14 = 1;
      do
      {
        if ( !v12 )
          break;
        v14 = *(_DWORD *)v13 == *v5;
        v13 += 4;
        ++v5;
        --v12;
      }
      while ( v14 );
      if ( v14 )
      {
        Section->SectionReferenceCount = 1;
        v11 = 0;
        if ( XepSendSectionDebugNotifications )
          DebugService(7u, Section, 0);
        goto CleanupAndExit_36;
      }
      DbgPrint(v5, "LDRX: failed to verify section digest.\n");
      DbgBreakPoint();
      v11 = (int *)-1073741424;
    }
    XepDecommitSectionPages(v10, v9, Section);
    if ( !Preloading )
    {
      DbgPrint(v5, "LDRX: failed to read section %08x (status=%08x).\n", Section, v11);
      DbgBreakPoint();
      if ( *(_DWORD *)(MEMORY[0x10118] + 8) == -131072 )
        HalReturnToFirmware(v15, v16, v5, (int)v11, HalFatalErrorRebootRoutine);
      HalHaltSystem();
    }
CleanupAndExit_36:
    result = v11;
  }
  return result;
}