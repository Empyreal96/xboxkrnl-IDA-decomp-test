_LARGE_INTEGER __stdcall FatxFatTimestampToTime(_FAT_TIME_STAMP *FatTimestamp)
{
  unsigned __int16 v1; // ax
  __int16 v2; // dx
  unsigned int v3; // edx
  unsigned __int16 v4; // ax
  _TIME_FIELDS TimeField; // [esp+0h] [ebp-18h]
  _LARGE_INTEGER SystemTime; // [esp+10h] [ebp-8h]

  v1 = HIWORD(FatTimestamp->AsULONG);
  v2 = HIWORD(FatTimestamp->AsULONG) >> 9;
  TimeField.Milliseconds = 0;
  TimeField.Year = v2 + 2000;
  v3 = v1;
  TimeField.Day = v1 & 0x1F;
  v4 = FatTimestamp->AsULONG;
  TimeField.Hour = LOWORD(FatTimestamp->AsULONG) >> 11;
  TimeField.Month = (v3 >> 5) & 0xF;
  TimeField.Second = 2 * (v4 & 0x1F);
  TimeField.Minute = (v4 >> 5) & 0x3F;
  if ( !RtlTimeFieldsToTime(&TimeField, &SystemTime) )
    SystemTime.QuadPart = 0i64;
  return SystemTime;
}