char __userpurge ObpCreatePermanentDirectoryObject@<al>(_OBJECT_DIRECTORY *a1@<ecx>, int *a2@<edi>, int a3@<esi>, _STRING *DirectoryName, _OBJECT_DIRECTORY **DirectoryObject)
{
  int v5; // edx
  int v6; // ecx
  _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+0h] [ebp-Ch]

  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.ObjectName = DirectoryName;
  ObjectAttributes.Attributes = 16;
  if ( NtCreateDirectoryObject(a1, (void **)&DirectoryName, &ObjectAttributes) < 0
    || ObReferenceObjectByHandle(v5, v6, a2, a3, DirectoryName, &ObDirectoryObjectType, (void **)DirectoryObject) < 0 )
  {
    return 0;
  }
  NtClose(a2, DirectoryName);
  return 1;
}