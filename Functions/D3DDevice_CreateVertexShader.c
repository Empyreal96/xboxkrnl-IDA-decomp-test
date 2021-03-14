// write access to const memory has been detected, the output may be wrong!
int __stdcall D3DDevice_CreateVertexShader(const unsigned int *pDeclaration, const unsigned int *pFunction, unsigned int *pHandle, unsigned int Usage)
{
  unsigned int v4; // ebx
  unsigned int v5; // edi
  int *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // ebx
  D3DK::VertexShader *v9; // esi
  unsigned int *v11; // eax
  signed int v12; // ecx
  signed int v13; // edi
  int v14; // edi
  unsigned int v15; // ebx
  unsigned int programAndConstantsSize; // [esp+10h] [ebp-10h]
  unsigned int shaderType; // [esp+14h] [ebp-Ch]
  int programSize; // [esp+18h] [ebp-8h]
  unsigned int shaderLength; // [esp+1Ch] [ebp-4h]

  ++D3DK::g_PerfCounters.m_APICounters[34];
  if ( pFunction )
  {
    v4 = *(unsigned __int16 *)pFunction;
    v5 = *((unsigned __int16 *)pFunction + 1);
    shaderType = *(unsigned __int16 *)pFunction;
    shaderLength = *((unsigned __int16 *)pFunction + 1);
  }
  else
  {
    v4 = shaderType;
    v5 = shaderLength;
  }
  if ( Usage & 0xFFFFC3FF )
    D3DK::DXGRIP((int *)v5, "Invalid usage flag");
  if ( !pFunction )
    goto LABEL_46;
  if ( v4 != 8312 && v4 != 30584 && v4 != 29560 || !v5 || v5 > 0x88 )
  {
    D3DK::DXGRIP((int *)v5, "Invalid function header.  Only valid Xbox-assembled function declarations are accepted.");
    D3DK::DXGRIP(
      (int *)v5,
      "(Perhaps you're calling with a DX8-defined token stream?  Use Xgraphics assembler to compile into Xbox form.)");
  }
  if ( v4 != 29560 )
  {
LABEL_46:
    v6 = (int *)pDeclaration;
LABEL_17:
    if ( v6 )
      goto LABEL_21;
    goto LABEL_18;
  }
  v6 = (int *)pDeclaration;
  if ( pDeclaration )
  {
    D3DK::DXGRIP((int *)pDeclaration, "State shaders must pass a NULL declaration pointer");
    goto LABEL_17;
  }
LABEL_18:
  if ( !pFunction || v4 != 29560 )
    D3DK::DXGRIP(v6, "Declaration pointer can be NULL only for state shaders");
LABEL_21:
  programSize = 0;
  if ( pFunction )
    programSize = 16 * shaderLength + 4 * ((16 * shaderLength + 127) >> 7);
  v7 = 0;
  if ( v6 )
    v7 = 4 * D3DK::ParseDeclarationConstants((const unsigned int *)v6, 0);
  v8 = v7 + programSize;
  programAndConstantsSize = v7 + programSize;
  v9 = (D3DK::VertexShader *)D3DK::MemAlloc(v7 + programSize + 368, programSize, (int)pFunction, v7 + programSize + 368);
  if ( !v9 )
    return -2147024882;
  memset(v9, 0, sizeof(D3DK::VertexShader));
  v9->Signature = 1450403940;
  v9->RefCount = 1;
  if ( Usage & 0xFFFFC3FF )
    D3DK::DXGRIP(
      (int *)&v9[1],
      "Assertion failure: %s",
      "(Usage & ~(D3DUSAGE_PERSISTENTDIFFUSE | D3DUSAGE_PERSISTENTSPECULAR | D3DUSAGE_PERSISTENTBACKDIFFUSE | D3DUSAGE_PE"
      "RSISTENTBACKSPECULAR)) == 0");
  v9->Flags = Usage;
  v11 = &v9->Slot[0].SizeAndType;
  v12 = 20;
  do
  {
    *v11 = 2;
    v11 += 4;
    --v12;
  }
  while ( v12 );
  if ( pDeclaration )
    D3DK::ParseDeclarationStream(v9, pDeclaration, pFunction == 0);
  v13 = 0;
  if ( pFunction )
  {
    v14 = v9->Flags | 4;
    v9->Flags = v14;
    if ( shaderType != 8312 )
      v9->Flags = v14 | 1;
    if ( shaderType == 29560 )
      v9->Flags |= 8u;
    v9->ProgramSize = shaderLength;
    v13 = D3DK::ParseProgram(v9->ProgramAndConstants, pFunction + 1, 4 * shaderLength) - v9->ProgramAndConstants;
    if ( programSize != 4 * v13 )
      D3DK::DXGRIP((int *)v13, "Assertion failure: %s", "programSize == 4 * functionDwords");
    v8 = programAndConstantsSize;
  }
  if ( pDeclaration )
    D3DK::ParseDeclarationConstants(pDeclaration, &v9->ProgramAndConstants[v13]);
  v15 = v8 >> 2;
  v9->ProgramAndConstantsDwords = v15;
  v9->ProgramAndConstants[v15] = 0;
  *pHandle = (unsigned int)v9 | 1;
  return 0;
}