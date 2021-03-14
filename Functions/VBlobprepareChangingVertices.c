void __thiscall VBlob::prepareChangingVertices(VBlob *this)
{
  VBlob *v1; // edi
  D3DVertexBuffer *v2; // ST00_4
  int v3; // edx
  int v4; // ebx
  signed int v5; // esi
  VBlobBump *v6; // eax
  _D3DVECTOR *v7; // esi
  double v8; // st7
  VBlobChangingVertex *v9; // ebx
  double v10; // st6
  float v11; // eax
  int v12; // eax
  VBlobBump *v13; // ecx
  double v14; // st7
  VBlobBump *v15; // eax
  double v16; // st7
  double v17; // st6
  float *v18; // esi
  float scale; // ST10_4
  VBlobChangingVertex *v20; // edi
  int v21; // eax
  int v22; // ecx
  VBlobBump *vp_blobs_of_interest[32]; // [esp+10h] [ebp-BCh]
  int v24; // [esp+90h] [ebp-3Ch]
  _D3DVECTOR lnorm; // [esp+94h] [ebp-38h]
  float displacement; // [esp+A0h] [ebp-2Ch]
  _D3DVECTOR *us_normal; // [esp+A4h] [ebp-28h]
  _D3DVECTOR delta; // [esp+A8h] [ebp-24h]
  _D3DVECTOR *p_us_normals; // [esp+B4h] [ebp-18h]
  int i; // [esp+B8h] [ebp-14h]
  int face; // [esp+BCh] [ebp-10h]
  VBlob *v32; // [esp+C0h] [ebp-Ch]
  VBlobChangingVertex *p_verts; // [esp+C4h] [ebp-8h]
  int j; // [esp+C8h] [ebp-4h]

  v1 = this;
  p_us_normals = this->m_pUnitSphereNormals;
  v2 = this->m_pBlobVBChangingU;
  v32 = this;
  D3DVertexBuffer_Lock((int *)this, v2, 0, 0, (char **)&p_verts, 0);
  face = 0;
  do
  {
    v3 = v1->m_NumBlobBumps;
    v4 = 0;
    if ( v3 > 0 )
    {
      v5 = 1 << face;
      v6 = v1->m_BlobBumps;
      do
      {
        if ( v5 & v6->facesOfInterest )
          vp_blobs_of_interest[v4++] = v6;
        ++v6;
        --v3;
      }
      while ( v3 );
    }
    i = 0;
    if ( v1->m_NumVertsPerFace > 0 )
    {
      v24 = v4 - 1;
      do
      {
        v7 = p_us_normals;
        v8 = p_us_normals->z;
        v9 = p_verts;
        v10 = p_us_normals->y;
        v11 = p_us_normals->x;
        ++p_us_normals;
        p_verts->normal.y = v10;
        v9->normal.x = v11;
        v12 = v24;
        v9->normal.z = v8;
        v9->normal.w = 0.0;
        us_normal = v7;
        for ( j = v12; j >= 0; --j )
        {
          Sub(v7, &vp_blobs_of_interest[j]->vPosition, &delta);
          v13 = vp_blobs_of_interest[j];
          v14 = delta.z * delta.z + delta.y * delta.y + delta.x * delta.x;
          if ( v14 < v13->fRadius2 )
          {
            v15 = vp_blobs_of_interest[j];
            v16 = v14 * v13->fOORadius2 - 1.0;
            v17 = v1->m_fRadius * v13->fMagnitude;
            lnorm.x = v7->x;
            v18 = &v7->y;
            lnorm.y = *v18;
            lnorm.z = v18[1];
            displacement = v17 * v16 * v16;
            scale = v15->fMagnitude * v15->fOORadius2 * v16 * -4.0;
            AddScaled(&lnorm, &delta, scale);
            QuickNormalize(&lnorm);
            v1 = v32;
            v7 = us_normal;
            v9->normal.x = lnorm.x + v9->normal.x;
            v9->normal.y = lnorm.y + v9->normal.y;
            v9->normal.z = lnorm.z + v9->normal.z;
            v9->normal.w = displacement + v9->normal.w;
          }
        }
        v20 = p_verts;
        ++i;
        v21 = (int)v32;
        v22 = i;
        p_verts->normal.x = v9->normal.x;
        v20 = (VBlobChangingVertex *)((char *)v20 + 4);
        v20->normal.x = v9->normal.y;
        v20 = (VBlobChangingVertex *)((char *)v20 + 4);
        v20->normal.x = v9->normal.z;
        v20->normal.y = v9->normal.w;
        ++p_verts;
        v1 = (VBlob *)v21;
      }
      while ( v22 < *(_DWORD *)(v21 + 48) );
    }
    ++face;
  }
  while ( face < 6 );
}