void __thiscall VBlob::zeroChangingVertices(VBlob *this)
{
  VBlob *v1; // edi
  _D3DVECTOR *v2; // esi
  int v3; // eax
  int i; // ecx
  signed int v5; // [esp+8h] [ebp-8h]
  VBlobChangingVertex *p_verts; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = this->m_pUnitSphereNormals;
  D3DVertexBuffer_Lock((int *)this, this->m_pBlobVBChangingU, 0, 0, (char **)&p_verts, 0);
  v3 = v1->m_NumVertsPerFace;
  v5 = 6;
  do
  {
    for ( i = 0; i < v3; ++p_verts )
    {
      p_verts->normal.x = v2->x;
      p_verts->normal.y = v2->y;
      ++i;
      p_verts->normal.z = v2->z;
      ++v2;
      p_verts->normal.w = 1.0;
      v3 = v1->m_NumVertsPerFace;
    }
    --v5;
  }
  while ( v5 );
}