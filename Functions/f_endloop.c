int __stdcall f_endloop()
{
  unsigned __int16 *v0; // eax
  int v1; // ecx

  v0 = &ti->pitch + (unsigned __int8)ti->loop_level;
  --*v0;
  v1 = (unsigned __int8)ti->loop_level;
  if ( *(&ti->pitch + v1) )
  {
    current_process->mem_ptr.c = *(char **)&ti->loop_counter[2 * v1 + 2];
  }
  else
  {
    current_process->mem_ptr.c += 2;
    --ti->loop_level;
  }
  current_process->function = *current_process->mem_ptr.i;
  return 1;
}