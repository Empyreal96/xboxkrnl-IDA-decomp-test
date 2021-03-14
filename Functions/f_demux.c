// write access to const memory has been detected, the output may be wrong!
int __stdcall f_demux()
{
  un_char = --ti->mux_level;
  current_process->mem_ptr.c = (char *)ti->mux_addr[(unsigned __int8)un_char];
  current_process->function = *(unsigned __int8 *)current_process->mem_ptr.c;
  return 1;
}