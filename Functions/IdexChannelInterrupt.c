char __stdcall IdexChannelInterrupt(_KINTERRUPT *InterruptObject, void *ServiceContext)
{
  unsigned __int8 v2; // al

  if ( IdexChannelObject.InterruptRoutine )
    IdexChannelObject.InterruptRoutine();
  else
    v2 = __inbyte(0x1F7u);
  return 1;
}