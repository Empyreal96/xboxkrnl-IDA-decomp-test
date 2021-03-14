int __usercall XepResolveNonKernelImageImports@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  int v3; // edi
  int v4; // edx
  int v5; // ecx
  _LIST_ENTRY *v6; // esi
  int result; // eax
  _UNICODE_STRING ImageName; // [esp+Ch] [ebp-8h]

  if ( !MEMORY[0x1015C] )
    RtlAssert(
      a1,
      a2,
      a3,
      0,
      "XeImageHeader()->ImportDirectory != NULL",
      "d:\\xbox-apr03\\private\\ntos\\ldrx\\loader.c",
      0x46Cu,
      0);
  v3 = MEMORY[0x1015C];
  if ( !*MEMORY[0x1015C] )
    return 0;
  while ( 1 )
  {
    RtlInitUnicodeString(&ImageName, *(PCWSTR *)(v3 + 4));
    v6 = KdLoadedModuleList.Flink;
    if ( IsListEmpty(&KdLoadedModuleList) )
      break;
    while ( !RtlEqualUnicodeString(v5, v4, &ImageName, (_UNICODE_STRING *)&v6[5].Blink, 1) )
    {
      v6 = v6->Flink;
      if ( v6 == &KdLoadedModuleList )
        goto LABEL_9;
    }
    result = XepResolveImageImports((int *)v3, v6[3].Flink, *(_IMAGE_THUNK_DATA32 **)v3);
    if ( result < 0 )
      return result;
LABEL_9:
    if ( v6 == &KdLoadedModuleList )
      break;
    v3 += 8;
    if ( !*(_DWORD *)v3 )
      return 0;
  }
  DbgPrint((int *)v3, "LDRX: cannot import from module %wZ.\n", &ImageName);
  return -1073741515;
}