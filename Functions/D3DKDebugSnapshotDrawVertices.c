int __thiscall D3DK::DebugSnapshot::DrawVertices(D3DK::DebugSnapshot *this)
{
  unsigned int v1; // edi
  int result; // eax

  v1 = D3DK::g_pDevice->m_dwSnapshot;
  D3DK::g_pDevice->m_dwSnapshot = 0;
  switch ( this->DrawVertType )
  {
    case 1u:
      D3DDevice_DrawVerticesUP(
        this->PrimitiveType,
        this->VertexCount,
        this->pVertexStreamZeroData,
        this->VertexStreamZeroStride);
      D3DK::g_pDevice->m_dwSnapshot = v1;
      result = 0;
      break;
    case 2u:
      D3DDevice_DrawIndexedVerticesUP(
        this->PrimitiveType,
        this->VertexCount,
        this->pIndexData,
        this->pVertexStreamZeroData,
        this->VertexStreamZeroStride);
      D3DK::g_pDevice->m_dwSnapshot = v1;
      result = 0;
      break;
    case 3u:
      D3DDevice_DrawVertices(this->PrimitiveType, this->StartVertex, this->VertexCount);
      D3DK::g_pDevice->m_dwSnapshot = v1;
      result = 0;
      break;
    case 4u:
      D3DDevice_DrawIndexedVertices(this->PrimitiveType, this->VertexCount, (const unsigned __int16 *)this->pIndexData);
      goto LABEL_6;
    default:
LABEL_6:
      D3DK::g_pDevice->m_dwSnapshot = v1;
      result = 0;
      break;
  }
  return result;
}