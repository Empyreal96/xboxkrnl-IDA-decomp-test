void __stdcall READ_PORT_BUFFER_ULONG(PULONG Port, PULONG Buffer, ULONG Count)
{
  __indwordstring((unsigned __int16)Port, Buffer, Count);
}