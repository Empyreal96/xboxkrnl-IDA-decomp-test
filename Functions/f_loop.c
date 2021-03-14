int __stdcall f_loop()
{
  current_process->mem_ptr.c += 2;
  ti->loop_counter[(unsigned __int8)ti->loop_level] = *current_process->mem_ptr.i;
  current_process->mem_ptr.c += 2;
  ti->loop_addr[(unsigned __int8)ti->loop_level++] = current_process->mem_ptr.i;
  current_process->function = *current_process->mem_ptr.i;
  return 1;
}