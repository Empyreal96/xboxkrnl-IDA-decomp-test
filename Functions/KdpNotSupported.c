int __stdcall KdpNotSupported(_DBGKD_MANIPULATE_STATE64 *m)
{
  _STRING MessageHeader; // [esp+0h] [ebp-8h]

  MessageHeader.Buffer = (char *)m;
  m->ReturnStatus = -1073741823;
  MessageHeader.Length = 56;
  KdPhysicalPort->SendPacket(2u, &MessageHeader, 0);
  return 0;
}