void __thiscall CMcpxAPU::BlockIdleHandler(CMcpxAPU *this)
{
  ++this->m_dwVoiceMapLock;
}