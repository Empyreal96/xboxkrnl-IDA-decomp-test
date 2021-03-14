int __userpurge CAc97Channel::Initialize@<eax>(CAc97Channel *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int dwFlags, void (__stdcall *pfnCallback)(void *), void *pvContext)
{
  int v6; // ST14_4
  CAc97Channel *thisa; // [esp+0h] [ebp-14h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-Ch]
  int hr; // [esp+10h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  thisa->m_dwFlags = dwFlags;
  thisa->m_pfnCallback = pfnCallback;
  thisa->m_pvCallbackContext = pvContext;
  thisa->m_pPrdl = (ACIPRD *)PhysicalAlloc(a3, 0x100u, 0x1000u, 4u, 0);
  hr = thisa->m_pPrdl != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 )
    thisa->m_dwPrdlAddress = MmGetPhysicalAddress((int)thisa->m_pPrdl, a2, thisa->m_pPrdl);
  if ( hr >= 0 && dwFlags & 1 )
  {
    thisa->m_pvSilence = PhysicalAlloc(a3, 0x2000u, 0x1000u, 4u, 0);
    hr = thisa->m_pvSilence != 0 ? 0 : 0x8007000E;
  }
  if ( hr >= 0 )
    CAc97Channel::Reset(thisa);
  v6 = hr;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return v6;
}