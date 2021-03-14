double __stdcall D3DK::JBInvSqrt(const float x)
{
  float y; // ST00_4

  y = (1.47 - COERCE_FLOAT((-1098907648 - LODWORD(x)) >> 1) * COERCE_FLOAT((-1098907648 - LODWORD(x)) >> 1) * (0.47 * x))
    * COERCE_FLOAT((-1098907648 - LODWORD(x)) >> 1);
  return (3.0 - COERCE_FLOAT(LODWORD(y) & 0x7FFFFFFF) * COERCE_FLOAT(LODWORD(y) & 0x7FFFFFFF) * x)
       * COERCE_FLOAT(LODWORD(y) & 0x7FFFFFFF)
       * 0.5;
}