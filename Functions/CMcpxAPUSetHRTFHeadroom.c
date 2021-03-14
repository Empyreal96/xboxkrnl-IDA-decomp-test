int __stdcall CMcpxAPU::SetHRTFHeadroom(unsigned int dwHeadroom)
{
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE820280] = dwHeadroom & 7;
  return 0;
}