void __usercall CMcpxAPU::Terminate(CMcpxAPU *this@<ecx>, int *a2@<edi>)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-18h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-10h]
  _LIST_ENTRY *pleEntry; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  for ( i = 0; i < 3; ++i )
  {
    for ( pleEntry = thisa->m_alstActiveVoices[i].Flink;
          pleEntry != &thisa->m_alstActiveVoices[i];
          pleEntry = pleEntry->Flink )
    {
      ((void (__thiscall *)(_LIST_ENTRY **, _DWORD, _DWORD))pleEntry[-24].Blink[2].Flink)(&pleEntry[-24].Blink, 0, 0);
    }
  }
  CMcpxCore::Reset((CMcpxCore *)&thisa->vfptr, a2, 1);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}