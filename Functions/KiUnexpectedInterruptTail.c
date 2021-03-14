int __usercall KiUnexpectedInterruptTail@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int *a4)
{
  unsigned int v4; // ebx
  int v5; // ST08_4
  int v7; // [esp+18h] [ebp-20h]
  int v8; // [esp+1Ch] [ebp-1Ch]
  int v9; // [esp+20h] [ebp-18h]
  unsigned int v10; // [esp+24h] [ebp-14h]
  int v11; // [esp+34h] [ebp-4h]
  void *retaddr; // [esp+38h] [ebp+0h]

  v9 = a1;
  v8 = a3;
  v7 = a2;
  v4 = KiPCR;
  KiPCR = -1;
  v10 = v4;
  ++unk_8004C5E4;
  HalBeginSystemInterrupt(retaddr, 31, 0, v11, a4, -1160049408, a2);
  DbgPrint(a4, BadInterruptMessage, retaddr);
  _disable();
  return HalEndSystemInterrupt(v5);
}