// write access to const memory has been detected, the output may be wrong!
int __stdcall f_jumpto()
{
  current_process->mem_ptr.c += 2;
  ptr = *(unsigned __int16 **)current_process->mem_ptr.c;
  current_process->mem_ptr.c += 2;
  current_process->mem_ptr.c = (char *)ptr;
  current_process->function = *ptr;
  return 1;
}