// write access to const memory has been detected, the output may be wrong!
void __stdcall put_fifo(char value)
{
  fifo.data[(unsigned __int8)fifo.fifo_write] = value;
  if ( ++fifo.fifo_write >= 0x10u )
    fifo.fifo_write = 0;
}