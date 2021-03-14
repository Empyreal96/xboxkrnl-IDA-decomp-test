int __usercall note_on_dsp@<eax>(int *a1@<edi>, int a2@<esi>)
{
  IDirectSoundBuffer_SetPitch(
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    341 * (((unsigned int)value_16_bit >> 8) - 60) + 341 * (unsigned int)(unsigned __int8)value_16_bit / 0xFF);
  if ( *(_WORD *)(*(_DWORD *)(4 * ti->patch - 2146155992) + 10) )
    IDirectSoundBuffer_Play(
      a1,
      a2,
      *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
      0,
      0,
      1u);
  else
    IDirectSoundBuffer_Play(
      a1,
      a2,
      *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
      0,
      0,
      0);
  return 1;
}