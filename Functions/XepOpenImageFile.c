int *__userpurge XepOpenImageFile@<eax>(int *a1@<edi>, int a2@<esi>, void **ImageFileHandle)
{
  _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+0h] [ebp-14h]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+Ch] [ebp-8h]

  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = &XeImageFileName;
  return NtOpenFile(a1, a2, ImageFileHandle, 0x80000000, &ObjectAttributes, &IoStatusBlock, 1u, 0x60u);
}