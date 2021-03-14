void __stdcall D3DK::ShadowVertexShaderState(D3DK::VertexShader *pVertexShader, unsigned int Address)
{
  D3DK::VertexShader *v2; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  int *v5; // edi
  unsigned int v6; // ebx
  int v7; // eax
  D3DK::VertexShader *v8; // ebx
  float *pConstants; // [esp+14h] [ebp-Ch]
  unsigned int *pSlots; // [esp+1Ch] [ebp-4h]
  unsigned int *pProgramAndConstants; // [esp+2Ch] [ebp+Ch]

  v2 = (D3DK::VertexShader *)((char *)pVertexShader + 364);
  pSlots = (unsigned int *)((char *)D3DK::g_pDevice + 16 * (Address + 396));
  while ( 1 )
  {
    v3 = v2->Signature;
    v4 = v2->Signature;
    v5 = (int *)&v2->RefCount;
    v6 = v4 >> 18;
    if ( !v6 )
    {
      D3DK::DXGRIP(v5, "Assertion failure: %s", "count != 0");
LABEL_5:
      if ( (unsigned __int16)v3 == 2816 )
      {
        if ( v6 & 3 || !v6 || v6 >= 0x220 )
          D3DK::DXGRIP(
            v5,
            "Assertion failure: %s",
            "((count & 3) == 0) && (count != 0) && (count < VSHADER_PROGRAM_SLOTS*4)");
        if ( &pSlots[v6] > &D3DK::g_pDevice->m_ConstantMode )
          D3DK::DXGRIP(
            v5,
            "Assertion failure: %s",
            "pSlots + count <= &pDevice->m_VertexShaderProgramSlots[VSHADER_PROGRAM_SLOTS][0]");
        qmemcpy(pSlots, v5, 4 * (4 * v6 >> 2));
        pSlots += v6;
      }
      else
      {
        if ( v6 & 3 || v6 >= 0x220 )
          D3DK::DXGRIP(v5, "Assertion failure: %s", "((count & 3) == 0) && (count < VSHADER_PROGRAM_SLOTS*4)");
        if ( &pConstants[v6] > (float *)D3DK::g_pDevice->m_VertexShaderProgramSlots )
          D3DK::DXGRIP(
            v5,
            "Assertion failure: %s",
            "pConstants + count <= &pDevice->m_VertexShaderConstants[VSHADER_CONSTANT_NUM][0]");
        if ( (unsigned __int16)v3 != 2944 )
          D3DK::DXGRIP(
            v5,
            "Assertion failure: %s",
            "(methodEncode & 0xffff) == PUSHER_METHOD(SUBCH_3D, NV097_SET_TRANSFORM_CONSTANT(0), 0)");
        qmemcpy(pConstants, v5, 4 * (4 * v6 >> 2));
        pConstants += v6;
      }
      goto LABEL_27;
    }
    if ( v6 != 1 )
      goto LABEL_5;
    pProgramAndConstants = (unsigned int *)*v5;
    if ( (unsigned int)*v5 >= 0xC0 )
      D3DK::DXGRIP(v5, "Assertion failure: %s", "constantSlot < VSHADER_CONSTANT_NUM");
    if ( (unsigned __int16)v3 != 7844 )
      D3DK::DXGRIP(
        v5,
        "Assertion failure: %s",
        "(methodEncode & 0xffff) == PUSHER_METHOD(SUBCH_3D, NV097_SET_TRANSFORM_CONSTANT_LOAD, 0)");
    pConstants = (float *)((char *)D3DK::g_pDevice + 16 * (_DWORD)(pProgramAndConstants + 51));
LABEL_27:
    v7 = v5[v6];
    v8 = (D3DK::VertexShader *)&v5[v6];
    if ( !v7 )
      break;
    v2 = v8;
  }
  if ( v8 != (D3DK::VertexShader *)&pVertexShader->ProgramAndConstants[pVertexShader->ProgramAndConstantsDwords] )
    D3DK::DXGRIP(
      v5,
      "Assertion failure: %s",
      "pProgramAndConstants == &pVertexShader->ProgramAndConstants[ pVertexShader->ProgramAndConstantsDwords]");
}