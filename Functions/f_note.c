// write access to const memory has been detected, the output may be wrong!
int __usercall f_note@<eax>(int *a1@<edi>, int a2@<esi>)
{
  unsigned __int16 *v2; // eax
  char v3; // dl
  unsigned __int16 *v4; // eax
  unsigned __int16 v5; // dx

  current_process->mem_ptr.c += 2;
  v2 = current_process->mem_ptr.i;
  ptr = v2;
  v3 = *(_BYTE *)v2;
  v4 = v2 + 1;
  b_value = v3;
  ptr = v4;
  if ( v3 >= 0 )
  {
    v5 = *v4;
    ++v4;
    dp_word1 = v5;
    ptr = v4;
  }
  else
  {
    dp_word1 = *(unsigned __int8 *)v4;
    b_value = v3 & 0x7F;
  }
  current_process->function = *v4;
  current_process->mem_ptr.c = (char *)ptr;
  current_process->timer += dp_word1;
  value_16_bit = ti->transpose + ((unsigned __int8)b_value << 8);
  ti->pitch = value_16_bit;
  if ( current_level == 1 )
    ti->pitch += global_fxpose;
  value_16_bit = ti->pitch;
  if ( (unsigned __int8)current_level >= (unsigned __int8)channel_level[(unsigned __int8)current_channel] )
    (*(void (__usercall **)(int *@<edi>, int@<esi>))(4 * (unsigned __int8)current_channel - 2146390120))(a1, a2);
  return 1;
}