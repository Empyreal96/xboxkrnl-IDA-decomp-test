int __stdcall volume_dsp(char op_level, char sound_level, char *patch_addr, char chan)
{
  IDirectSoundBuffer_SetVolume(
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    200 - 30 * (unsigned __int8)op_level);
  return 1;
}