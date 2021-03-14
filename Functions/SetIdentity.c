void __stdcall SetIdentity(_D3DMATRIX *pres)
{
  pres->_44 = 1.0;
  pres->_33 = 1.0;
  pres->_22 = 1.0;
  pres->_11 = 1.0;
  pres->_43 = 0.0;
  pres->_42 = 0.0;
  pres->_41 = 0.0;
  pres->_34 = 0.0;
  pres->_32 = 0.0;
  pres->_31 = 0.0;
  pres->_24 = 0.0;
  pres->_23 = 0.0;
  pres->_21 = 0.0;
  pres->_14 = 0.0;
  pres->_13 = 0.0;
  pres->_12 = 0.0;
}