int __cdecl _SEH_prolog(int a1, int a2)
{
  void *v2; // esp
  int result; // eax
  int retaddr; // [esp+10h] [ebp-8h]

  v2 = alloca(a2);
  result = a1;
  retaddr = a1;
  return result;
}