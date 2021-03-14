// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::HandleShaderSnapshot_DrawIndexedVertices(_D3DPRIMITIVETYPE PrimitiveType, unsigned int VertexCount, const unsigned __int16 *pIndexData)
{
  D3DK::g_snapshot.VertexCount = VertexCount;
  D3DK::g_snapshot.DrawVertType = 4;
  D3DK::g_snapshot.PrimitiveType = PrimitiveType;
  D3DK::g_snapshot.pIndexData = pIndexData;
  D3DK::DebugSnapshot::HandleDrawVertices(&D3DK::g_snapshot);
}