void __thiscall CMcpxAPU::RemoveDeferredCommandLow(CMcpxAPU *this, MCPX_DEFERRED_COMMAND *pCmd)
{
  this->m_apDeferredCommandsLow[pCmd->dwCommand + 2 * (_DWORD)pCmd->pVoice->m_ahVoices[0]] = 0;
}