double __thiscall XBoxStartupApp::sumIntensityPulses(XBoxStartupApp *this, float et)
{
  float *v2; // esi
  signed int v3; // edi
  float x; // ST00_4
  double v5; // st7
  float s; // [esp+1Ch] [ebp-10h]
  float sum; // [esp+20h] [ebp-Ch]
  float c; // [esp+24h] [ebp-8h]
  float v10; // [esp+28h] [ebp-4h]

  sum = 0.0;
  v2 = &this->vPulses[0].y;
  v3 = 12;
  do
  {
    x = et - *(v2 - 1);
    v5 = fast_fabs(x);
    if ( v5 <= *v2 )
    {
      v10 = v5 / *v2 * 1.5707964;
      c = cos(v10);
      s = sin(v10);
      sum = c * v2[1] + sum;
    }
    v2 += 3;
    --v3;
  }
  while ( v3 );
  return sum;
}