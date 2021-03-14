void __thiscall Swizzler::Init(Swizzler *this, unsigned int width, unsigned int height, unsigned int depth)
{
  signed int v4; // eax
  unsigned int v5; // edi
  signed int v6; // esi

  this->m_Width = width;
  this->m_Height = height;
  this->m_Depth = depth;
  v4 = 1;
  this->m_MaskU = 0;
  this->m_MaskV = 0;
  this->m_MaskW = 0;
  this->m_u = 0;
  this->m_v = 0;
  this->m_w = 0;
  v5 = 1;
  do
  {
    v6 = 0;
    if ( v5 < width )
    {
      this->m_MaskU |= v4;
      v4 *= 2;
      v6 = v4;
    }
    if ( v5 < height )
    {
      this->m_MaskV |= v4;
      v4 *= 2;
      v6 = v4;
    }
    if ( v5 < depth )
    {
      this->m_MaskW |= v4;
      v4 *= 2;
      v6 = v4;
    }
    v5 *= 2;
  }
  while ( v6 );
}