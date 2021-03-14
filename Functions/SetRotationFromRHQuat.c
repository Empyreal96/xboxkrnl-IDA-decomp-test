void __stdcall SetRotationFromRHQuat(D3DVECTOR4 *q, _D3DMATRIX *pres)
{
  D3DVECTOR4 *v2; // eax

  v2 = q;
  pres->_11 = q->x * q->x + q->w * q->w - q->y * q->y - q->z * q->z;
  pres->_12 = (v2->z * v2->w + v2->x * v2->y) * 2.0;
  pres->_13 = v2->z * v2->x * 2.0 - v2->w * v2->y * 2.0;
  pres->_14 = 0.0;
  pres->_21 = v2->x * v2->y * 2.0 - v2->z * v2->w * 2.0;
  pres->_22 = v2->w * v2->w - v2->x * v2->x + v2->y * v2->y - v2->z * v2->z;
  pres->_23 = (v2->x * v2->w + v2->z * v2->y) * 2.0;
  pres->_24 = 0.0;
  pres->_31 = (v2->z * v2->x + v2->w * v2->y) * 2.0;
  pres->_32 = v2->z * v2->y * 2.0 - v2->x * v2->w * 2.0;
  pres->_33 = v2->w * v2->w - v2->x * v2->x - v2->y * v2->y + v2->z * v2->z;
  pres->_34 = 0.0;
  pres->_43 = 0.0;
  pres->_42 = 0.0;
  pres->_41 = 0.0;
  pres->_44 = 1.0;
}