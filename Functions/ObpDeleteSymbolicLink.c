void __fastcall ObpDeleteSymbolicLink(int a1, int a2, void *Object)
{
  ObfDereferenceObject(*(void **)Object, a2);
}