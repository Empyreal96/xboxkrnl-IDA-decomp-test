int __thiscall NtCreateDirectoryObject(_OBJECT_DIRECTORY *this, void **DirectoryHandle, _OBJECT_ATTRIBUTES *ObjectAttributes)
{
  int result; // eax
  _OBJECT_DIRECTORY *Directory; // [esp+0h] [ebp-4h]

  Directory = this;
  result = ObCreateObject(&ObDirectoryObjectType, ObjectAttributes, 0x2Cu, (void **)&Directory);
  if ( result >= 0 )
  {
    memset(Directory, 0, sizeof(_OBJECT_DIRECTORY));
    result = ObInsertObject(Directory, ObjectAttributes, 0, DirectoryHandle);
  }
  return result;
}