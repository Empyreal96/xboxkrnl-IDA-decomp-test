_IRP *__fastcall IoAllocateIrp(int a1, int a2, char StackSize)
{
  unsigned int v3; // edi
  _IRP *v4; // edx
  _IRP *result; // eax

  v3 = (unsigned __int16)(36 * StackSize + 104);
  v4 = (_IRP *)ExAllocatePoolWithTag(a2, a1, StackSize, v3, 0x20707249u);
  result = 0;
  if ( v4 )
  {
    memset(v4, 0, v3);
    v4->Size = 36 * StackSize + 104;
    v4->StackCount = StackSize;
    v4->CurrentLocation = StackSize + 1;
    v4->ThreadListEntry.Blink = &v4->ThreadListEntry;
    v4->ThreadListEntry.Flink = &v4->ThreadListEntry;
    v4->Tail.Overlay.PacketType = (unsigned int)&v4[1] + 36 * StackSize;
    v4->Type = 6;
    result = v4;
  }
  return result;
}