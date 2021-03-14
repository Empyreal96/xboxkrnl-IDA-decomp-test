int __fastcall ExQueryNonVolatileSetting(int a1, int a2, unsigned int ValueIndex, unsigned int *Type, void *Value, unsigned int ValueLength, unsigned int *ResultLength)
{
  int *v7; // edi
  _SETTING_ENTRY_INFO *v9; // ebx
  int v10; // edx
  int v11; // ecx
  int v12; // edi
  void *v13; // ecx
  unsigned int v14; // ebx
  int v15; // edx
  int v16; // ecx
  void *v17; // ecx
  _SETTING_ENTRY_INFO *v18; // [esp-10h] [ebp-118h]
  unsigned int v19; // [esp-Ch] [ebp-114h]
  unsigned int v20; // [esp-8h] [ebp-110h]
  char buf[256]; // [esp+8h] [ebp-100h]
  unsigned int SectionSize; // [esp+110h] [ebp+8h]

  v7 = 0;
  if ( !Type || !Value )
    RtlAssert(
      a2,
      a1,
      0,
      (int)Type,
      "Type != NULL && Value != NULL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\settings.c",
      0x14Fu,
      0);
  if ( ValueIndex == 260 )
  {
    if ( ResultLength )
      *ResultLength = 4;
    if ( ValueLength < 4 )
      return -1073741789;
    *Type = 4;
    *(_DWORD *)Value = XboxGameRegion;
    return 0;
  }
  if ( ValueIndex == 0xFFFF || ValueIndex == 65534 )
  {
    v14 = (unsigned __int8)(ValueIndex != 0xFFFF ? 0 : 0xD0) + 48;
    if ( ResultLength )
      *ResultLength = v14;
    if ( ValueLength < v14 )
      return -1073741789;
    *Type = 3;
    RtlEnterCriticalSectionAndRegion(&ExpNonVolatileSettingsLock);
    v12 = ExpReadEEPROMSection(v15, v16, 0, 0, v14, Value, 0);
    RtlLeaveCriticalSectionAndRegion(v17, (_KEVENT *)&ExpNonVolatileSettingsLock);
    return v12;
  }
  if ( ValueIndex <= 0xFF )
  {
    v7 = (int *)96;
    v20 = ValueIndex;
    v19 = 20;
    v18 = UserSettingsInfo;
LABEL_14:
    SectionSize = (unsigned int)v7;
    v9 = ExpFindSettingInfo(v18, v19, v20);
    goto LABEL_18;
  }
  if ( ValueIndex <= 0x1FF )
  {
    v7 = (int *)48;
    v20 = ValueIndex - 256;
    v19 = 5;
    v18 = FactorySettingsInfo;
    goto LABEL_14;
  }
  v9 = 0;
  SectionSize = 0;
LABEL_18:
  if ( !v9 )
    return -1073741772;
  RtlEnterCriticalSectionAndRegion(&ExpNonVolatileSettingsLock);
  v12 = ExpReadEEPROMSection(v10, v11, v7, (unsigned int)v7, SectionSize, buf, 1);
  RtlLeaveCriticalSectionAndRegion(v13, (_KEVENT *)&ExpNonVolatileSettingsLock);
  if ( v12 < 0 )
    return v12;
  if ( ValueLength < (unsigned __int8)v9->Size )
    return -1073741789;
  *Type = (unsigned __int8)v9->Type;
  if ( ResultLength )
    *ResultLength = (unsigned __int8)v9->Size;
  memset(Value, 0, ValueLength);
  qmemcpy(Value, &buf[(unsigned __int8)v9->Offset], (unsigned __int8)v9->Size);
  return 0;
}