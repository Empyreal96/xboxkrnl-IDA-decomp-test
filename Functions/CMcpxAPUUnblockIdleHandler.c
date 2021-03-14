void __thiscall CMcpxAPU::UnblockIdleHandler(CMcpxAPU *this)
{
  --this->m_dwVoiceMapLock;
}