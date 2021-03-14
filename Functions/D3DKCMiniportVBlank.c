unsigned int __fastcall D3DK::CMiniport::VBlank(D3DK::CMiniport *this, int a2)
{
  D3DK::CMiniport *v2; // esi
  int v3; // ecx
  _DWORD *v4; // edi
  char v5; // bl
  unsigned int v6; // eax
  int v7; // ebx
  void (__cdecl *v8)(unsigned int); // eax
  char crtcIndex; // [esp+Fh] [ebp-1h]

  v2 = this;
  v3 = this->m_VBlankFlipNext;
  v4 = v2->m_RegisterBase;
  v5 = *((_BYTE *)v2->m_RegisterBase + 6296532);
  v6 = v2->m_VBlankCount + 1;
  v2->m_VBlankCount = v6;
  crtcIndex = v5;
  if ( v2->m_VBlankFlips[v3].Pending == 1 )
  {
    if ( v2->m_PresentationInterval != 2 || (LOWORD(a2) = -32576, LOBYTE(v6) = __inbyte(0x80C0u), ~(v6 >> 5) & 1) )
    {
      D3DK::CMiniport::DacProgramVideoStart(v2, v2->m_VBlankFlips[v3].Offset);
      v2->m_VBlankFlips[v2->m_VBlankFlipNext].Pending = 0;
      v7 = v2->m_VBlankFlipCount & 1;
      if ( v2->m_GammaUpdated[v7] == 1 )
      {
        D3DK::CMiniport::DacProgramGammaRamp(v2, &v2->m_GammaRamp[v7]);
        v2->m_GammaUpdated[v7] = 0;
      }
      v4[1049031] |= 2u;
      v3 = v2->m_VBlankFlipNext + 1;
      v2->m_VBlankFlipNext = v3;
      if ( v3 == 5 )
        v2->m_VBlankFlipNext = 0;
      v5 = crtcIndex;
      a2 = v2->m_VBlankFlipCount + 1;
      v2->m_VBlankFlipCount = a2;
    }
  }
  do
    v4[1572928] = 1;
  while ( v4[64] & 0x1000000 );
  KeSetEvent(v3, a2, &v2->m_VerticalBlankEvent, 1, 0);
  v8 = v2->m_pVerticalBlankCallback;
  if ( v8 )
    v8(v2->m_VBlankCount);
  *((_BYTE *)v4 + 6296532) = v5;
  return 0;
}