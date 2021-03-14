void __userpurge CMcpxBuffer::RemoveDeferredCommand(CMcpxBuffer *this@<ecx>, int *a2@<edi>, unsigned int dwCommand)
{
  CMcpxAPU::RemoveDeferredCommand(this->m_pMcpxApu, a2, &this->m_aDeferredCommands[dwCommand]);
}