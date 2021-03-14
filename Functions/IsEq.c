BOOL __stdcall IsEq(float a, float b)
{
  float x; // ST00_4

  x = a - b;
  return fast_fabs(x) <= 0.0000099999997;
}