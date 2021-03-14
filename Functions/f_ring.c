// write access to const memory has been detected, the output may be wrong!
int __stdcall f_ring()
{
  unsigned __int16 *v0; // eax
  unsigned __int16 v1; // dx

  current_process->mem_ptr.c += 2;
  v0 = current_process->mem_ptr.i;
  ptr = v0;
  v1 = *v0;
  ++v0;
  ptr = v0;
  un_int = v1;
  current_process->function = *v0;
  current_process->timer += un_int;
  current_process->mem_ptr.c = (char *)ptr;
  return 1;
}