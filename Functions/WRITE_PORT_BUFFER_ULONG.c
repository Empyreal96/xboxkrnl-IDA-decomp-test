void __stdcall WRITE_PORT_BUFFER_ULONG(PULONG Port, PULONG Buffer, ULONG Count)
{
  __outdwordstring((unsigned __int16)Port, Buffer, Count);
}