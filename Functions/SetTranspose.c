void __stdcall SetTranspose(_D3DMATRIX *mat, _D3DMATRIX *pres)
{
  pres->_11 = mat->_11;
  pres->_12 = mat->_21;
  pres->_13 = mat->_31;
  pres->_14 = mat->_41;
  pres->_21 = mat->_12;
  pres->_22 = mat->_22;
  pres->_23 = mat->_32;
  pres->_24 = mat->_42;
  pres->_31 = mat->_13;
  pres->_32 = mat->_23;
  pres->_33 = mat->_33;
  pres->_34 = mat->_43;
  pres->_41 = mat->_14;
  pres->_42 = mat->_24;
  pres->_43 = mat->_34;
  pres->_44 = mat->_44;
}