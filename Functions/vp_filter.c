int __stdcall vp_filter()
{
  _DSFILTERDESC fdesc; // [esp+0h] [ebp-18h]

  fdesc.dwQCoefficient = 0;
  fdesc.dwMode = 1;
  fdesc.adwCoefficients[0] = ti->filtercutoff + 0x8000;
  fdesc.adwCoefficients[1] = ti->filterres;
  fdesc.adwCoefficients[2] = ti->filtercutoff + 0x8000;
  fdesc.adwCoefficients[3] = ti->filterres;
  IDirectSoundBuffer_SetFilter(*(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584), &fdesc);
  return 1;
}