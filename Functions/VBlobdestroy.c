void __usercall VBlob::destroy(VBlob *this@<ecx>, int *a2@<edi>)
{
  VBlob *v2; // esi

  v2 = this;
  D3DResource_Release(a2, (D3DResource *)&this->m_pBlobletVB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->m_pBlobletIB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->m_pBlobVBConst->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->m_pBlobVBChangingR->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->m_pBlobVBChangingU->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->m_pBlobIB->Common);
  MemFree(v2->m_pUnitSphereNormals);
  D3DResource_Release(a2, (D3DResource *)&v2->pHaloQuadVB->Common);
  if ( v2->m_dwPShaderBlob )
    D3DDevice_DeletePixelShader(v2->m_dwPShaderBlob);
  if ( v2->m_dwPShaderBloblet )
    D3DDevice_DeletePixelShader(v2->m_dwPShaderBloblet);
  if ( v2->m_dwVShaderBlob )
    D3DDevice_DeleteVertexShader(v2->m_dwVShaderBlob);
  if ( v2->m_dwVShaderBloblet )
    D3DDevice_DeleteVertexShader(v2->m_dwVShaderBloblet);
  v2->m_pBlobletVB = 0;
  v2->m_pBlobletIB = 0;
  v2->m_pBlobVBConst = 0;
  v2->m_pBlobVBChangingR = 0;
  v2->m_pBlobVBChangingU = 0;
  v2->m_pBlobIB = 0;
  v2->m_pUnitSphereNormals = 0;
}