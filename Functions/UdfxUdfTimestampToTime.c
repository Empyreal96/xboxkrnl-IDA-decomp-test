_LARGE_INTEGER __stdcall UdfxUdfTimestampToTime(TIMESTAMP *UdfTimestamp)
{
  __int16 v1; // ax
  __int16 v2; // ax
  __int16 v3; // si
  _TIME_FIELDS TimeField; // [esp+4h] [ebp-18h]
  _LARGE_INTEGER SystemTime; // [esp+14h] [ebp-8h]

  TimeField.Year = UdfTimestamp->Year;
  TimeField.Month = (unsigned __int8)UdfTimestamp->Month;
  TimeField.Day = (unsigned __int8)UdfTimestamp->Day;
  v1 = (unsigned __int8)UdfTimestamp->Hour;
  TimeField.Milliseconds = 0;
  TimeField.Hour = v1;
  TimeField.Minute = (unsigned __int8)UdfTimestamp->Minute;
  TimeField.Second = (unsigned __int8)UdfTimestamp->Second;
  if ( (*(_WORD *)UdfTimestamp & 0xF000u) <= 0x1000
    && ((v2 = (signed __int16)(16 * *(_WORD *)UdfTimestamp) >> 4, v2 >= -1440) && v2 <= 1440 || v2 == -2047)
    && RtlTimeFieldsToTime(&TimeField, &SystemTime) )
  {
    if ( (*(_WORD *)UdfTimestamp & 0xF000) == 4096 )
    {
      v3 = (signed __int16)(16 * *(_WORD *)UdfTimestamp) >> 4;
      if ( v3 != -2047 )
        SystemTime.QuadPart += -600000000i64 * v3;
    }
  }
  else
  {
    SystemTime.QuadPart = 0i64;
  }
  return SystemTime;
}