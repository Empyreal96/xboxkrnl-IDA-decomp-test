void __fastcall ExpDeleteTimer(int a1, int a2, void *Object)
{
  KeCancelTimer(a1, a2, (_KTIMER *)Object);
}