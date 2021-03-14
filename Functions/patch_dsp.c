int __userpurge patch_dsp@<eax>(int *a1@<edi>, unsigned __int16 pat)
{
  int v2; // esi

  v2 = *(_DWORD *)(4 * pat - 2146155992);
  IDirectSoundBuffer_SetEG(
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    *(_DSENVELOPEDESC **)(v2 + 12));
  IDirectSoundBuffer_SetEG(
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    *(_DSENVELOPEDESC **)(v2 + 16));
  IDirectSoundBuffer_SetBufferData(
    a1,
    v2,
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    *(void **)v2,
    *(unsigned __int16 *)(v2 + 4));
  IDirectSoundBuffer_SetLoopRegion(
    a1,
    v2,
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    0,
    *(unsigned __int16 *)(v2 + 4));
  IDirectSoundBuffer_SetCurrentPosition(
    a1,
    v2,
    *(IDirectSoundBuffer **)(4 * (unsigned __int8)current_channel - 2146303584),
    0);
  return 1;
}