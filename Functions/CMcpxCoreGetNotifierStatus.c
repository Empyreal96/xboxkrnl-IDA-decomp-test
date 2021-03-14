int __thiscall CMcpxCore::GetNotifierStatus(CMcpxCore *this, unsigned int dwIndex, int fReset)
{
  char v4; // [esp+0h] [ebp-Ch]
  _MCPX_HW_NOTIFICATION *pNotifier; // [esp+8h] [ebp-4h]

  pNotifier = CMcpxCore::GetNotifier(this, dwIndex);
  v4 = pNotifier->Status;
  if ( !v4 )
  {
    pNotifier->Status = -128;
    return 0;
  }
  if ( v4 != 1 )
    return 0;
  if ( fReset )
    pNotifier->Status = -128;
  return 1;
}