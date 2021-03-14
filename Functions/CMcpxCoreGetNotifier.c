_MCPX_HW_NOTIFICATION *__thiscall CMcpxCore::GetNotifier(CMcpxCore *this, unsigned int dwIndex)
{
  return (_MCPX_HW_NOTIFICATION *)((char *)this->m_ctxMemory[4].VirtualAddress + 16 * dwIndex);
}