void __stdcall TransformPoint(_D3DVECTOR *pt, _D3DMATRIX *mat, _D3DVECTOR *pres)
{
  _D3DMATRIX *v3; // eax
  _D3DVECTOR *v4; // ecx

  v3 = mat;
  v4 = pt;
  pres->x = mat->_31 * pt->z + mat->_21 * pt->y + pt->x * mat->_11 + mat->_41;
  pres->y = v3->_12 * v4->x + v3->_32 * v4->z + v3->_22 * v4->y + v3->_42;
  pres->z = v3->_13 * v4->x + v3->_33 * v4->z + v3->_23 * v4->y + v3->_43;
}