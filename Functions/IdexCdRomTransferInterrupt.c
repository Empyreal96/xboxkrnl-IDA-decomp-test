unsigned __int8 __usercall IdexCdRomTransferInterrupt@<al>(int *a1@<edi>)
{
  unsigned __int8 v1; // al
  int v2; // ecx
  char v3; // al
  unsigned __int8 result; // al
  unsigned __int8 v5; // bl
  char IdeStatus; // [esp+1h] [ebp-1h]

  v1 = __inbyte(0xFF62u);
  LOBYTE(v2) = v1;
  v3 = __inbyte(0x1F7u);
  IdeStatus = v3;
  result = __inbyte(0x1F2u);
  v5 = result;
  if ( unk_80051359 )
  {
    if ( !(v2 & 4) )
      return result;
    __outbyte(0xFF60u, 0);
    result = 4;
    __outbyte(0xFF62u, 4u);
    unk_80051359 = 0;
  }
  if ( (v5 & 3) == 3 )
  {
    IdexChannelObject.InterruptRoutine = 0;
    if ( IdeStatus & 1 || v2 & 2 )
    {
      Irp->IoStatus.Status = -1073741435;
    }
    else
    {
      v2 = (v2 & 1) != 0 ? 0xC000003C : 0;
      Irp->IoStatus.Status = v2;
    }
    result = KeInsertQueueDpc(0, (unsigned __int8)v2, a1, &Dpc, 0, 0);
  }
  return result;
}