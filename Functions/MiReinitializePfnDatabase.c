void __stdcall MiReinitializePfnDatabase()
{
  KIRQL v0; // bl
  unsigned int v1; // esi
  int v2; // eax

  v0 = KeRaiseIrqlToDpcLevel();
  v1 = 0;
  do
  {
    v2 = *(_DWORD *)(4 * v1 - 2080440320);
    if ( v2 & 1 )
    {
      if ( v2 & 0x400 )
      {
        ++MmAllocatedPagesByUsage[9];
        goto LABEL_8;
      }
LABEL_7:
      MiInsertPageInFreeList(v1, 0);
      goto LABEL_8;
    }
    if ( !(v2 & 0x10000) || v2 & 0xF0000000 )
      goto LABEL_7;
LABEL_8:
    ++v1;
  }
  while ( v1 <= MmHighestPhysicalPage );
  KfLowerIrql(v0);
}