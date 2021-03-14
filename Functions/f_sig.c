// write access to const memory has been detected, the output may be wrong!
int __stdcall f_sig()
{
  a_value = *++current_process->mem_ptr.c;
  current_process->function = *(unsigned __int8 *)++current_process->mem_ptr.c;
  return 1;
}