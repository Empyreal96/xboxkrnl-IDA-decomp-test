// write access to const memory has been detected, the output may be wrong!
int __stdcall f_slur()
{
  unsigned __int16 *v0; // eax
  char v1; // dl
  unsigned __int16 *v2; // eax
  unsigned __int16 v3; // dx

  current_process->mem_ptr.c += 2;
  v0 = current_process->mem_ptr.i;
  ptr = v0;
  v1 = *(_BYTE *)v0;
  v2 = v0 + 1;
  b_value = v1;
  ptr = v2;
  if ( v1 >= 0 )
  {
    v3 = *v2;
    ++v2;
    dp_word1 = v3;
    ptr = v2;
  }
  else
  {
    dp_word1 = *(unsigned __int8 *)v2;
    b_value = v1 & 0x7F;
  }
  current_process->function = *v2;
  current_process->mem_ptr.c = (char *)ptr;
  current_process->timer += dp_word1;
  value_16_bit = ti->transpose + ((unsigned __int8)b_value << 8);
  ti->pitch = value_16_bit;
  if ( current_level == 1 )
    ti->pitch += global_fxpose;
  value_16_bit = ti->pitch;
  if ( (unsigned __int8)current_level >= (unsigned __int8)channel_level[(unsigned __int8)current_channel] )
    (*(void (__stdcall **)())(4 * (unsigned __int8)current_channel - 2146390056))();
  return 1;
}