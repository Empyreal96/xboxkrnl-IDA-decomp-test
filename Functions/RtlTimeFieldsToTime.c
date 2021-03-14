char __stdcall RtlTimeFieldsToTime(_TIME_FIELDS *TimeFields, _LARGE_INTEGER *Time)
{
  _TIME_FIELDS *v2; // eax
  __int16 v3; // dx
  unsigned int v4; // ecx
  unsigned int v5; // esi
  int v6; // edi
  unsigned int v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  unsigned int Milliseconds; // [esp+10h] [ebp-10h]
  unsigned int Second; // [esp+14h] [ebp-Ch]
  unsigned int Minute; // [esp+18h] [ebp-8h]
  unsigned int Year; // [esp+28h] [ebp+8h]

  v2 = TimeFields;
  v3 = TimeFields->Month;
  Year = TimeFields->Year;
  v4 = v2->Hour;
  Minute = v2->Minute;
  v5 = v3 - 1;
  v6 = v2->Day - 1;
  Second = v2->Second;
  Milliseconds = v2->Milliseconds;
  if ( v3 < 1 || v2->Day < 1 || Year < 0x641 || v5 > 0xB )
    return 0;
  if ( Year % 0x190 && (!(Year % 0x64) || Year & 3) )
  {
    v7 = v5;
    v8 = word_800158C6[v7];
    v9 = NormalYearDaysPrecedingMonth[v7];
  }
  else
  {
    v7 = v5;
    v8 = word_800158AA[v7];
    v9 = LeapYearDaysPrecedingMonth[v7];
  }
  if ( (signed __int16)v6 >= v8 - v9 || v4 > 0x17 || Minute > 0x3B || Second > 0x3B || Milliseconds > 0x3E7 )
    return 0;
  if ( (Year - 1600) % 0x190 && (!((Year - 1600) % 0x64) || Year & 3) )
    v10 = NormalYearDaysPrecedingMonth[v7];
  else
    v10 = LeapYearDaysPrecedingMonth[v7];
  DaysAndFractionToTime(
    v6 + v10 + ((Year - 1601) >> 2) + 365 * (Year - 1601) + (Year - 1601) / 0x190 - (Year - 1601) / 0x64,
    Milliseconds + 1000 * (Second + 60 * (Minute + 60 * v4)),
    Time);
  return 1;
}