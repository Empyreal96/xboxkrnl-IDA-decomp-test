void __stdcall D3DK::DumpMatrixTransposed(unsigned int *pPush, unsigned int encodedMethod, _D3DMATRIX *pMatrix)
{
  *pPush = encodedMethod;
  pPush[1] = LODWORD(pMatrix->_11);
  pPush[2] = LODWORD(pMatrix->m[1][0]);
  pPush[3] = LODWORD(pMatrix->m[2][0]);
  pPush[4] = LODWORD(pMatrix->m[3][0]);
  pPush[5] = LODWORD(pMatrix->m[0][1]);
  pPush[6] = LODWORD(pMatrix->m[1][1]);
  pPush[7] = LODWORD(pMatrix->m[2][1]);
  pPush[8] = LODWORD(pMatrix->m[3][1]);
  pPush[9] = LODWORD(pMatrix->m[0][2]);
  pPush[10] = LODWORD(pMatrix->m[1][2]);
  pPush[11] = LODWORD(pMatrix->m[2][2]);
  pPush[12] = LODWORD(pMatrix->m[3][2]);
  pPush[13] = LODWORD(pMatrix->m[0][3]);
  pPush[14] = LODWORD(pMatrix->m[1][3]);
  pPush[15] = LODWORD(pMatrix->m[2][3]);
  pPush[16] = LODWORD(pMatrix->m[3][3]);
}