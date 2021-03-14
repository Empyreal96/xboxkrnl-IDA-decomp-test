unsigned int *__usercall D3DK::CDevice::GpuGet@<eax>(D3DK::CDevice *this@<ecx>, int *a2@<edi>)
{
  unsigned int v2; // esi
  unsigned int *v3; // esi
  unsigned int *result; // eax
  unsigned int v5; // esi
  unsigned int *v6; // esi
  D3DK::CDevice *v7; // [esp+4h] [ebp-4h]

  v7 = this;
  v2 = this->m_pControlDma->Get;
  if ( v2 > 0x4000000 )
  {
    DbgPrint(a2, "DebugVerifyPhysical - Not a valid physical memory offset.");
    DbgPrint(a2, "\n");
    __debugbreak();
    this = v7;
  }
  v3 = (unsigned int *)(v2 | 0x80000000);
  result = v3;
  if ( v3 < this->m_pPushBase || v3 >= this->m_pPushLimit )
  {
    v5 = this->m_NvBase[3219].Reg032[0] & 0xFFFFFFFE;
    if ( v5 > 0x4000000 )
    {
      DbgPrint(a2, "DebugVerifyPhysical - Not a valid physical memory offset.");
      DbgPrint(a2, "\n");
      __debugbreak();
      this = v7;
    }
    v6 = (unsigned int *)(v5 | 0x80000000);
    if ( v6 < this->m_pPushBase || v6 > this->m_pPushLimit )
      D3DK::DXGRIP(a2, "Assertion failure: %s", "(pGet >= m_pPushBase) && (pGet <= m_pPushLimit)");
    result = v6;
  }
  return result;
}