void __stdcall SetZRotation(float r, _D3DMATRIX *pres)
{
  double v2; // st7
  _D3DMATRIX *v3; // eax
  float c; // [esp+10h] [ebp-8h]
  float s; // [esp+14h] [ebp-4h]

  c = cos(r);
  s = sin(r);
  v2 = c;
  v3 = pres;
  pres->_11 = c;
  v3->_12 = s;
  v3->_13 = 0.0;
  v3->_14 = 0.0;
  v3->_21 = -s;
  v3->_22 = v2;
  v3->_23 = 0.0;
  v3->_24 = 0.0;
  v3->_31 = 0.0;
  v3->_32 = 0.0;
  v3->_33 = 1.0;
  v3->_34 = 0.0;
  v3->_43 = 0.0;
  v3->_42 = 0.0;
  v3->_41 = 0.0;
  v3->_44 = 1.0;
}