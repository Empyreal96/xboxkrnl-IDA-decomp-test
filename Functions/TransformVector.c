void __stdcall TransformVector(_D3DVECTOR *v, _D3DMATRIX *mat, _D3DVECTOR *pres)
{
  _D3DMATRIX *v3; // ecx
  _D3DVECTOR *v4; // eax

  v3 = mat;
  v4 = v;
  pres->x = mat->_31 * v->z + mat->_21 * v->y + v->x * mat->_11;
  pres->y = v3->_12 * v4->x + v3->_32 * v4->z + v3->_22 * v4->y;
  pres->z = v3->_13 * v4->x + v3->_33 * v4->z + v3->_23 * v4->y;
}