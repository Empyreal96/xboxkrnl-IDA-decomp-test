unsigned __int8 __usercall IdexDiskTransferInterrupt@<al>(int *a1@<edi>)
{
  unsigned __int8 result; // al
  int v2; // ecx
  unsigned __int8 v3; // al

  result = __inbyte(0xFF62u);
  LOBYTE(v2) = result;
  if ( unk_80051359 )
  {
    if ( !(result & 4) )
      return result;
    __outbyte(0xFF60u, 0);
    __outbyte(0xFF62u, 4u);
    unk_80051359 = 0;
  }
  v3 = __inbyte(0x1F7u);
  __outbyte(0xFF60u, 0);
  __outbyte(0xFF62u, 4u);
  IdexChannelObject.InterruptRoutine = 0;
  if ( v3 & 1 || v2 & 2 )
  {
    Irp->IoStatus.Status = -1073741435;
  }
  else
  {
    v2 = (v2 & 1) != 0 ? 0xC000003C : 0;
    Irp->IoStatus.Status = v2;
  }
  return KeInsertQueueDpc(0, (unsigned __int8)v2, a1, &Dpc, 0, 0);
}