// write access to const memory has been detected, the output may be wrong!
void __thiscall VBlob::Init(VBlob *this)
{
  VBloblet **v1; // edx
  signed int v2; // esi
  float *v3; // edx
  signed int v4; // esi

  v1 = &this->m_BlobBumps[0].pMyBloblet;
  v2 = 32;
  do
  {
    *v1 = 0;
    v1 += 16;
    --v2;
  }
  while ( v2 );
  v3 = &this->m_Bloblets[0].fWobbleDirection;
  v4 = 8;
  do
  {
    *(v3 - 1) = 1.0;
    *v3 = 0.0;
    v3 += 14;
    --v4;
  }
  while ( v4 );
  VBlob::m_QRand.seed = 1985229328;
  this->m_pBlobVBChangingU = 0;
  this->m_pBlobVBChangingR = 0;
  this->m_pBlobVBConst = 0;
  this->m_pBlobletVB = 0;
  this->m_pBlobIB = 0;
  this->m_pBlobletIB = 0;
  this->m_pUnitSphereNormals = 0;
  this->m_dwNumIndices = 0;
  this->m_dwNumVertices = 0;
  this->m_NumVertsPerFace = 0;
  this->m_dwNumBlobletIndices = 0;
  this->m_dwNumBlobletVertices = 0;
  this->m_dwVShaderBloblet = 0;
  this->m_dwVShaderBlob = 0;
  this->m_dwPShaderBloblet = 0;
  this->m_dwPShaderBlob = 0;
  this->m_NumBloblets = 0;
  this->m_NumBlobBumps = 0;
  this->m_BlobColor.y = 1.0;
  this->m_BlobColor.x = 0.25;
  this->m_BlobColor.w = 1.0;
  this->m_BlobColor.z = 0.15000001;
  this->m_Pos.x = 0.0;
  this->m_Pos.y = 0.0;
  this->m_Pos.z = 0.0;
  this->m_Scale.x = 1.0;
  this->m_Scale.y = 1.0;
  this->m_Scale.z = 1.0;
  this->m_fRadius = 2.3;
}