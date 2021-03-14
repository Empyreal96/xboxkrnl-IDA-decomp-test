void __stdcall KdpCheckLowMemory(_DBGKD_MANIPULATE_STATE64 *Message)
{
  _STRING MessageHeader; // [esp+0h] [ebp-8h]

  Message->ReturnStatus = 0;
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)Message;
  if ( KdpSearchInProgress )
    KdpSearchPhysicalPageRange();
  KdPhysicalPort->SendPacket(2u, &MessageHeader, 0);
}