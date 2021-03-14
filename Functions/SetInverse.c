void __stdcall SetInverse(_D3DMATRIX *mat, _D3DMATRIX *pres)
{
  float v2; // ecx
  float v3; // ecx
  float v4; // ecx
  float v5; // eax
  _D3DVECTOR r_inv_trans; // [esp+4h] [ebp-18h]
  _D3DVECTOR inv_trans; // [esp+10h] [ebp-Ch]

  pres->_11 = mat->_11;
  pres->_12 = mat->_21;
  v2 = mat->_31;
  pres->_14 = 0.0;
  pres->_13 = v2;
  pres->_21 = mat->_12;
  pres->_22 = mat->_22;
  v3 = mat->_32;
  pres->_24 = 0.0;
  pres->_23 = v3;
  pres->_31 = mat->_13;
  pres->_32 = mat->_23;
  v4 = mat->_33;
  pres->_34 = 0.0;
  pres->_33 = v4;
  inv_trans.x = -mat->_41;
  inv_trans.y = -mat->_42;
  inv_trans.z = -mat->_43;
  TransformVector(&inv_trans, pres, &r_inv_trans);
  v5 = r_inv_trans.x;
  pres->_44 = 1.0;
  pres->_41 = v5;
  *(_QWORD *)&pres->m[3][1] = *(_QWORD *)&r_inv_trans.y;
}