_SETTING_ENTRY_INFO *__stdcall ExpFindSettingInfo(_SETTING_ENTRY_INFO *Table, unsigned int Count, unsigned int Index)
{
  _SETTING_ENTRY_INFO *result; // eax

  result = Table;
  while ( Count )
  {
    --Count;
    if ( (unsigned __int8)result->Index == Index )
      return result;
    ++result;
  }
  return 0;
}