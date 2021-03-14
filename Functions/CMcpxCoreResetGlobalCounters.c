// write access to const memory has been detected, the output may be wrong!
void CMcpxCore::ResetGlobalCounters()
{
  if ( !(_S1 & 1) )
  {
    _S1 |= 1u;
    dwDelta = CMcpxCore::m_adwEPOutputBufferSizes[0] >> 2;
  }
  MEMORY[0xFE802008] = dwDelta;
  MEMORY[0xFE80200C] = 0;
  MEMORY[0xFE802010] = dwDelta;
  MEMORY[0xFE802014] = dwDelta >> 1;
  MEMORY[0xFE802018] = dwDelta - 1;
  MEMORY[0xFE80201C] = 0;
  MEMORY[0xFE802020] = 1536;
  MEMORY[0xFE802024] = 256;
  MEMORY[0xFE802028] = 256;
  MEMORY[0xFE80402C] = 1536;
  MEMORY[0xFE80403C] = CMcpxCore::m_adwEPOutputBufferSizes[0] + 6144;
}