void __stdcall WRITE_PORT_BUFFER_USHORT(PUSHORT Port, PUSHORT Buffer, ULONG Count)
{
  __outwordstring((unsigned __int16)Port, Buffer, Count);
}