// write access to const memory has been detected, the output may be wrong!
int __stdcall f_fxset()
{
  global_fxpose = *(_WORD *)++current_process->mem_ptr.c;
  current_process->mem_ptr.c += 2;
  current_process->function = *(unsigned __int8 *)current_process->mem_ptr.c;
  return 1;
}