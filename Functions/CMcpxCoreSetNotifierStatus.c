void __thiscall CMcpxCore::SetNotifierStatus(CMcpxCore *this, unsigned int dwIndex, int fSignaled)
{
  CMcpxCore::GetNotifier(this, dwIndex)->Status = fSignaled != 0 ? 1 : -128;
}