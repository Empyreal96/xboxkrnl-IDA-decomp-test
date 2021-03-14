signed int __stdcall MmQueryAllocationSize(void *BaseAddress)
{
  signed int v1; // ebx
  int v2; // edx
  int v3; // ecx
  int *i; // esi
  int v5; // eax
  char OldIrql; // [esp+Fh] [ebp-1h]

  v1 = 1;
  OldIrql = KeRaiseIrqlToDpcLevel();
  for ( i = (int *)((((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000); ; ++i )
  {
    v5 = *i;
    if ( *i & 0x200 )
      break;
    if ( !(v5 & 1) )
      RtlAssert(
        v2,
        v3,
        (int *)0x200,
        (int)i,
        "PointerPte->Hard.Valid != 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x246u,
        0);
    ++v1;
  }
  KfLowerIrql(OldIrql);
  return v1 << 12;
}