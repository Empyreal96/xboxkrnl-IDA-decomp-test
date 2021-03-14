void __usercall CMcpxCore::~CMcpxCore(CMcpxCore *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxCore *thisa; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]

  thisa = this;
  this->vfptr = (CMcpxCoreVtbl *)&CMcpxCore::`vftable';
  CMcpxCore::Reset(this, a2, 1);
  __delete(a2, a3, &thisa->m_pGpDspManager);
  for ( i = 0; i < 0x10; ++i )
    PhysicalFree(a2, &thisa->m_ctxMemory[i].VirtualAddress);
  __Release((CDirectSoundBufferSettings **)&thisa->m_pSettings);
  CAc97Device::~CAc97Device(&thisa->m_Ac97, a2);
}