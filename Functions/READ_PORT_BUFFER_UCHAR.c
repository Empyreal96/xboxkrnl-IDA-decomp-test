void __stdcall READ_PORT_BUFFER_UCHAR(PUCHAR Port, PUCHAR Buffer, ULONG Count)
{
  __inbytestring((unsigned __int16)Port, (unsigned __int8 *)Buffer, Count);
}