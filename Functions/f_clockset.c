int __stdcall f_clockset()
{
  clock_cntr_value[(unsigned __int8)current_process->level] = *++current_process->mem_ptr.c;
  current_process->function = *(unsigned __int8 *)++current_process->mem_ptr.c;
  return 1;
}