void __usercall ExpTryToBootMediaROM(int *a1@<edi>)
{
  int v1; // edx
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  void *v5; // eax
  int v6; // edx
  int v7; // ecx
  char *v8; // esi
  _DWORD *v9; // edi
  char v10; // al
  const char *v11; // esi
  char v12; // al
  _DWORD *v13; // edi
  int v14; // esi
  int *v15; // edi
  int v16; // edx
  _DWORD *v17; // edi
  char v18; // al
  _DWORD *v19; // edi
  void (__thiscall *v20)(unsigned int); // esi
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  unsigned int v24; // eax
  int v25; // edx
  int v26; // ST1C_4
  int v27; // edx
  int v28; // ecx
  char *v29; // [esp-8h] [ebp-13Ch]
  RC4_KEYSTRUCT RC4KeyStruct; // [esp+8h] [ebp-12Ch]
  int status; // [esp+10Ch] [ebp-28h]
  _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+110h] [ebp-24h]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+11Ch] [ebp-18h]
  void *ROMShadow; // [esp+124h] [ebp-10h]
  void *RelocatedBootLoader; // [esp+128h] [ebp-Ch]
  void *FileHandle; // [esp+12Ch] [ebp-8h]
  char LoadedFromCdRom; // [esp+133h] [ebp-1h]

  LoadedFromCdRom = 1;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = &ExpCdRomBootROMString;
  if ( (signed int)NtOpenFile(a1, 2147483648, &FileHandle, 0x80000000, &ObjectAttributes, &IoStatusBlock, 0, 0x68u) >= 0
    || (LoadedFromCdRom = 0,
        ObjectAttributes.ObjectName = &ExpHardDiskBootROMString,
        (signed int)NtOpenFile(a1, 2147483648, &FileHandle, 0x80000000, &ObjectAttributes, &IoStatusBlock, 0, 0x68u) >= 0) )
  {
    RelocatedBootLoader = (void *)MmAllocateContiguousMemoryEx(v1, v2, 2147483648, 0x6000u, 0x400000u, 0x405FFFu, 0, 4u);
    if ( !RelocatedBootLoader )
    {
      DbgPrint((int *)0x6000, "INIT: failed to allocate boot loader memory.\n");
LABEL_5:
      NtClose((int *)0x6000, FileHandle);
      return;
    }
    v5 = (void *)MmAllocateContiguousMemoryEx(v3, v4, 0x100000, 0x100000u, 0, 0x3000000u, 0, 4u);
    ROMShadow = v5;
    if ( !v5 )
    {
      DbgPrint((int *)0x6000, "INIT: failed to allocate shadow ROM memory.\n");
      goto LABEL_5;
    }
    status = NtReadFile(v6, v7, 0x100000, FileHandle, 0, 0, 0, &IoStatusBlock, v5, 0x100000u, 0);
    NtClose((int *)0x6000, FileHandle);
    if ( status < 0 || IoStatusBlock.Information != 0x100000 )
    {
      DbgPrint((int *)0x6000, "INIT: failed to read ROM from media.\n");
      MmFreeContiguousMemory(v25, v26, (int *)0x6000, ROMShadow);
      MmFreeContiguousMemory(v27, v28, (int *)0x6000, RelocatedBootLoader);
    }
    else
    {
      rc4_key((int)&RC4KeyStruct, 0x10u, ExpBldrEncryptionKey);
      v8 = (char *)ROMShadow + 1023488;
      rc4((int)&RC4KeyStruct, 0x6000u, (_BYTE *)ROMShadow + 1023488);
      qmemcpy(RelocatedBootLoader, v8, 0x6000u);
      v9 = (_DWORD *)-2143289341;
      if ( LoadedFromCdRom )
      {
        do
        {
          v10 = *((_BYTE *)v9 + 1);
          v9 = (_DWORD *)((char *)v9 + 1);
        }
        while ( v10 );
        v11 = " /SHADOW /CDBOOT";
        v29 = "INIT: loaded kernel image from CD-ROM.\n";
      }
      else
      {
        do
        {
          v12 = *((_BYTE *)v9 + 1);
          v9 = (_DWORD *)((char *)v9 + 1);
        }
        while ( v12 );
        v11 = " /SHADOW /HDBOOT";
        v29 = "INIT: loaded kernel image from hard disk.\n";
      }
      *v9 = *(_DWORD *)v11;
      v14 = (int)(v11 + 4);
      v13 = v9 + 1;
      *v13 = *(_DWORD *)v14;
      v14 += 4;
      ++v13;
      *v13 = *(_DWORD *)v14;
      v14 += 4;
      ++v13;
      *v13 = *(_DWORD *)v14;
      ++v13;
      *(_BYTE *)v13 = *(_BYTE *)(v14 + 4);
      v15 = (_DWORD *)((char *)v13 + 1);
      DbgPrint(v15, v29);
      if ( (XboxBootFlags & 0x80u) != 0 )
      {
        v17 = (_DWORD *)-2143289341;
        do
        {
          v18 = *((_BYTE *)v17 + 1);
          v17 = (_DWORD *)((char *)v17 + 1);
        }
        while ( v18 );
        *v17 = *(_DWORD *)" /DBBOOT";
        v19 = v17 + 1;
        *v19 = *(_DWORD *)"BOOT";
        ++v19;
        *(_BYTE *)v19 = aDbboot_0[8];
        v15 = (_DWORD *)((char *)v19 + 1);
      }
      v20 = (void (__thiscall *)(unsigned int))(*(_DWORD *)((char *)RelocatedBootLoader
                                                          + *(_DWORD *)RelocatedBootLoader
                                                          - 589828)
                                              + 2147483648);
      AniSetLogo(*(_DWORD *)RelocatedBootLoader, v16, 0, 0);
      AniTerminateAnimation(v21, v22, v15, (int)v20);
      DbgUnLoadImageSymbols(0, (void *)0xFFFFFFFF, 0);
      v24 = MmGetPhysicalAddress(v23, v15, ROMShadow);
      v20(v24);
    }
  }
}