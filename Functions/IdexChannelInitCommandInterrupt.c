// write access to const memory has been detected, the output may be wrong!
bool __usercall IdexChannelInitCommandInterrupt@<al>(int a1@<ecx>, int *a2@<edi>)
{
  unsigned __int8 v2; // al

  v2 = __inbyte(0x1F7u);
  IdexChannelInitCommandIdeStatus = v2;
  IdexChannelObject.InterruptRoutine = 0;
  return KeInsertQueueDpc(503, a1, a2, &Dpc, 0, 0);
}