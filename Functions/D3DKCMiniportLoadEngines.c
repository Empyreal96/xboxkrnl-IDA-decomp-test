int __thiscall D3DK::CMiniport::LoadEngines(D3DK::CMiniport *this)
{
  D3DK::CMiniport *v1; // edi
  _DWORD *v2; // esi
  int *v3; // eax
  int v4; // ecx
  int v5; // ebx
  int v6; // eax
  _TIME_FIELDS TimeField; // [esp+Ch] [ebp-18h]
  _LARGE_INTEGER SysTime; // [esp+1Ch] [ebp-8h]

  v1 = this;
  v2 = this->m_RegisterBase;
  v3 = (int *)((char *)this->m_RegisterBase + 6220);
  v4 = *v3;
  *v3 &= 0xFFFFFCFF;
  *v3 = v4;
  v2[128] = -1;
  *((_DWORD *)v1->m_RegisterBase + 80) = v1->m_GenInfo.ChipIntrEn0;
  D3DK::CMiniport::HalDacLoad(v1);
  KeQuerySystemTime(&SysTime);
  RtlTimeToTimeFields(&SysTime, &TimeField);
  if ( TimeField.Year > 1990 )
    TimeField.Year -= 1990;
  v5 = 365 * TimeField.Year + (TimeField.Year + 1) / 4;
  if ( !((LOBYTE(TimeField.Year) - 2) & 3) && TimeField.Month > 2 )
    ++v5;
  while ( --TimeField.Month )
    v5 += (unsigned __int8)tmrMonthDays[TimeField.Month];
  v6 = 20117 * (v5 + TimeField.Day)
     + (4295 * TimeField.Second + 257698 * TimeField.Minute) / 1000
     + 838 * TimeField.Hour
     + 146951526;
  v2[9472] = 0;
  v2[9476] = v6;
  v2[1049032] = 0;
  D3DK::CMiniport::HalGrControlLoad(v1);
  v2[1048640] = -1;
  v2[1048656] = -1;
  D3DK::CMiniport::HalFifoControlLoad(v1);
  v2[2112] = -1;
  v2[2128] = v1->m_HalInfo.FifoIntrEn0;
  return 1;
}