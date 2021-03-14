// write access to const memory has been detected, the output may be wrong!
int __stdcall f_pan()
{
  char v0; // dl

  current_process->mem_ptr.c += 2;
  ptr = current_process->mem_ptr.i;
  v0 = *(_BYTE *)ptr;
  ++ptr;
  a_value = v0;
  current_process->function = *ptr;
  current_process->mem_ptr.c = (char *)ptr;
  ti->pan = a_value;
  if ( (unsigned __int8)current_level >= (unsigned __int8)channel_level[(unsigned __int8)current_channel] )
    (*(void (__stdcall **)(char, char, char *))(4 * (unsigned __int8)current_channel - 2146389800))(
      current_channel,
      a_value,
      (char *)ti->patch);
  return 1;
}