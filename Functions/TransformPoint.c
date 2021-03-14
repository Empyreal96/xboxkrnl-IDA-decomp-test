void __stdcall TransformPoint(D3DVECTOR4 *pt, _D3DMATRIX *mat, D3DVECTOR4 *pres)
{
  _D3DMATRIX *v3; // ecx
  D3DVECTOR4 *v4; // eax

  v3 = mat;
  v4 = pt;
  pres->x = mat->_41 * pt->w + mat->_21 * pt->y + mat->_31 * pt->z + pt->x * mat->_11;
  pres->y = v3->_12 * v4->x + v3->_42 * v4->w + v3->_22 * v4->y + v3->_32 * v4->z;
  pres->z = v3->_13 * v4->x + v3->_43 * v4->w + v3->_23 * v4->y + v3->_33 * v4->z;
  pres->w = v3->_14 * v4->x + v3->_44 * v4->w + v3->_24 * v4->y + v3->_34 * v4->z;
}