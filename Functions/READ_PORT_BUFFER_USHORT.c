void __stdcall READ_PORT_BUFFER_USHORT(PUSHORT Port, PUSHORT Buffer, ULONG Count)
{
  __inwordstring((unsigned __int16)Port, Buffer, Count);
}