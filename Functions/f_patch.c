// write access to const memory has been detected, the output may be wrong!
int __usercall f_patch@<eax>(int *a1@<edi>)
{
  unsigned __int16 v1; // dx

  current_process->mem_ptr.c += 2;
  ptr = current_process->mem_ptr.i;
  v1 = *ptr;
  ++ptr;
  current_process->function = *ptr;
  current_process->mem_ptr.c = (char *)ptr;
  ti->patch = v1;
  ti->volume = 0;
  ti->pan = 0;
  if ( (unsigned __int8)current_level >= (unsigned __int8)channel_level[(unsigned __int8)current_channel] )
    (*(void (__userpurge **)(int *@<edi>, unsigned __int16))(4 * (unsigned __int8)current_channel - 2146389928))(a1, v1);
  return 1;
}