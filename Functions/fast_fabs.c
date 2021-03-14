double __stdcall fast_fabs(float x)
{
  return COERCE_FLOAT(LODWORD(x) & 0x7FFFFFFF);
}