// write access to const memory has been detected, the output may be wrong!
char __stdcall get_fifo()
{
  char result; // al

  result = fifo.data[(unsigned __int8)fifo.fifo_read];
  if ( ++fifo.fifo_read >= 0x10u )
    fifo.fifo_read = 0;
  return result;
}