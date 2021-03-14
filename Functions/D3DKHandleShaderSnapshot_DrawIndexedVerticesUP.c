// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::HandleShaderSnapshot_DrawIndexedVerticesUP(_D3DPRIMITIVETYPE PrimitiveType, unsigned int VertexCount, const void *pIndexData, const void *pVertexStreamZeroData, unsigned int VertexStreamZeroStride)
{
  D3DK::g_snapshot.VertexCount = VertexCount;
  D3DK::g_snapshot.PrimitiveType = PrimitiveType;
  D3DK::g_snapshot.VertexStreamZeroStride = VertexStreamZeroStride;
  D3DK::g_snapshot.DrawVertType = 2;
  D3DK::g_snapshot.pIndexData = pIndexData;
  D3DK::g_snapshot.pVertexStreamZeroData = pVertexStreamZeroData;
  D3DK::DebugSnapshot::HandleDrawVertices(&D3DK::g_snapshot);
}