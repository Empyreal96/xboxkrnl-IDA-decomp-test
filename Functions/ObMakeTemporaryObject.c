void __userpurge ObMakeTemporaryObject(int *a1@<edi>, int a2@<esi>, void *Object)
{
  int v3; // edx
  int v4; // ecx
  KIRQL OldIrql; // [esp+0h] [ebp-4h]

  OldIrql = KeRaiseIrqlToDpcLevel();
  *((_DWORD *)Object - 1) &= 0xFFFFFFFD;
  v4 = *((_DWORD *)Object - 1);
  if ( *((_DWORD *)Object - 3) || !(v4 & 4) )
    KfLowerIrql(OldIrql);
  else
    ObpDetachNamedObject(v3, v4, a1, a2, Object, OldIrql);
}