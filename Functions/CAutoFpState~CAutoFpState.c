void CAutoFpState::~CAutoFpState()
{
  CFpState::Restore();
}