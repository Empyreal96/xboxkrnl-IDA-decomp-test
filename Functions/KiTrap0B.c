void KiTrap0B()
{
  __int16 retaddr_2; // [esp+12h] [ebp+2h]

  retaddr_2 = 0;
  _enable();
  JUMPOUT(&CommonDispatchException2Args0d);
}