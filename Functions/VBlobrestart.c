void __thiscall VBlob::restart(VBlob *this)
{
  VBlob *v1; // esi
  signed int v2; // eax
  VBloblet *v3; // edx
  VBlobBump *v4; // ecx
  D3DVertexBuffer *v5; // eax

  v1 = this;
  this->m_NumBloblets = 0;
  this->m_NumBlobBumps = 0;
  do
  {
    v2 = v1->m_NumBloblets;
    if ( v2 >= 8 )
      v3 = 0;
    else
      v3 = &v1->m_Bloblets[v2];
    v4 = &v1->m_BlobBumps[v1->m_NumBlobBumps++];
    if ( (unsigned __int8)VBlobBump::create(v4, -0.30000001, v3) )
      ++v1->m_NumBloblets;
  }
  while ( v1->m_NumBlobBumps < 32 );
  VBlob::zeroChangingVertices(v1);
  v5 = v1->m_pBlobVBChangingR;
  v1->m_pBlobVBChangingR = v1->m_pBlobVBChangingU;
  v1->m_pBlobVBChangingU = v5;
  VBlob::zeroChangingVertices(v1);
}