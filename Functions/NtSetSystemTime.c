int __userpurge NtSetSystemTime@<eax>(int a1@<esi>, _LARGE_INTEGER *SystemTime, _LARGE_INTEGER *PreviousTime)
{
  signed int v3; // edi
  int v4; // edx
  int v5; // ST0C_4
  int v6; // edx
  void *v7; // ecx
  signed int v8; // eax
  _TIME_FIELDS TimeFields; // [esp+8h] [ebp-20h]
  _LARGE_INTEGER CurrentTime; // [esp+18h] [ebp-10h]
  _LARGE_INTEGER NewTime; // [esp+20h] [ebp-8h]

  v3 = 0;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(0, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v4, v5, 0, a1, "FALSE", "d:\\xbox-apr03\\private\\ntos\\ex\\systime.c", 0x3Bu, 0);
  }
  RtlEnterCriticalSectionAndRegion(&ExpTimeRefreshLock);
  v7 = (void *)SystemTime->LowPart;
  v8 = SystemTime->HighPart;
  NewTime.LowPart = SystemTime->LowPart;
  NewTime.HighPart = v8;
  if ( v8 < 0 || v8 > 0x20000000 )
  {
    v3 = -1073741811;
  }
  else
  {
    KeSetSystemTime(v6, (int)v7, 0, (int)&ExpTimeRefreshLock, &NewTime, &CurrentTime);
    RtlTimeToTimeFields(&NewTime, &TimeFields);
    HalSetRealTimeClock((int)&TimeFields);
    if ( PreviousTime )
      *PreviousTime = CurrentTime;
    HalMarkCmosValid();
  }
  RtlLeaveCriticalSectionAndRegion(v7, (_KEVENT *)&ExpTimeRefreshLock);
  return v3;
}