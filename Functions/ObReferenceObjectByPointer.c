int __stdcall ObReferenceObjectByPointer(void *Object, _OBJECT_TYPE *ObjectType)
{
  _OBJECT_HEADER *ObjectHeader; // [esp+8h] [ebp+8h]

  _ZF = ObjectType == *((_OBJECT_TYPE **)Object - 2);
  ObjectHeader = (_OBJECT_HEADER *)((char *)Object - 16);
  if ( !_ZF )
    return -1073741788;
  _EAX = 1;
  _ECX = ObjectHeader;
  __asm { xadd    [ecx], eax }
  return 0;
}