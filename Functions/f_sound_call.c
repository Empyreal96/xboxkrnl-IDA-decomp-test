int __stdcall f_sound_call()
{
  char *v0; // ecx
  char v1; // dl

  v0 = ++current_process->mem_ptr.c;
  v1 = *v0;
  current_process->mem_ptr.c = v0 + 1;
  current_process->function = *(unsigned __int8 *)current_process->mem_ptr.c;
  put_fifo(v1);
  return 1;
}