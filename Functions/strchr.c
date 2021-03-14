char *__cdecl strchr(const char *a1, int a2)
{
  const char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  char *result; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax

  v2 = a1;
  if ( (unsigned __int8)a1 & 3 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      JUMPOUT(v3, a2, found_bx);
      if ( !v3 )
        break;
      if ( !((unsigned __int8)v2 & 3) )
        goto main_loop_0;
    }
retnull_bx:
    result = 0;
  }
  else
  {
    while ( 1 )
    {
main_loop_0:
      while ( 1 )
      {
        v4 = (((unsigned __int8)a2 << 8) | (unsigned __int8)a2 | ((((unsigned __int8)a2 << 8) | (unsigned __int8)a2) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( ((v4 + 2130640639) ^ ~v4) & 0x81010100 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 && (v7 & 0x1010100 || !(v5 & 0x80000000)) )
          goto retnull_bx;
      }
      v9 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v9 == (_BYTE)a2 )
        break;
      if ( !(_BYTE)v9 )
        goto retnull_bx;
      if ( BYTE1(v9) == (_BYTE)a2 )
        return (char *)(v2 - 3);
      if ( !BYTE1(v9) )
        goto retnull_bx;
      v10 = v9 >> 16;
      if ( (_BYTE)v10 == (_BYTE)a2 )
        return (char *)(v2 - 2);
      if ( !(_BYTE)v10 )
        goto retnull_bx;
      if ( BYTE1(v10) == (_BYTE)a2 )
        return (char *)(v2 - 1);
      if ( !BYTE1(v10) )
        goto retnull_bx;
    }
    result = (char *)(v2 - 4);
  }
  return result;
}