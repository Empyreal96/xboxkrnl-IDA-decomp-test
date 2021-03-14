void __userpurge IoRemoveShareAccess(int *a1@<edi>, int a2@<esi>, _FILE_OBJECT *FileObject, _SHARE_ACCESS *ShareAccess)
{
  int v4; // edx
  int v5; // ST0C_4

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v4, v5, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x95Bu, 0);
  }
  if ( *((_BYTE *)FileObject + 2) & 0xE )
  {
    --ShareAccess->OpenCount;
    if ( *((_BYTE *)FileObject + 2) & 2 )
      --ShareAccess->Readers;
    if ( *((_BYTE *)FileObject + 2) & 4 )
      --ShareAccess->Writers;
    if ( *((_BYTE *)FileObject + 2) & 8 )
      --ShareAccess->Deleters;
    if ( *((_BYTE *)FileObject + 2) & 0x10 )
      --ShareAccess->SharedRead;
    if ( *((_BYTE *)FileObject + 2) & 0x20 )
      --ShareAccess->SharedWrite;
    if ( *((_BYTE *)FileObject + 2) & 0x40 )
      --ShareAccess->SharedDelete;
  }
}