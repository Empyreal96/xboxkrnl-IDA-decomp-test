void __userpurge D3DK::CMiniport::HalGrLoadChannelContext(D3DK::CMiniport *this@<ecx>, int a2@<edx>, int *a3@<edi>, unsigned int ChID)
{
  D3DK::CMiniport *v4; // ebx
  _DWORD *v5; // esi
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // edi
  int v9; // et1
  signed int v10; // eax
  int v11; // edi
  unsigned int misc; // [esp+Ch] [ebp-4h]

  v4 = this;
  v5 = this->m_RegisterBase;
  if ( *((_DWORD *)this->m_RegisterBase + 1048640) )
    D3DK::CMiniport::ServiceGrInterrupt(this, a3);
  misc = v5[1049032];
  v5[1049032] = 0;
  D3DK::CMiniport::HalGrIdle(v4, a2);
  v6 = ChID;
  if ( v4->m_HalInfo.GrChID != ChID )
  {
    D3DK::CMiniport::HalGrUnloadChannelContext(v4, v4->m_HalInfo.GrChID);
    v6 = ChID;
  }
  v4->m_HalInfo.GrChID = v6;
  if ( v6 == 2 )
  {
    v5[1048657] = 268435712;
    v5[1049049] = 0x8000000;
    v5[1049032] = misc | 1;
  }
  else
  {
    if ( v4->m_HalInfo.GrCurrentObjects3d[v6] )
    {
      v7 = v5 + 1048608;
      *v7 = 458752;
      v8 = v5[1048608];
      *v7 = 0;
      v9 = v5[1048608];
      v5[1049044] = 3997696;
      v10 = 15;
      do
      {
        --v10;
        v5[1049045] = 0;
      }
      while ( v10 );
    }
    v5[1048609] |= 0x1000000u;
    v11 = (v6 & 0x1F) << 24;
    v5[1048658] = v11;
    v5[1049057] = v4->m_HalInfo.GrCtxTable[ChID] & 0xFFFF;
    v5[1049058] = 1;
    D3DK::CMiniport::HalGrIdle(v4, v6);
    v5[1048658] = v11 | v5[1048658] & 0xE0FFFFFF;
    v5[1048657] = 268501248;
    v5[1049049] &= 0xCFFFFFFF;
  }
}