void __stdcall WRITE_PORT_BUFFER_UCHAR(PUCHAR Port, PUCHAR Buffer, ULONG Count)
{
  __outbytestring((unsigned __int16)Port, (unsigned __int8 *)Buffer, Count);
}