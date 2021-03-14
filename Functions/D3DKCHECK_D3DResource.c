void __stdcall D3DK::CHECK(D3DResource *p, char *func)
{
  char v2; // cl
  unsigned int v3; // eax
  const unsigned int Alignments[7]; // [esp+8h] [ebp-1Ch]

  if ( !p )
    D3DK::DXGRIP((int *)func, "%s - Null THIS pointer.", func);
  v2 = BYTE2(p->Common);
  Alignments[0] = 4;
  Alignments[1] = 4;
  Alignments[2] = 4;
  Alignments[6] = 4;
  v3 = p->Data;
  Alignments[3] = 64;
  Alignments[4] = 128;
  Alignments[5] = 1;
  if ( v3 % Alignments[v2 & 7] )
    D3DK::DXGRIP((int *)func, "%s - Bad data alignment.", func);
}