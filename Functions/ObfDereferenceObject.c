void __fastcall ObfDereferenceObject(void *Object, int a2)
{
  int *v2; // edi
  char *v3; // esi
  void (__fastcall *v11)(char *, int, int *); // eax
  int *v12; // edi

  v2 = (int *)Object;
  v3 = (char *)Object - 16;
  _EAX = -1;
  _ECX = (char *)Object - 16;
  __asm { xadd    [Object], eax }
  if ( _EAX == 1 )
  {
    if ( *((_DWORD *)v3 + 1) )
      RtlAssert(
        a2,
        (int)_ECX,
        v2,
        (int)v3,
        "ObjectHeader->HandleCount == 0",
        "d:\\xbox-apr03\\private\\ntos\\obx\\obref.c",
        0x15Cu,
        0);
    v11 = *(void (__fastcall **)(char *, int, int *))(*((_DWORD *)v3 + 2) + 12);
    if ( v11 )
      v11(_ECX, a2, v2);
    if ( v3[12] & 1 )
    {
      v12 = (int *)(v3 - 16);
      if ( *((_DWORD *)v3 - 3) )
        RtlAssert(
          a2,
          (int)_ECX,
          v12,
          (int)v3,
          "((POBJECT_HEADER_NAME_INFO)ObjectBase)->Directory == NULL",
          "d:\\xbox-apr03\\private\\ntos\\obx\\obref.c",
          0x16Cu,
          0);
    }
    else
    {
      v12 = (int *)v3;
    }
    (*(void (__fastcall **)(char *, int, int *))(*((_DWORD *)v3 + 2) + 4))(_ECX, a2, v12);
  }
}