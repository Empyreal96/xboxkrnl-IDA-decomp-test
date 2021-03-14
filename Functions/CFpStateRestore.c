// write access to const memory has been detected, the output may be wrong!
void CFpState::Restore()
{
  if ( KeIsExecutingDpc() )
  {
    if ( !--CFpState::m_dwRefCount )
      KeRestoreFloatingPointState(&CFpState::m_fps);
  }
}