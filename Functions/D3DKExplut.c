void __userpurge D3DK::Explut(int *a1@<edi>, float n, float *l, float *m)
{
  long double v4; // st7
  float e; // ST00_4
  signed int v6; // eax
  double v7; // st7
  int savedregs; // [esp+8h] [ebp+0h]
  float idx; // [esp+10h] [ebp+8h]

  if ( n >= 1.0 )
  {
    idx = D3DK::Log((int)&savedregs, a1, n) * 1.442695 * 3.0;
    v6 = D3DK::FloatToLong(idx);
    v7 = idx - (double)v6;
    *l = (1.0 - v7) * *(float *)(4 * v6 - 2146916360) + v7 * *(float *)(4 * v6 - 2146916356);
    *m = (1.0 - v7) * *(float *)(4 * v6 - 2146916488) + v7 * *(float *)(4 * v6 - 2146916484);
  }
  else
  {
    if ( n == 0.0 )
    {
      v4 = 0.0;
    }
    else
    {
      e = -(4.1588831 / n);
      v4 = D3DK::Exp(e);
    }
    *l = -v4;
    *m = 1.0 - (1.0 - v4) * n;
  }
}