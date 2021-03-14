// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_ZBias(unsigned int Value)
{
  unsigned int v1; // edi
  BOOL v2; // esi
  double v3; // st7
  unsigned int v4; // ST10_4
  float bias; // [esp+14h] [ebp+8h]

  v1 = Value;
  ++D3DK::g_PerfCounters.m_APICounters[155];
  v2 = Value != 0;
  v3 = -(double)Value;
  bias = v3;
  *(float *)&v4 = v3 * 0.25;
  D3DDevice_SetRenderStateNotInline(D3DRS_POLYGONOFFSETZSLOPESCALE, v4);
  D3DDevice_SetRenderStateNotInline(D3DRS_POLYGONOFFSETZOFFSET, LODWORD(bias));
  D3DDevice_SetRenderStateNotInline(D3DRS_POINTOFFSETENABLE, v2);
  D3DDevice_SetRenderStateNotInline(D3DRS_WIREFRAMEOFFSETENABLE, v2);
  D3DDevice_SetRenderStateNotInline(D3DRS_SOLIDOFFSETENABLE, v2);
  dword_800C25CC = v1;
}