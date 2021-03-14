// write access to const memory has been detected, the output may be wrong!
int __stdcall f_volume()
{
  current_process->mem_ptr.c += 2;
  un_char = *current_process->mem_ptr.c + ti->volume;
  current_process->mem_ptr.c += 2;
  current_process->function = *current_process->mem_ptr.i;
  ti->volume = un_char;
  if ( (unsigned __int8)current_level >= (unsigned __int8)channel_level[(unsigned __int8)current_channel] )
    (*(void (__stdcall **)(char, char, char *))(4 * (unsigned __int8)current_channel - 2146389864))(
      un_char,
      current_level,
      (char *)ti->patch);
  return 1;
}