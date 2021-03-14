int *__fastcall ExSaveNonVolatileSetting(int a1, int a2, unsigned int ValueIndex, unsigned int Type, const void *Value, unsigned int ValueLength)
{
  char *v6; // esi
  int *v7; // edi
  int v8; // edx
  int v9; // edx
  void *v10; // ecx
  int *v11; // edi
  unsigned int v13; // ecx
  _SETTING_ENTRY_INFO *v14; // ebx
  int v15; // edx
  int v16; // ecx
  void *v17; // ecx
  char *v18; // ebx
  int v19; // edx
  int v20; // ecx
  char *v21; // edx
  char *v22; // edi
  unsigned int v23; // ecx
  unsigned int v24; // esi
  _SETTING_ENTRY_INFO *v25; // [esp-Ch] [ebp-220h]
  unsigned int v26; // [esp-8h] [ebp-21Ch]
  unsigned int v27; // [esp-4h] [ebp-218h]
  char OldSettings[256]; // [esp+Ch] [ebp-208h]
  char NewSettings[256]; // [esp+10Ch] [ebp-108h]
  unsigned int SectionOffset; // [esp+20Ch] [ebp-8h]
  char SmartWrite; // [esp+213h] [ebp-1h]
  unsigned int SectionSize; // [esp+21Ch] [ebp+8h]

  v6 = (char *)Value;
  SmartWrite = 1;
  if ( !Value )
    RtlAssert(
      a2,
      a1,
      0,
      (int)Value,
      "Value != NULL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\settings.c",
      0x1DAu,
      0);
  if ( ValueIndex == 0xFFFF )
  {
    if ( ValueLength == 256 )
    {
      RtlEnterCriticalSectionAndRegion(&ExpNonVolatileSettingsLock);
      SectionOffset = 0;
      SectionSize = 256;
      qmemcpy(NewSettings, Value, sizeof(NewSettings));
      v7 = (int *)&SectionOffset;
      if ( ExpReadEEPROMSection(v8, 0, (int *)&SectionOffset, 0, 0x100u, OldSettings, 0) < 0 )
      {
LABEL_6:
        v11 = (int *)ExpWriteEEPROM(v9, (int)v10, v7, SectionOffset, SectionSize, NewSettings);
LABEL_7:
        RtlLeaveCriticalSectionAndRegion(v10, (_KEVENT *)&ExpNonVolatileSettingsLock);
        return v11;
      }
LABEL_28:
      v11 = 0;
      v24 = 0;
      if ( SectionSize )
      {
        do
        {
          LOWORD(v10) = *(_WORD *)&OldSettings[v24];
          if ( (_WORD)v10 != *(_WORD *)&NewSettings[v24] )
          {
            v11 = (int *)ExpWriteEEPROM(v9, (int)v10, v11, v24 + SectionOffset, 2u, &NewSettings[v24]);
            if ( (signed int)v11 < 0 )
              break;
          }
          v24 += 2;
        }
        while ( v24 < SectionSize );
      }
      goto LABEL_7;
    }
    return (int *)-1073741811;
  }
  if ( ValueIndex <= 0xFF )
  {
    v13 = 96;
    v27 = ValueIndex;
    v26 = 20;
    v25 = UserSettingsInfo;
    goto LABEL_11;
  }
  if ( ValueIndex != 260 )
  {
    if ( ValueIndex > 0x1FF )
    {
      SectionOffset = 0;
      SectionSize = 0;
      v14 = 0;
      goto LABEL_20;
    }
    v13 = 48;
    v27 = ValueIndex - 256;
    v26 = 5;
    v25 = FactorySettingsInfo;
LABEL_11:
    SectionOffset = v13;
    SectionSize = v13;
    v14 = ExpFindSettingInfo(v25, v26, v27);
LABEL_20:
    if ( !v14 )
      return (int *)-1073741772;
    if ( ValueLength <= (unsigned __int8)v14->Size )
    {
      RtlEnterCriticalSectionAndRegion(&ExpNonVolatileSettingsLock);
      if ( ExpReadEEPROMSection(v19, v20, 0, SectionOffset, SectionSize, OldSettings, 1) >= 0 )
      {
        qmemcpy(NewSettings, OldSettings, SectionSize);
        v6 = (char *)Value;
      }
      else
      {
        memset(NewSettings, 0, SectionSize);
        SmartWrite = 0;
      }
      v21 = &NewSettings[(unsigned __int8)v14->Offset];
      memset(v21, 0, (unsigned __int8)v14->Size);
      qmemcpy(v21, v6, 4 * (ValueLength >> 2));
      v22 = &v21[4 * (ValueLength >> 2)];
      v23 = ValueLength & 3;
      qmemcpy(v22, &v6[4 * (ValueLength >> 2)], v23);
      v7 = (int *)&v22[v23];
      *(_DWORD *)NewSettings = 0;
      *(_DWORD *)NewSettings = ~XConfigChecksum(NewSettings, SectionSize);
      if ( !SmartWrite )
        goto LABEL_6;
      goto LABEL_28;
    }
    return (int *)-1073741811;
  }
  if ( ValueLength != 4 )
    return (int *)-1073741811;
  RtlEnterCriticalSectionAndRegion(&ExpNonVolatileSettingsLock);
  v18 = ExpWriteEEPROM(v15, v16, (int *)ExpNonVolatileSettingsLock.Synchronization.RawEvent, 0x2Cu, 4u, Value);
  if ( (signed int)v18 >= 0 )
    XboxGameRegion = *(_DWORD *)Value;
  RtlLeaveCriticalSectionAndRegion(v17, (_KEVENT *)&ExpNonVolatileSettingsLock);
  return (int *)v18;
}