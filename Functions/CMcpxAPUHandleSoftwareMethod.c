void __thiscall CMcpxAPU::HandleSoftwareMethod(CMcpxAPU *this, unsigned int dwMethod, unsigned int dwParam)
{
  if ( dwMethod == 0x8000 )
    CMcpxAPU::HandleIdleVoice(this, dwParam);
}