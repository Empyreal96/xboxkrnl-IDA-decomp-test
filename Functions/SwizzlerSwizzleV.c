unsigned int __thiscall Swizzler::SwizzleV(Swizzler *this, unsigned int num)
{
  unsigned int v2; // ecx
  unsigned int v3; // edx
  unsigned int result; // eax

  v2 = this->m_MaskV;
  v3 = 1;
  for ( result = 0; v3 <= v2; v3 *= 2 )
  {
    if ( v2 & v3 )
      result |= num & v3;
    else
      num *= 2;
  }
  return result;
}