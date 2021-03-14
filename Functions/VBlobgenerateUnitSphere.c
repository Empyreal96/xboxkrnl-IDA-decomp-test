char __stdcall VBlob::generateUnitSphere(int resolution, D3DVertexBuffer **pp_vb, D3DIndexBuffer **pp_ib, _D3DVECTOR **pp_us, unsigned int *num_verts, unsigned int *num_indices)
{
  signed int v6; // ebx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  _D3DVECTOR *v11; // eax
  VBlobConstantVertex *v12; // esi
  bool v13; // zf
  double v14; // st7
  double v15; // st7
  _DWORD *v16; // edi
  _DWORD *v17; // esi
  unsigned __int16 *p_indices; // [esp+Ch] [ebp-Ch]
  VBlobConstantVertex *p_verts; // [esp+10h] [ebp-8h]
  float f_division_step; // [esp+14h] [ebp-4h]
  int k; // [esp+20h] [ebp+8h]
  int i; // [esp+24h] [ebp+Ch]
  int ia; // [esp+24h] [ebp+Ch]
  int j; // [esp+28h] [ebp+10h]
  float fu; // [esp+2Ch] [ebp+14h]
  signed int fua; // [esp+2Ch] [ebp+14h]
  VBlobConstantVertex *p_vert; // [esp+30h] [ebp+18h]
  _D3DVECTOR *p_us; // [esp+34h] [ebp+1Ch]
  _D3DVECTOR *p_usa; // [esp+34h] [ebp+1Ch]

  v6 = 1;
  if ( resolution / 2 >= 1 )
    v6 = resolution / 2;
  *num_verts = 6 * (v6 + 1) * (v6 + 1);
  f_division_step = 2.0 / (double)v6;
  *num_indices = 6 * GetNumberOfIndicesForTristripMesh(v6, v6, 0, 0) + 10;
  D3DDevice_CreateVertexBuffer(0, (int)num_indices, (int)num_verts, 12 * *num_verts, 0, 0, 0, pp_vb);
  D3DDevice_CreateIndexBuffer(v7, v8, (int)num_verts, 2 * *num_indices, 8u, D3DFMT_INDEX16, 0, pp_ib);
  if ( pp_us )
    *pp_us = (_D3DVECTOR *)MemAlloc(v9, v10, *num_verts, 12 * *num_verts);
  D3DVertexBuffer_Lock(0, *pp_vb, 0, 0, (char **)&p_verts, 0);
  p_indices = (unsigned __int16 *)(*pp_ib)->Data;
  BYTE1(v11) = BYTE1(pp_us);
  if ( pp_us )
  {
    v11 = *pp_us;
    p_us = *pp_us;
  }
  else
  {
    p_us = 0;
  }
  v12 = p_verts;
  p_vert = p_verts;
  k = 0;
  do
  {
    j = 0;
    if ( v6 < 0 )
      goto LABEL_34;
    do
    {
      i = 0;
      v13 = v6 == 0;
      do
      {
        if ( v13 )
          v14 = 1.0;
        else
          v14 = (double)i * f_division_step - 1.0;
        fu = v14;
        if ( j == v6 )
          v15 = 1.0;
        else
          v15 = (double)j * f_division_step - 1.0;
        if ( k )
        {
          switch ( k )
          {
            case 1:
              v12->unit_sphere_normal.x = v15;
              v12->unit_sphere_normal.y = -1.0;
              v15 = -fu;
              break;
            case 2:
              v12->unit_sphere_normal.z = -1.0;
              v12->unit_sphere_normal.x = -fu;
              v12->unit_sphere_normal.y = v15;
              goto LABEL_30;
            case 3:
              v12->unit_sphere_normal.x = 1.0;
              v12->unit_sphere_normal.y = fu;
              break;
            case 4:
              v12->unit_sphere_normal.x = v15;
              v12->unit_sphere_normal.z = fu;
              v12->unit_sphere_normal.y = 1.0;
              goto LABEL_30;
            case 5:
              v12->unit_sphere_normal.y = v15;
              v12->unit_sphere_normal.x = fu;
              v15 = 1.0;
              break;
            default:
              goto LABEL_30;
          }
        }
        else
        {
          v12->unit_sphere_normal.x = -1.0;
          v12->unit_sphere_normal.y = -fu;
        }
        v12->unit_sphere_normal.z = v15;
LABEL_30:
        Normalize(&v12->unit_sphere_normal);
        if ( p_us )
        {
          v16 = (_DWORD *)&p_us->x;
          ++p_us;
          *v16 = LODWORD(v12->unit_sphere_normal.x);
          v17 = (_DWORD *)&v12->unit_sphere_normal.y;
          ++v16;
          *v16 = *v17;
          v16[1] = v17[1];
          v12 = p_vert;
        }
        ++v12;
        v13 = ++i == v6;
        p_vert = v12;
      }
      while ( i <= v6 );
      ++j;
    }
    while ( j <= v6 );
LABEL_34:
    ++k;
  }
  while ( k < 6 );
  p_usa = 0;
  fua = 0;
  ia = 0;
  do
  {
    LOBYTE(v11) = fua > 0;
    v11 = (_D3DVECTOR *)CreateTristripForMesh(&p_indices[(_DWORD)p_usa], v6, v6, (__int16)v11, fua < 5, ia, 0, 0);
    p_usa = (_D3DVECTOR *)((char *)p_usa + (_DWORD)v11);
    ++fua;
    ia += (v6 + 1) * (v6 + 1);
  }
  while ( fua < 6 );
  return 1;
}