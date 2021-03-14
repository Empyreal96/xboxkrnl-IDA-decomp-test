void __stdcall CpInitialize(_CPPORT *Port, char *Address, unsigned int Rate)
{
  Port->Baud = 0;
  Port->Address = Address;
  CpSetBaud(Port, Rate);
  __outbyte((unsigned __int16)(Port->Address + 4), 3u);
  __outbyte((unsigned __int16)(Port->Address + 1), 0);
}