int __stdcall f_mux()
{
  ti->mux_addr[(unsigned __int8)ti->mux_level++] = (unsigned __int16 *)(++current_process->mem_ptr.c + 2);
  current_process->mem_ptr.c = (char *)*current_process->mem_ptr.i;
  current_process->function = *(unsigned __int8 *)current_process->mem_ptr.c;
  return 1;
}