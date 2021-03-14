void __stdcall SetProjection(float fov, float aspect, float near_plane, float far_plane, _D3DMATRIX *pres)
{
  double v5; // st7
  _D3DMATRIX *v6; // eax
  double v7; // st6
  float s; // [esp+Ch] [ebp-8h]
  float c; // [esp+10h] [ebp-4h]

  fov = fov * 0.5;
  c = cos(fov);
  s = sin(fov);
  v5 = c / s;
  v6 = pres;
  v7 = far_plane / (far_plane - near_plane);
  pres->_11 = v5 * aspect;
  v6->_12 = 0.0;
  v6->_13 = 0.0;
  v6->_14 = 0.0;
  v6->_21 = 0.0;
  v6->_22 = v5;
  v6->_23 = 0.0;
  v6->_24 = 0.0;
  v6->_31 = 0.0;
  v6->_32 = 0.0;
  v6->_33 = v7;
  v6->_34 = 1.0;
  v6->_41 = 0.0;
  v6->_42 = 0.0;
  v6->_43 = -(v7 * near_plane);
  v6->_44 = 0.0;
}