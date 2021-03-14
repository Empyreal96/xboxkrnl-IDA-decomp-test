void __usercall CAutoFpState::CAutoFpState(CAutoFpState *this@<ecx>, int *a2@<edi>)
{
  CFpState::Save(&this->m_fps, a2);
}