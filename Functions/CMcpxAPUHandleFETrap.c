void __thiscall CMcpxAPU::HandleFETrap(CMcpxAPU *this)
{
  if ( ((MEMORY[0xFE801100] >> 8) & 0xF) == 15 )
    CMcpxAPU::HandleSoftwareMethod(this, MEMORY[0xFE801300], MEMORY[0xFE801304]);
  CMcpxCore::SetFrontEndState(0);
  CMcpxCore::SetFrontEndState(MCPX_FE_STATE_FREE_RUNNING);
}