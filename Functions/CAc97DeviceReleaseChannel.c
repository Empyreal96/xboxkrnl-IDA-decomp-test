void __userpurge CAc97Device::ReleaseChannel(CAc97Device *this@<ecx>, int *a2@<edi>, AC97CHANNELTYPE Channel)
{
  CAc97Device *v3; // ST04_4
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  v3 = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  __delete(a2, &v3->m_apChannels[Channel]);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}