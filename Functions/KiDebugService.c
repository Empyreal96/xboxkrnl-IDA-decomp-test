void KiDebugService()
{
  char *retaddr; // [esp+2h] [ebp+0h]

  ++retaddr;
  JUMPOUT(&KiTrap03DebugService);
}