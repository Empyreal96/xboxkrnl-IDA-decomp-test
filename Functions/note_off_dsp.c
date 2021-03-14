int __usercall note_off_dsp@<eax>(int *a1@<edi>, int a2@<esi>)
{
  IDirectSoundBuffer_StopEx(
    a1,
    a2,
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    0i64,
    1u);
  return 1;
}