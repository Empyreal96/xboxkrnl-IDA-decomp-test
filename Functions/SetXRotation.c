void __stdcall SetXRotation(float r, _D3DMATRIX *pres)
{
  _D3DMATRIX *v2; // eax
  float v3; // ecx
  double v4; // st7
  float c; // [esp+10h] [ebp-8h]
  float s; // [esp+14h] [ebp-4h]

  c = cos(r);
  s = sin(r);
  v2 = pres;
  pres->_11 = 1.0;
  v3 = s;
  v2->_12 = 0.0;
  v2->_23 = v3;
  v2->_13 = 0.0;
  v2->_14 = 0.0;
  v2->_21 = 0.0;
  v4 = c;
  v2->_22 = c;
  v2->_24 = 0.0;
  v2->_31 = 0.0;
  v2->_32 = -s;
  v2->_33 = v4;
  v2->_34 = 0.0;
  v2->_43 = 0.0;
  v2->_42 = 0.0;
  v2->_41 = 0.0;
  v2->_44 = 1.0;
}