// write access to const memory has been detected, the output may be wrong!
void __fastcall D3DK::CMiniport::Dpc(int a1, int a2, _KDPC *Dpc, void *DpcContext, void *Arg1, void *Arg2)
{
  D3DK::CMiniport *v6; // ecx
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // eax

  v6 = (D3DK::CMiniport *)DpcContext;
  v7 = *(_DWORD *)DpcContext;
  do
  {
    v8 = *(_DWORD *)(v7 + 256);
    v9 = 0;
    if ( v8 & 0x100000 )
    {
      *(_DWORD *)(v7 + 37120) = 1;
      v9 = *(_DWORD *)(v7 + 37120);
    }
    if ( v8 & 0x1000000 )
    {
      v10 = D3DK::CMiniport::VBlank(v6, a2);
      v6 = (D3DK::CMiniport *)DpcContext;
      v9 |= v10;
    }
    if ( v8 & 0x1000 )
    {
      v11 = D3DK::CMiniport::ServiceGrInterrupt(v6, (int *)v7);
      v6 = (D3DK::CMiniport *)DpcContext;
      v9 |= v11;
    }
    if ( v8 & 0x10 )
    {
      D3DK::DXGRIP((int *)v7, "MP: Unhandled ServiceMediaPortInterrupt");
      v6 = (D3DK::CMiniport *)DpcContext;
      D3DK::g_DpcRIPFired = 1;
    }
    if ( v8 & 0x100 || *(_BYTE *)(v7 + 8320) & 1 )
    {
      v12 = D3DK::CMiniport::ServiceFifoInterrupt(v6, a2);
      v6 = (D3DK::CMiniport *)DpcContext;
      v9 |= v12;
    }
    if ( v8 & 0x10000 && *((_BYTE *)v6->m_RegisterBase + 33024) & 1 )
      *((_DWORD *)v6->m_RegisterBase + 8256) = 1;
  }
  while ( v9 );
  *((_DWORD *)v6->m_RegisterBase + 80) = v6->m_GenInfo.ChipIntrEn0;
}