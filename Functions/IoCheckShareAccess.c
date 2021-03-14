int __userpurge IoCheckShareAccess@<eax>(int *a1@<edi>, int a2@<esi>, unsigned int DesiredAccess, unsigned int DesiredShareAccess, _FILE_OBJECT *FileObject, _SHARE_ACCESS *ShareAccess, char Update)
{
  int v7; // edx
  int v8; // ST0C_4
  _FILE_OBJECT *v9; // esi
  char v10; // al
  char v11; // cl
  unsigned __int8 v12; // dl
  char v13; // bl
  char DesiredAccess_3; // [esp+13h] [ebp+Bh]
  char FileObject_3; // [esp+1Bh] [ebp+13h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v7, v8, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x286u, 0);
  }
  v9 = FileObject;
  v10 = *((_BYTE *)FileObject + 2) & 0xF1 | 2
                                          * (((DesiredAccess & 0x21) != 0) | 2
                                                                           * (2 * (BYTE2(DesiredAccess) & 1) | ((DesiredAccess & 6) != 0)));
  *((_BYTE *)FileObject + 2) = v10;
  if ( !(v10 & 0xE) )
    return 0;
  v11 = v10 & 0x8F | 16
                   * (DesiredShareAccess & 1 | 2 * ((DesiredShareAccess >> 1) & 1 | 2 * ((DesiredShareAccess >> 2) & 1)));
  *((_BYTE *)FileObject + 2) = v11;
  v12 = ShareAccess->OpenCount;
  if ( ShareAccess->OpenCount != -1
    && (!(v11 & 2) || ShareAccess->SharedRead >= v12)
    && (!(v11 & 4) || ShareAccess->SharedWrite >= v12)
    && (!(v11 & 8) || ShareAccess->SharedDelete >= v12) )
  {
    DesiredAccess_3 = ShareAccess->Readers;
    if ( !ShareAccess->Readers || v11 & 0x10 )
    {
      FileObject_3 = ShareAccess->Writers;
      if ( !ShareAccess->Writers || v11 & 0x20 )
      {
        v13 = ShareAccess->Deleters;
        if ( !v13 || v11 & 0x40 )
        {
          if ( Update )
          {
            ShareAccess->OpenCount = v12 + 1;
            ShareAccess->Readers = DesiredAccess_3 + ((*((_BYTE *)v9 + 2) >> 1) & 1);
            ShareAccess->Writers = FileObject_3 + ((*((_BYTE *)v9 + 2) >> 2) & 1);
            ShareAccess->Deleters = v13 + ((*((_BYTE *)v9 + 2) >> 3) & 1);
            ShareAccess->SharedRead += (*((_BYTE *)v9 + 2) >> 4) & 1;
            ShareAccess->SharedWrite += (*((_BYTE *)v9 + 2) >> 5) & 1;
            ShareAccess->SharedDelete += (*((_BYTE *)v9 + 2) >> 6) & 1;
          }
          return 0;
        }
      }
    }
  }
  return -1073741757;
}