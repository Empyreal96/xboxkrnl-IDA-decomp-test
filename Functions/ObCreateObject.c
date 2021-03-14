int __stdcall ObCreateObject(_OBJECT_TYPE *ObjectType, _OBJECT_ATTRIBUTES *ObjectAttributes, unsigned int ObjectBodySize, void **Object)
{
  _STRING *v4; // eax
  bool v5; // zf
  char *v6; // eax
  unsigned int v8; // esi
  int v9; // eax
  char *v10; // edi
  _DWORD *v11; // eax
  _STRING RemainingName; // [esp+Ch] [ebp-10h]
  _STRING ElementName; // [esp+14h] [ebp-8h]

  *Object = 0;
  if ( ObjectAttributes && (v4 = ObjectAttributes->ObjectName) != 0 )
  {
    v5 = (unsigned __int16)*(_DWORD *)&v4->Length == 0;
    *(_DWORD *)&RemainingName.Length = *(_DWORD *)&v4->Length;
    v6 = v4->Buffer;
    RemainingName.Buffer = v6;
    ElementName.Buffer = 0;
    ElementName.Length = 0;
    if ( v5 )
      return -1073741773;
    while ( 1 )
    {
      ObDissectName(
        (_STRING)__PAIR__((unsigned int)v6, *(unsigned int *)&RemainingName.Length),
        &ElementName,
        &RemainingName);
      if ( !RemainingName.Length )
        break;
      v6 = RemainingName.Buffer;
      if ( *RemainingName.Buffer == 92 )
        return -1073741773;
    }
    if ( !ElementName.Length )
      return -1073741773;
    v8 = (ObjectBodySize + 3) & 0xFFFFFFFC;
    v9 = ObjectType->AllocateProcedure(ElementName.Length + v8 + 32, ObjectType->PoolTag);
    if ( !v9 )
      return -1073741670;
    *(_DWORD *)v9 = 0;
    *(_DWORD *)(v9 + 4) = 0;
    v10 = (char *)(v9 + v8 + 32);
    *(_DWORD *)(v9 + 12) = v10;
    *(_WORD *)(v9 + 8) = ElementName.Length;
    *(_WORD *)(v9 + 10) = ElementName.Length;
    qmemcpy(v10, ElementName.Buffer, ElementName.Length);
    *(_DWORD *)(v9 + 20) = 0;
    *(_DWORD *)(v9 + 16) = 1;
    *(_DWORD *)(v9 + 28) = 1;
    *(_DWORD *)(v9 + 24) = ObjectType;
    *Object = (void *)(v9 + 32);
  }
  else
  {
    v11 = (_DWORD *)ObjectType->AllocateProcedure(ObjectBodySize + 16, ObjectType->PoolTag);
    if ( !v11 )
      return -1073741670;
    *v11 = 1;
    v11[1] = 0;
    v11[2] = ObjectType;
    v11[3] = 0;
    *Object = v11 + 4;
  }
  return 0;
}