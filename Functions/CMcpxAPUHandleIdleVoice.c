void __thiscall CMcpxAPU::HandleIdleVoice(CMcpxAPU *this, unsigned int dwIdleVoice)
{
  if ( !this->m_dwVoiceMapLock && !((*((_DWORD *)this->m_ctxMemory[3].VirtualAddress + 32 * dwIdleVoice + 1) >> 23) & 1) )
    CMcpxAPU::RemoveIdleVoice(this, dwIdleVoice);
}