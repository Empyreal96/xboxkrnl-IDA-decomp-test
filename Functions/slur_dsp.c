int __stdcall slur_dsp()
{
  IDirectSoundBuffer_SetPitch(
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    341 * (((unsigned int)value_16_bit >> 8) - 60) + 341 * (unsigned int)(unsigned __int8)value_16_bit / 0xFF);
  return 1;
}