void __thiscall XBoxStartupApp::initIntensityPulses(XBoxStartupApp *this)
{
  XBoxStartupApp *v1; // edi
  int v2; // eax
  float *v3; // esi
  double v4; // st7
  double v5; // st5
  float v6; // ST14_4
  double v7; // st7
  double v8; // st6
  float v9; // ST14_4
  double v10; // st6
  float v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]

  v1 = this;
  v2 = 0;
  v3 = (float *)this->vPulses;
  do
  {
    v12 = v2 + 1;
    v4 = XBoxStartupApp::fRand11(v1);
    v5 = 1.0 - (v4 * 0.029999999 + (double)v12 * 0.07692308 + 1.0) * (v4 * 0.029999999 + (double)v12 * 0.07692308) * 0.5;
    *v3 = v5;
    v6 = 1.2 - v5;
    v7 = (XBoxStartupApp::fRand01(&gApp) + 2.0) * v6 * v6 * 0.050000001;
    if ( v7 < 0.1 )
      v7 = 0.1;
    v3[1] = v7;
    v3[2] = (XBoxStartupApp::fRand01(&gApp) + 1.0) * (*v3 + 0.5) * 0.2;
    v8 = *v3 * 5.0 + 0.60000002;
    v9 = v8;
    v11 = v8;
    *v3 = v8;
    v10 = v3[1] + 0.60000002;
    if ( v10 < v9 )
      v10 = v11;
    v2 = v12;
    *v3 = v10;
    v3 += 3;
  }
  while ( v12 < 12 );
  v1->vPulses[11].x = v1->vPulses[11].y + 0.60000002;
  v1->vPulses[11].z = v1->vPulses[11].z * 3.0;
}