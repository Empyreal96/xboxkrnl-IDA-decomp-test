void __stdcall IopDisassociateThreadIrp()
{
  KIRQL v0; // bl
  void **v1; // esi
  KIRQL v2; // al
  int v3; // edx
  KIRQL v4; // cl
  int *v5; // esi
  int v6; // edi
  _DWORD *v7; // esi

  v0 = KfRaiseIrql(1);
  v1 = &thread[1].KernelStack;
  if ( *v1 != v1 )
  {
    v2 = KeRaiseIrqlToDpcLevel();
    v3 = (int)*v1 - 8;
    if ( *((char *)*v1 + 17) != *(char *)(v3 + 24) + 2 )
    {
      *(_DWORD *)(v3 + 80) = 0;
      v5 = (int *)*v1;
      v6 = *v5;
      v7 = (_DWORD *)v5[1];
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
      *(_DWORD *)(v3 + 12) = v3 + 8;
      *(_DWORD *)(v3 + 8) = v3 + 8;
      KfLowerIrql(v2);
      v4 = v0;
      goto LABEL_6;
    }
    KfLowerIrql(v2);
  }
  v4 = v0;
LABEL_6:
  KfLowerIrql(v4);
}