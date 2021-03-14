void __fastcall ObfReferenceObject(void *Object)
{
  _EAX = 1;
  _ECX = (char *)Object - 16;
  __asm { xadd    [Object], eax }
}