char *__cdecl strstr(const char *a1, const char *a2)
{
  char v2; // dl
  const char *v3; // edi
  char v4; // dh
  const char *v5; // ecx
  char *v6; // esi
  char v7; // al
  char v9; // ah
  char v10; // al
  char v11; // al

  v2 = *a2;
  v3 = a1;
  if ( !*a2 )
    return (char *)a1;
  v4 = a2[1];
  if ( !v4 )
    JUMPOUT(&__from_strstr_to_strchr);
findnext:
  v5 = a2;
  v6 = (char *)(v3 + 1);
  if ( *v3 == v2 )
    goto first_char_found;
  if ( *v3 )
  {
    while ( 2 )
    {
      v7 = *v6++;
      while ( v7 == v2 )
      {
first_char_found:
        v7 = *v6++;
        if ( v7 == v4 )
        {
          v3 = v6 - 1;
          while ( 1 )
          {
            v9 = v5[2];
            if ( !v9 )
              break;
            v10 = *v6;
            v6 += 2;
            if ( v10 != v9 )
              goto findnext;
            v11 = v5[3];
            if ( !v11 )
              break;
            v5 += 2;
            if ( v11 != *(v6 - 1) )
              goto findnext;
          }
          return (char *)(v3 - 1);
        }
      }
      if ( v7 )
        continue;
      break;
    }
  }
  return 0;
}