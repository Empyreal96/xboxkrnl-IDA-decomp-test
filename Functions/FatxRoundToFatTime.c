_LARGE_INTEGER __stdcall FatxRoundToFatTime(_LARGE_INTEGER *Time)
{
  _LARGE_INTEGER *v1; // esi

  v1 = Time;
  if ( *(_QWORD *)Time && FatxTimeToFatTimestamp(Time, (_FAT_TIME_STAMP *)&Time) )
    return FatxFatTimestampToTime((_FAT_TIME_STAMP *)&Time);
  return *v1;
}