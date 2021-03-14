void __userpurge IoSetShareAccess(int *a1@<edi>, int a2@<esi>, unsigned int DesiredAccess, unsigned int DesiredShareAccess, _FILE_OBJECT *FileObject, _SHARE_ACCESS *ShareAccess)
{
  int v6; // edx
  int v7; // ST0C_4
  char v8; // cl

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v6, v7, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x9B3u, 0);
  }
  v8 = *((_BYTE *)FileObject + 2) & 0xF1 | 2
                                         * (((DesiredAccess & 0x21) != 0) | 2
                                                                          * (2 * (BYTE2(DesiredAccess) & 1) | ((DesiredAccess & 6) != 0)));
  *((_BYTE *)FileObject + 2) = v8;
  if ( v8 & 0xE )
  {
    *((_BYTE *)FileObject + 2) = v8 & 0x8F | 16
                                           * (DesiredShareAccess & 1 | 2
                                                                     * ((DesiredShareAccess >> 1) & 1 | 2 * ((DesiredShareAccess >> 2) & 1)));
    ShareAccess->OpenCount = 1;
    ShareAccess->Readers = (*((_BYTE *)FileObject + 2) >> 1) & 1;
    ShareAccess->Writers = (*((_BYTE *)FileObject + 2) >> 2) & 1;
    ShareAccess->Deleters = (*((_BYTE *)FileObject + 2) >> 3) & 1;
    ShareAccess->SharedRead = (*((_BYTE *)FileObject + 2) >> 4) & 1;
    ShareAccess->SharedWrite = (*((_BYTE *)FileObject + 2) >> 5) & 1;
    ShareAccess->SharedDelete = (*((_BYTE *)FileObject + 2) >> 6) & 1;
  }
  else
  {
    ShareAccess->OpenCount = 0;
    ShareAccess->Readers = 0;
    ShareAccess->Writers = 0;
    ShareAccess->Deleters = 0;
    ShareAccess->SharedRead = 0;
    ShareAccess->SharedWrite = 0;
    ShareAccess->SharedDelete = 0;
  }
}