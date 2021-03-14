// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::HandleShaderSnapshot_DrawVertices(_D3DPRIMITIVETYPE PrimitiveType, unsigned int StartVertex, unsigned int VertexCount)
{
  D3DK::g_snapshot.StartVertex = StartVertex;
  D3DK::g_snapshot.DrawVertType = 3;
  D3DK::g_snapshot.PrimitiveType = PrimitiveType;
  D3DK::g_snapshot.VertexCount = VertexCount;
  D3DK::DebugSnapshot::HandleDrawVertices(&D3DK::g_snapshot);
}