int __thiscall CMcpxAPU::ScheduleDeferredCommandLow(CMcpxAPU *this, MCPX_DEFERRED_COMMAND *pCmd)
{
  if ( !(pCmd->dwFlags & 2) )
    this->m_apDeferredCommandsLow[pCmd->dwCommand + 2 * (_DWORD)pCmd->pVoice->m_ahVoices[0]] = pCmd;
  return 1;
}