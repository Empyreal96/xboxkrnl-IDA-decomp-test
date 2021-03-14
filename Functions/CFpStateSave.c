// write access to const memory has been detected, the output may be wrong!
void __usercall CFpState::Save(CFpState *this@<ecx>, int *a2@<edi>)
{
  int v2; // edx

  if ( KeIsExecutingDpc() )
  {
    if ( !++CFpState::m_dwRefCount )
      KeSaveFloatingPointState(v2, CFpState::m_dwRefCount + 1, a2, &CFpState::m_fps);
  }
}