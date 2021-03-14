int __userpurge CMcpxBuffer::ScheduleDeferredCommand@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, unsigned int dwCommand, __int64 rtTimeStamp, unsigned int dwContext)
{
  this->m_aDeferredCommands[dwCommand].rtTimestamp = rtTimeStamp;
  this->m_aDeferredCommands[dwCommand].dwContext = dwContext;
  return CMcpxAPU::ScheduleDeferredCommand(this->m_pMcpxApu, a2, &this->m_aDeferredCommands[dwCommand]);
}