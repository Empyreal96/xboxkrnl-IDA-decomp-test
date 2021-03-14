void __thiscall D3DK::CMiniport::DacProgramVideoStart(D3DK::CMiniport *this, unsigned int startAddr)
{
  unsigned __int8 v2; // al
  unsigned int v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // eax

  v2 = __inbyte(0x80C0u);
  v3 = (v2 & 0x20u) >> 5;
  v4 = this->m_DisplayMode & 0xC0000000;
  if ( v4 == 0x40000000 )
    v3 = v3 == 0;
  if ( !this->m_FirstFlip )
  {
    v5 = this->m_CurrentAvInfo;
    if ( v5 & 0x1000000 )
    {
      if ( v4 == 2147483648 )
      {
LABEL_9:
        if ( v5 & 0x200000 && v3 )
        {
          v6 = this->m_SurfacePitch + startAddr;
          goto LABEL_13;
        }
LABEL_12:
        v6 = startAddr;
        goto LABEL_13;
      }
      if ( v3 )
      {
        v6 = startAddr - (this->m_SurfacePitch >> 1);
LABEL_13:
        *((_DWORD *)this->m_RegisterBase + 1573376) = v6;
        return;
      }
    }
    if ( v4 != 2147483648 )
      goto LABEL_12;
    goto LABEL_9;
  }
}