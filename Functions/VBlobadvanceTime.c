void __thiscall VBlob::advanceTime(VBlob *this, float fElapsedTime, float fDt)
{
  VBlob *v3; // esi
  D3DVertexBuffer *v4; // eax
  int v5; // edi
  VBloblet *v6; // ebx
  int v7; // edi
  VBlobBump *v8; // ebx
  signed int v9; // eax
  VBloblet *v10; // eax

  v3 = this;
  if ( fElapsedTime >= 0.60000002 )
  {
    v5 = 0;
    if ( this->m_NumBloblets > 0 )
    {
      v6 = this->m_Bloblets;
      do
      {
        VBloblet::update(v6, fElapsedTime, fDt);
        ++v5;
        ++v6;
      }
      while ( v5 < v3->m_NumBloblets );
    }
    v7 = 0;
    if ( v3->m_NumBlobBumps > 0 )
    {
      v8 = v3->m_BlobBumps;
      do
      {
        v9 = v3->m_NumBloblets;
        if ( v9 >= 8 )
          v10 = 0;
        else
          v10 = &v3->m_Bloblets[v9];
        if ( VBlobBump::update(v8, fElapsedTime, fDt, v10) )
          ++v3->m_NumBloblets;
        ++v7;
        ++v8;
      }
      while ( v7 < v3->m_NumBlobBumps );
    }
    VBlob::prepareChangingVertices(v3);
  }
  else if ( fElapsedTime - fDt > 0.60000002 )
  {
    VBlob::zeroChangingVertices(this);
    v4 = v3->m_pBlobVBChangingR;
    v3->m_pBlobVBChangingR = v3->m_pBlobVBChangingU;
    v3->m_pBlobVBChangingU = v4;
    VBlob::zeroChangingVertices(v3);
  }
}