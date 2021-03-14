// write access to const memory has been detected, the output may be wrong!
void __usercall CAc97Device::~CAc97Device(CAc97Device *this@<ecx>, int *a2@<edi>)
{
  CAc97Device::Terminate(this, a2);
  CAc97Device::m_pDevice = 0;
}