void __stdcall SetLookAt(_D3DVECTOR *cam, _D3DVECTOR *look, _D3DVECTOR *up, _D3DMATRIX *pres)
{
  float v4; // eax
  float v5; // eax
  float v6; // eax
  float v7; // eax
  float v8; // eax
  float v9; // eax
  _D3DVECTOR yAxis; // [esp+8h] [ebp-24h]
  _D3DVECTOR xAxis; // [esp+14h] [ebp-18h]
  _D3DVECTOR zAxis; // [esp+20h] [ebp-Ch]

  zAxis.x = look->x;
  zAxis.y = look->y;
  zAxis.z = look->z;
  zAxis.x = zAxis.x - cam->x;
  zAxis.y = zAxis.y - cam->y;
  zAxis.z = zAxis.z - cam->z;
  Normalize(&zAxis);
  Cross(&zAxis, up, &xAxis);
  Normalize(&xAxis);
  Cross(&xAxis, &zAxis, &yAxis);
  v4 = yAxis.x;
  pres->_11 = xAxis.x;
  pres->_12 = v4;
  v5 = zAxis.x;
  pres->_14 = 0.0;
  pres->_13 = v5;
  v6 = xAxis.y;
  pres->_24 = 0.0;
  pres->_21 = v6;
  v7 = yAxis.y;
  pres->_34 = 0.0;
  pres->_22 = v7;
  pres->_23 = zAxis.y;
  v8 = xAxis.z;
  pres->_43 = 0.0;
  pres->_31 = v8;
  v9 = yAxis.z;
  pres->_42 = 0.0;
  pres->_32 = v9;
  pres->_33 = zAxis.z;
  pres->_41 = 0.0;
  pres->_44 = 1.0;
  yAxis.x = -cam->x;
  yAxis.y = -cam->y;
  yAxis.z = -cam->z;
  TransformVector(&yAxis, pres, &xAxis);
  *(_QWORD *)&pres->m[3][0] = *(_QWORD *)&xAxis.x;
  pres->_43 = xAxis.z;
}