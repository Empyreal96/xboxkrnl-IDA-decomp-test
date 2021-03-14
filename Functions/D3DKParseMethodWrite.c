// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::ParseMethodWrite(int *a1@<edi>, unsigned int Method, unsigned int *pPush, unsigned int Count)
{
  unsigned int *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax
  int *v8; // edi
  unsigned int v9; // eax
  int *v10; // edi

  if ( Method & 3 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "(Method & 3) == 0");
  v4 = pPush;
  v5 = pPush[Count - 1];
  v6 = Method >> 2;
  D3DK::g_Modified[v6] = 1;
  D3DK::g_ParseState[v6] = v5;
  switch ( Method )
  {
    case 0x100u:
      if ( *pPush == 776 || *pPush == 780 )
        D3DK::g_IgnorePushBufferJump = 1;
      return;
    case 0x1E9Cu:
      if ( D3DK::g_TransformProgramLoad & 3 )
        D3DK::DXGRIP((int *)v5, "Assertion failure: %s", "(g_TransformProgramLoad & 3) == 0");
      D3DK::g_TransformProgramLoad = 4 * v5;
      return;
    case 0x1EA4u:
      if ( D3DK::g_TransformConstantLoad & 3 )
        D3DK::DXGRIP((int *)v5, "Assertion failure: %s", "(g_TransformConstantLoad & 3) == 0");
      D3DK::g_TransformConstantLoad = 4 * v5;
      return;
  }
  if ( Method < 0xB00 )
  {
    if ( Method < 0xB80 )
      return;
  }
  else if ( Method < 0xB80 )
  {
    if ( Count )
    {
      v7 = D3DK::g_TransformProgramLoad;
      v8 = (int *)Count;
      do
      {
        *(_DWORD *)(4 * v7++ - 2146682360) = *v4;
        ++v4;
        D3DK::g_TransformProgramLoad = v7;
        if ( v7 > 0x220 )
        {
          D3DK::DXGRIP(v8, "Assertion failure: %s", "g_TransformProgramLoad <= sizeof(g_TransformProgram) / 4");
          v7 = D3DK::g_TransformProgramLoad;
        }
        v8 = (int *)((char *)v8 - 1);
      }
      while ( v8 );
    }
    return;
  }
  if ( Method < 0xC00 && Count )
  {
    v9 = D3DK::g_TransformConstantLoad;
    v10 = (int *)Count;
    do
    {
      *(_DWORD *)(4 * v9++ - 2146685440) = *v4;
      ++v4;
      D3DK::g_TransformConstantLoad = v9;
      if ( v9 > 0x300 )
      {
        D3DK::DXGRIP(v10, "Assertion failure: %s", "g_TransformConstantLoad <= sizeof(g_TransformConstant) / 4");
        v9 = D3DK::g_TransformConstantLoad;
      }
      v10 = (int *)((char *)v10 - 1);
    }
    while ( v10 );
  }
}