// write access to const memory has been detected, the output may be wrong!
int __usercall f_rest@<eax>(int *a1@<edi>, int a2@<esi>)
{
  unsigned __int16 v2; // dx

  current_process->mem_ptr.c += 2;
  ptr = current_process->mem_ptr.i;
  v2 = *ptr;
  ++ptr;
  un_int = v2;
  current_process->function = *ptr;
  current_process->timer += un_int;
  current_process->mem_ptr.c = (char *)ptr;
  if ( (unsigned __int8)current_level >= (unsigned __int8)channel_level[(unsigned __int8)current_channel] )
    (*(void (__usercall **)(int *@<edi>, int@<esi>))(4 * (unsigned __int8)current_channel - 2146389992))(a1, a2);
  return 1;
}