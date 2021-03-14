void __stdcall MiChangeCodeSelectorLimit(int a1, int a2)
{
  _disable();
  dword_8005FBB0 = a1;
  dword_8005FBB4 = a2;
  _enable();
  JUMPOUT(ChangeCodeSelectorLimitDone);
}