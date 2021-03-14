void __stdcall RtlTimeToTimeFields(_LARGE_INTEGER *Time, _TIME_FIELDS *TimeFields)
{
  LARGE_INTEGER v2; // rax
  unsigned int v3; // esi
  LARGE_INTEGER v4; // rax
  unsigned int v5; // ST20_4
  unsigned int v6; // ebx
  int *v7; // edi
  const __int16 *v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ett
  unsigned int Milliseconds; // [esp+14h] [ebp-4h]
  unsigned int Month; // [esp+20h] [ebp+8h]

  v2 = RtlExtendedMagicDivide(*Time, Magic10000, 13);
  v3 = v2.LowPart;
  v4 = RtlExtendedMagicDivide(v2, Magic86400000, 26);
  Milliseconds = v3 - 86400000 * v4.LowPart;
  v5 = v4.LowPart;
  TimeFields->Weekday = (v4.LowPart + 1) % 7;
  v6 = ElapsedDaysToYears(v4.LowPart);
  v7 = (int *)(v5 + -365 * v6 - v6 / 0x190 - (v6 >> 2) + v6 / 0x64);
  if ( (v6 + 1) % 0x190 && (!((v6 + 1) % 0x64) || ((_BYTE)v6 + 1) & 3) )
    v8 = NormalYearDaysPrecedingMonth;
  else
    v8 = LeapYearDaysPrecedingMonth;
  v9 = 1;
  Month = 1;
  while ( 1 )
  {
    v10 = (unsigned __int16)v8[v9];
    if ( (unsigned int)v7 < v10 )
      break;
    Month = ++v9;
    if ( v9 > 0xC )
      goto LABEL_11;
  }
  v8 = (const __int16 *)v8[v9 - 1];
  v10 = 1 - (_DWORD)v8;
  v7 = (int *)((char *)v7 + 1 - (_DWORD)v8);
LABEL_11:
  if ( v9 > 0xC )
    RtlAssert(v10, (int)v8, v7, (int)TimeFields, "Month <= 12", "d:\\xbox-apr03\\private\\ntos\\rtl\\time.c", 0x22Bu, 0);
  if ( (unsigned int)v7 < 1 || (unsigned int)v7 > 0x1F )
    RtlAssert(
      v10,
      (int)v8,
      v7,
      (int)TimeFields,
      "Days >= 1 && Days <= 31",
      "d:\\xbox-apr03\\private\\ntos\\rtl\\time.c",
      0x22Cu,
      0);
  TimeFields->Day = (signed __int16)v7;
  TimeFields->Year = v6 + 1601;
  TimeFields->Month = Month;
  v11 = Milliseconds / 0x3E8 / 0x3C;
  TimeFields->Second = Milliseconds / 0x3E8 % 0x3C;
  TimeFields->Hour = v11 / 0x3C;
  TimeFields->Minute = v11 % 0x3C;
  TimeFields->Milliseconds = Milliseconds % 0x3E8;
}