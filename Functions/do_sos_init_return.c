// write access to const memory has been detected, the output may be wrong!
int __usercall do_sos_init_return@<eax>(int *a1@<edi>)
{
  int result; // eax

  sos_only = 0;
  fifo.fifo_read = 0;
  fifo.fifo_write = 0;
  dev_init(a1);
  result = init_queuelist();
  system_clock_music = 1;
  sound_call_table = 0;
  return result;
}