int __userpurge NtClose@<eax>(int *a1@<edi>, void *Handle)
{
  int v2; // edx
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // esi
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int result; // eax
  int *v13; // [esp-4h] [ebp-Ch]
  KIRQL OldIrql; // [esp+4h] [ebp-4h]

  OldIrql = KeRaiseIrqlToDpcLevel();
  v4 = ObpDestroyObjectHandle(v2, v3, a1, Handle);
  v7 = v4;
  if ( v4 )
  {
    v13 = a1;
    v8 = *(v4 - 3);
    if ( !v8 )
      RtlAssert(v5, v6, 0, (int)v4, "HandleCount > 0", "d:\\xbox-apr03\\private\\ntos\\obx\\obhandle.c", 0xA9u, 0);
    v9 = *(v7 - 2);
    --*(v7 - 3);
    if ( *(_DWORD *)(v9 + 8) )
    {
      KfLowerIrql(OldIrql);
      (*(void (__stdcall **)(_DWORD *, int))(*(v7 - 2) + 8))(v7, v8);
      OldIrql = KeRaiseIrqlToDpcLevel();
    }
    if ( *(v7 - 3) || (v10 = *(v7 - 1), !(v10 & 4)) || v10 & 2 )
      KfLowerIrql(OldIrql);
    else
      ObpDetachNamedObject(v5, v6, v13, (int)v7, v7, OldIrql);
    ObfDereferenceObject(v7, v11);
    result = 0;
  }
  else
  {
    KfLowerIrql(OldIrql);
    result = -1073741816;
  }
  return result;
}