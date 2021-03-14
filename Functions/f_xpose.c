int __stdcall f_xpose()
{
  current_process->mem_ptr.c += 2;
  ti->transpose += *current_process->mem_ptr.i;
  current_process->mem_ptr.c += 2;
  current_process->function = *current_process->mem_ptr.i;
  return 1;
}