int __fastcall IdexChannelFinishInitCommand(int a1, int a2)
{
  return KeSetEvent(a1, a2, &IdexChannelInitCommandEvent, 1, 0);
}