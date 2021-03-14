int __fastcall ExecuteHandler(int a1, int a2, int a3, int a4, int a5, int a6, int (__stdcall *a7)(int, int, int, int, int, int))
{
  int v8; // [esp-Ch] [ebp-Ch]

  return a7(a3, a4, a5, a6, v8, a2);
}