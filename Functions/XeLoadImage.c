int *__userpurge XeLoadImage@<eax>(int *a1@<edi>, const char *ImageFileName, char LoadingDashboard, unsigned int SettingsError)
{
  const char *v4; // esi
  const char *v5; // ecx
  char v6; // dl
  unsigned int v7; // ebx
  int *v8; // eax
  _XBEIMAGE_CERTIFICATE *v9; // edx
  _XBEIMAGE_SECTION *v10; // ecx
  int *v11; // esi
  int *v12; // edi
  const char *v13; // esi
  int v14; // ecx
  bool v15; // zf
  int *v16; // edi
  int v17; // esi
  int *v18; // eax
  const char **v19; // ebx
  int *v20; // edi
  unsigned int v21; // ecx
  unsigned int v22; // eax
  int *v23; // edi
  unsigned int v24; // edx
  int v25; // ecx
  _XBEIMAGE_SECTION *v26; // ST1C_4
  _XBEIMAGE_SECTION *v27; // ebx
  _XBEIMAGE_SECTION *v28; // edi
  int v29; // edx
  int v30; // ecx
  _XBEIMAGE_SECTION *v31; // edi
  _XBEIMAGE_SECTION *v32; // esi
  unsigned int v33; // eax
  _XBEIMAGE_LIBRARY_VERSION *v34; // eax
  _XBEIMAGE_LIBRARY_VERSION *v35; // ebx
  _XBEIMAGE_LIBRARY_VERSION *v36; // esi
  _XBEIMAGE_LIBRARY_VERSION *i; // edi
  signed int v38; // esi
  unsigned int v39; // eax
  _XBEIMAGE_SECTION *v41; // [esp-Ch] [ebp-34h]
  _XBEIMAGE_SECTION *v42; // [esp-Ch] [ebp-34h]
  _XBEIMAGE_SECTION *v43; // [esp-Ch] [ebp-34h]
  int *v44; // [esp-8h] [ebp-30h]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+4h] [ebp-24h]
  _LARGE_INTEGER ByteOffset; // [esp+Ch] [ebp-1Ch]
  _XBEIMAGE_CERTIFICATE *Certificate; // [esp+14h] [ebp-14h]
  char *PublicKeyData; // [esp+18h] [ebp-10h]
  void *BaseAddress; // [esp+1Ch] [ebp-Ch]
  void *ImageFileHandle; // [esp+20h] [ebp-8h]
  char ReleaseBaseAddress; // [esp+27h] [ebp-1h]

  ImageFileHandle = 0;
  v4 = ImageFileName;
  ReleaseBaseAddress = 0;
  v5 = ImageFileName + 1;
  v7 = strlen(ImageFileName);
  if ( v7 > 0xFFFF )
    RtlAssert(
      0,
      (int)v5,
      a1,
      (int)ImageFileName,
      "ImageFileNameLength <= USHRT_MAX",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x5CBu,
      0);
  v8 = ExAllocatePoolWithTag(v6, (int)v5, (int)v4, v7, 0x6E466558u);
  XeImageFileName.Buffer = (char *)v8;
  if ( !v8 )
  {
    v11 = (int *)-1073741670;
    goto LABEL_99;
  }
  v44 = a1;
  qmemcpy(v8, v4, 4 * (v7 >> 2));
  v13 = &v4[4 * (v7 >> 2)];
  v12 = &v8[v7 >> 2];
  v14 = v7 & 3;
  v15 = SettingsError == 0;
  qmemcpy(v12, v13, v14);
  v17 = (int)&v13[v14];
  v16 = (int *)((char *)v12 + v14);
  v10 = 0;
  XeImageFileName.Length = v7;
  XeImageFileName.MaximumLength = v7;
  if ( !v15 )
    goto LABEL_6;
  v11 = XepOpenImageFile(v16, v17, &ImageFileHandle);
  if ( (signed int)v11 < 0 )
    goto LABEL_98;
  v18 = ExAllocatePoolWithTag((unsigned __int8)v9, (int)v10, 4096, 0x1000u, 0x68496558u);
  v19 = (const char **)v18;
  v20 = 0;
  if ( !v18 )
  {
    v11 = (int *)-1073741670;
    goto CleanupAndExit_39;
  }
  ByteOffset.QuadPart = 0i64;
  v11 = (int *)NtReadFile((int)v9, (int)v10, 4096, ImageFileHandle, 0, 0, 0, &IoStatusBlock, v18, 0x1000u, &ByteOffset);
  if ( (signed int)v11 < 0 )
    goto CleanupAndExit_39;
  if ( IoStatusBlock.Information < 0x178 )
  {
    DbgPrint(0, "LDRX: image too small.\n");
LABEL_95:
    v10 = v41;
    v11 = (int *)-1073741701;
    goto CleanupAndExit_39;
  }
  if ( *v19 != (const char *)1212498520
    || (v21 = (unsigned int)v19[66], v21 <= 0x178)
    || v21 > (unsigned int)v19[67]
    || (v20 = (int *)0x10000, v19[65] != (const char *)0x10000) )
  {
    DbgPrint(v20, "LDRX: invalid image header.\n");
    goto LABEL_95;
  }
  BaseAddress = (void *)0x10000;
  ImageFileName = v19[67];
  v11 = (int *)NtAllocateVirtualMemory(
                 (int)v9,
                 v21,
                 (int *)0x10000,
                 (int)v11,
                 &BaseAddress,
                 0,
                 (unsigned int *)&ImageFileName,
                 0x2000u,
                 4u);
  if ( (signed int)v11 < 0
    || (BaseAddress = (void *)0x10000,
        ImageFileName = v19[66],
        ReleaseBaseAddress = 1,
        v11 = (int *)NtAllocateVirtualMemory(
                       (int)v9,
                       (int)v10,
                       (int *)0x10000,
                       (int)v11,
                       &BaseAddress,
                       0,
                       (unsigned int *)&ImageFileName,
                       0x1000u,
                       4u),
        (signed int)v11 < 0) )
  {
CleanupAndExit_39:
    if ( v19 )
      ExFreePool(v19);
    goto LABEL_98;
  }
  qmemcpy((void *)0x10000, v19, 0x1000u);
  ExFreePool(v19);
  if ( MEMORY[0x10108] > 0x1000u )
  {
    v11 = (int *)XepReadImageFile(
                   (int)v9,
                   4096,
                   (int)(v19 + 1024),
                   ImageFileHandle,
                   (void *)0x11000,
                   MEMORY[0x10108] - 4096,
                   0x1000u);
    if ( (signed int)v11 < 0 )
      goto LABEL_98;
  }
  v10 = (_XBEIMAGE_SECTION *)0x10000;
  v22 = MEMORY[0x10108] + 0x10000;
  if ( MEMORY[0x10118] < 0x10000u
    || (v9 = (_XBEIMAGE_CERTIFICATE *)(MEMORY[0x10118] + 464), MEMORY[0x10118] + 464 > v22)
    || (unsigned int)MEMORY[0x10120] < 0x10000
    || (v10 = &MEMORY[0x10120][MEMORY[0x1011C]], (unsigned int)v10 > v22) )
  {
    v11 = (int *)-1073741701;
    goto LABEL_98;
  }
  v11 = (int *)XepVerifyImageHeaderEncryptedDigest(LoadingDashboard, &PublicKeyData);
  if ( (signed int)v11 < 0 )
  {
    DbgPrint((int *)0x11000, "LDRX: failed to verify header digest.\n");
LABEL_27:
    v10 = v42;
    goto LABEL_98;
  }
  v23 = (int *)MEMORY[0x10118];
  v24 = *(_DWORD *)(MEMORY[0x10118] + 160);
  v25 = *((_DWORD *)PublicKeyData + 32) ^ *((_DWORD *)PublicKeyData + 36);
  Certificate = (_XBEIMAGE_CERTIFICATE *)MEMORY[0x10118];
  SettingsError = v24;
  MEMORY[0x10128] = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))((unsigned int)MEMORY[0x10128] ^ v25);
  MEMORY[0x10158] = (_IMAGE_THUNK_DATA32 *)((unsigned int)MEMORY[0x10158] ^ *((_DWORD *)PublicKeyData + 33) ^ *((_DWORD *)PublicKeyData + 34));
  if ( (XboxGameRegion & 0x80000000) != 0 )
  {
    v24 &= 0x80000000;
    SettingsError = v24;
  }
  if ( !(XboxGameRegion & v24) )
  {
    DbgPrint(MEMORY[0x10118], "LDRX: game region mismatch; cannot run image.\n");
    v10 = v26;
    v11 = (int *)-1073414143;
    goto LABEL_98;
  }
  v11 = (int *)XepComputeImageMediaTypes(
                 v24,
                 2147483648,
                 MEMORY[0x10118],
                 (int)v11,
                 ImageFileHandle,
                 (unsigned int *)&PublicKeyData);
  if ( (signed int)v11 < 0 )
  {
    DbgPrint(v23, "LDRX: failed to compute media types.\n");
    goto LABEL_27;
  }
  if ( !((unsigned int)PublicKeyData & v23[39]) )
  {
    DbgPrint(v23, "LDRX: media types mismatch; cannot run image.\n");
LABEL_36:
    v10 = v43;
    v11 = (int *)-1073414142;
    goto LABEL_98;
  }
  if ( (unsigned __int8)PublicKeyData & 2 )
  {
    if ( XeCdRomMediaTimeDateStamp && XeCdRomMediaTimeDateStamp != v23[1] )
    {
      DbgPrint(v23, "LDRX: time stamp mismatch; cannot run image.\n");
      goto LABEL_36;
    }
    XeCdRomMediaTimeDateStamp = v23[1];
  }
  if ( !KeHasQuickBooted )
    AniSetLogo((int)v10, (int)v9, MEMORY[0x10170], MEMORY[0x10174]);
  v27 = MEMORY[0x10120];
  v28 = &MEMORY[0x10120][MEMORY[0x1011C]];
  while ( v27 < v28 )
  {
    if ( v27->SectionFlags & 2 )
    {
      v11 = XepLoadSection((int)v10, (int)v9, ImageFileHandle, v27, 1);
      if ( (signed int)v11 < 0 )
        goto LABEL_98;
    }
    ++v27;
  }
  if ( !HalEnableTrayEjectRequiresReboot((int)v9, (int)v10, (int *)v28, (int)v11, LoadingDashboard) )
    goto LABEL_108;
  if ( KeHasQuickBooted )
    RtlAssert(
      (unsigned __int8)v9,
      (int)v10,
      (int *)v28,
      (int)v11,
      "!KeHasQuickBooted",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x712u,
      0);
  if ( !(XboxBootFlags & 8) )
    RtlAssert(
      (unsigned __int8)v9,
      (int)v10,
      (int *)v28,
      (int)v11,
      "LdrxIsFlagSet(XboxBootFlags, XBOX_BOOTFLAG_NONSECUREMODE)",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x713u,
      0);
  if ( LoadingDashboard )
  {
LABEL_108:
    if ( MEMORY[0x10158] )
    {
      v11 = (int *)XepResolveImageImports((int *)v28, osfile, MEMORY[0x10158]);
      if ( (signed int)v11 < 0 )
        goto LABEL_98;
    }
    if ( MEMORY[0x1015C] )
    {
      v11 = (int *)XepResolveNonKernelImageImports((int)v9, (int)v10, (int *)v28);
      if ( (signed int)v11 < 0 )
        goto LABEL_98;
    }
    XepNotifyDebuggerOfImageLoad();
    v31 = MEMORY[0x10120];
    v32 = &MEMORY[0x10120][MEMORY[0x1011C]];
    while ( v31 < v32 )
    {
      v33 = v31->SectionFlags;
      if ( v31->SectionFlags & 2 && !(v33 & 1) )
        XepMarkSectionPagesReadOnly(v30, v29, v31);
      ++v31;
    }
    DbgPrint((int *)v31, "Xbox image loaded: %Z\n");
    v34 = MEMORY[0x10164];
    v35 = 0;
    v36 = &MEMORY[0x10164][MEMORY[0x10160]];
    while ( v34 < v36 )
    {
      if ( *((_BYTE *)v34 + 15) & 0x10 )
      {
        v35 = v34;
        XepPrintLibraryVersion(v34);
        break;
      }
      ++v34;
    }
    for ( i = MEMORY[0x10164]; i < v36; ++i )
    {
      if ( i != v35 )
        XepPrintLibraryVersion(i);
    }
    if ( !(MEMORY[0x10124] & 4) )
      MmReleaseDeveloperKitMemory();
    XepExtractCertificateKeys();
    v10 = (_XBEIMAGE_SECTION *)-2147483648;
    if ( (SettingsError & 0x80000000) == 0 )
    {
      *(_DWORD *)XboxEEPROMKey = 0;
      *(_DWORD *)&XboxEEPROMKey[4] = 0;
      *(_DWORD *)&XboxEEPROMKey[8] = 0;
      *(_DWORD *)&XboxEEPROMKey[12] = 0;
      i = (_XBEIMAGE_LIBRARY_VERSION *)&XboxEEPROMKey[16];
    }
    v38 = 0;
    if ( LoadingDashboard
      || (v9 = Certificate, Certificate->AllowedMediaTypes & 0x80000000)
      || XboxBootFlags & 4
      || XboxGameRegion & 0x80000000 )
    {
      if ( KeHasQuickBooted || XboxBootFlags & 8 )
        goto LABEL_92;
      v39 = XboxBootFlags | 8;
      v38 = 1;
    }
    else
    {
      if ( KeHasQuickBooted && !(XboxBootFlags & 8) )
        goto LABEL_92;
      v39 = XboxBootFlags & 0xFFFFFFF7;
    }
    XboxBootFlags = v39;
    while ( HalWriteSMBusValue((int)v9, (int)v10, (int *)i->LibraryName, v38, 32, 25, 0, v38) < 0 )
      ;
LABEL_92:
    v11 = 0;
    goto LABEL_98;
  }
LABEL_6:
  v11 = (int *)-1073741766;
LABEL_98:
  a1 = v44;
LABEL_99:
  if ( ImageFileHandle )
    NtClose(a1, ImageFileHandle);
  if ( (signed int)v11 < 0 )
  {
    if ( ReleaseBaseAddress )
    {
      ImageFileName = 0;
      BaseAddress = (void *)0x10000;
      NtFreeVirtualMemory((int)v9, (int)v10, a1, (int)v11, &BaseAddress, (unsigned int *)&ImageFileName, 0x8000u);
    }
    RtlFreeAnsiString(&XeImageFileName);
  }
  return v11;
}