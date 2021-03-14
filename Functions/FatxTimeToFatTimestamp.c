BOOL __stdcall FatxTimeToFatTimestamp(_LARGE_INTEGER *Time, _FAT_TIME_STAMP *FatTimestamp)
{
  _LARGE_INTEGER v2; // kr00_8
  __int16 v3; // si
  __int16 v4; // dx
  _TIME_FIELDS TimeField; // [esp+4h] [ebp-18h]
  _LARGE_INTEGER LocalTime; // [esp+14h] [ebp-8h]

  v2.QuadPart = *(_QWORD *)Time + 19999999i64;
  LocalTime = v2;
  RtlTimeToTimeFields(&LocalTime, &TimeField);
  v3 = TimeField.Year;
  v4 = TimeField.Hour;
  HIWORD(FatTimestamp->AsULONG) = TimeField.Day & 0x1F | 32 * (TimeField.Month & 0xF) | ((TimeField.Year + 48) << 9) & 0xFE00;
  LOWORD(FatTimestamp->AsULONG) = (SLOBYTE(TimeField.Second) >> 1) & 0x1F | 32 * ((v4 << 6) | TimeField.Minute & 0x3F);
  return v3 >= 2000 && v3 <= 2127;
}