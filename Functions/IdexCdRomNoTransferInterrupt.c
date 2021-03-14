char __usercall IdexCdRomNoTransferInterrupt@<al>(int *a1@<edi>)
{
  unsigned __int8 v1; // al
  unsigned __int8 v2; // cl
  unsigned __int8 v3; // al
  char result; // al
  int v5; // ecx

  v1 = __inbyte(0x1F7u);
  v2 = v1;
  v3 = __inbyte(0x1F2u);
  result = v3 & 3;
  if ( result == 3 )
  {
    IdexChannelObject.InterruptRoutine = 0;
    v5 = (v2 & 1) != 0 ? 0xC0000185 : 0;
    Irp->IoStatus.Status = v5;
    result = KeInsertQueueDpc(0, v5, a1, &Dpc, 0, 0);
  }
  return result;
}