int __stdcall CreateTristripForMesh(unsigned __int16 *p_index_buffer, int x_quads, int y_quads, __int16 b_double_tap_first, bool b_double_tap_last, int start_index, int vstride, int hstride)
{
  signed int v8; // eax
  int v9; // edi
  int v10; // eax
  int result; // eax
  __int16 v12; // bx
  unsigned __int16 *v13; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // edx
  __int16 v17; // di
  int v18; // eax
  int i; // [esp+18h] [ebp+8h]
  int j; // [esp+24h] [ebp+14h]

  v8 = 0;
  if ( !vstride )
    vstride = x_quads + 1;
  v9 = 1;
  if ( !hstride )
    hstride = 1;
  if ( x_quads <= 14 )
  {
    v12 = start_index;
    v13 = p_index_buffer;
    if ( (_BYTE)b_double_tap_first )
    {
      *p_index_buffer = start_index;
      v8 = 1;
    }
    p_index_buffer[v8] = start_index;
    result = v8 + 1;
    if ( x_quads >= 1 )
    {
      do
      {
        v14 = start_index + v9 * hstride;
        p_index_buffer[result] = v14;
        v15 = result + 1;
        p_index_buffer[v15] = v14;
        result = v15 + 1;
        ++v9;
      }
      while ( v9 <= x_quads );
    }
    LOWORD(v16) = y_quads;
    j = 0;
    if ( y_quads > 0 )
    {
      do
      {
        v17 = vstride * j;
        i = 0;
        v13[result++] = vstride * j + v12;
        if ( x_quads >= 0 )
        {
          while ( 1 )
          {
            v12 = start_index;
            v13[result] = start_index + hstride * i + v17;
            v18 = result + 1;
            v13[v18] = start_index + vstride * (j + 1) + hstride * i;
            result = v18 + 1;
            if ( ++i > x_quads )
              break;
            v17 = vstride * j;
          }
        }
        v16 = y_quads;
        if ( j < y_quads - 1 )
        {
          v12 = start_index;
          v16 = y_quads;
          v13[result++] = start_index + vstride * (j + 1) + hstride * x_quads;
        }
        ++j;
      }
      while ( j < v16 );
    }
    if ( b_double_tap_last )
      v13[result++] = v12 + vstride * v16 + hstride * x_quads;
  }
  else
  {
    v10 = CreateTristripForMesh(p_index_buffer, 14, y_quads, b_double_tap_first, 1, start_index, vstride, hstride);
    result = v10
           + CreateTristripForMesh(
               &p_index_buffer[v10],
               x_quads - 14,
               y_quads,
               1,
               b_double_tap_last,
               start_index + 14 * hstride,
               vstride,
               hstride);
  }
  return result;
}