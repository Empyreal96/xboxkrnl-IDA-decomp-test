// write access to const memory has been detected, the output may be wrong!
unsigned int __usercall D3DK::CMiniport::ServiceGrInterrupt@<eax>(D3DK::CMiniport *this@<ecx>, int *a2@<edi>)
{
  _DWORD *v2; // esi
  unsigned int v3; // edx
  int v4; // ebx
  int v5; // eax
  void *v6; // edx
  int *v7; // edi
  unsigned int v8; // ecx
  int ChID; // [esp+Ch] [ebp-14h]
  int Class; // [esp+10h] [ebp-10h]
  int Offset; // [esp+14h] [ebp-Ch]
  D3DK::CMiniport *v13; // [esp+18h] [ebp-8h]
  unsigned int intr; // [esp+1Ch] [ebp-4h]
  unsigned int intra; // [esp+1Ch] [ebp-4h]

  v13 = this;
  v2 = this->m_RegisterBase;
  v2[1049032] = 0;
  v3 = v2[1048640];
  v4 = v2[1048642];
  v5 = (v2[1049025] >> 20) & 0x1F;
  intr = v2[1048640];
  ChID = (v2[1049025] >> 20) & 0x1F;
  Offset = v2[1049025] & 0x1FFC;
  if ( v3 & 0x1000 )
  {
    v2[1048640] = 4096;
    v6 = this->m_RegisterBase;
    do
      a2 = (int *)*((_DWORD *)v6 + 1049024);
    while ( a2 );
    D3DK::CMiniport::HalGrLoadChannelContext(this, (int)v6, 0, v5);
    v3 = intr;
  }
  if ( v3 & 0x10 )
  {
    D3DK::DXGRIP(a2, "Graphics engine software method");
    v3 = intr;
    v2[1048640] = 16;
  }
  v7 = (int *)(v3 & 1);
  if ( (v3 & 1 || v3 & 0x100000) && v4 & 0x40 )
  {
    D3DK::DXGRIP(v7, "Graphics engine software method-2");
    v7 = (int *)(v7 != 0 ? 1 : 0x100000);
    v2[1048640] = v7;
  }
  v8 = v2[1048640];
  intra = v2[1048640];
  if ( v8 )
  {
    v2[1048640] = v8;
    if ( v8 != 4096 && v8 != 0x1000000 )
    {
      if ( v8 & 0x10 )
      {
        while ( *((_DWORD *)v13->m_RegisterBase + 1049024) )
          ;
        D3DK::DXGRIP(v7, "MP: Missing hardware object");
        v8 = intra;
      }
      if ( v4 && (v8 & 1 || v8 & 0x100000) )
      {
        v7 = (int *)v2[1049026];
        Class = v2[1048659] & 0xFF;
        if ( !(v4 & 0x40) )
        {
          if ( Offset == 256 )
          {
            D3DK::CMiniport::SoftwareMethod(v13, v7, (unsigned int)v7, v2[1050274]);
          }
          else
          {
            if ( v4 & 2 )
              D3DK::WARNING(v7, "MP: Graphics invalid data error!");
            if ( v4 & 4 )
              D3DK::WARNING(v7, "MP: Graphics surface protection error!");
            if ( v4 & 8 )
              D3DK::WARNING(v7, "MP: Graphics range exception error!");
            if ( v4 & 0x10 )
              D3DK::WARNING(v7, "MP: Graphics color buffer limit error!");
            if ( v4 & 0x20 )
              D3DK::WARNING(v7, "MP: Graphics zeta buffer limit error!");
            if ( (v4 & 0x80u) != 0 )
              D3DK::WARNING(v7, "MP: Graphics dma read protection error!");
            if ( v4 & 0x100 )
              D3DK::WARNING(v7, "MP: Graphics dma write protection error!");
            if ( v4 & 0x200 )
              D3DK::WARNING(v7, "MP: Graphics format exception error!");
            if ( v4 & 0x400 )
              D3DK::WARNING(v7, "MP: Graphics patch exception error!");
            if ( v4 & 0x800 )
              D3DK::WARNING(v7, "MP: Graphics object state invalid error!");
            if ( v4 & 0x1000 )
              D3DK::WARNING(v7, "MP: Graphics double notify error!");
            if ( v4 & 0x2000 )
              D3DK::WARNING(v7, "MP: Graphics notify in use error!");
            if ( v4 & 0x4000 )
              D3DK::WARNING(v7, "MP: Graphics method count error!");
            if ( (v4 & 0x8000) != 0 )
              D3DK::WARNING(v7, "MP: Graphics buffer notification error!");
            if ( v4 & 0x10000 )
              D3DK::WARNING(v7, "MP: Graphics DMA vertex protection error!");
            if ( v4 & 0x20000 )
              D3DK::WARNING(v7, "MP: Graphics index inline reuse error!");
            if ( v4 & 0x40000 )
              D3DK::WARNING(v7, "MP: Graphics invalid operation error!");
            if ( v4 & 0x80000 )
              D3DK::WARNING(v7, "MP: Graphics FD invalid operation error!");
            if ( v4 & 0x400000 )
              D3DK::WARNING(v7, "MP: Graphics texture A protection error!");
            if ( v4 & 0x800000 )
              D3DK::WARNING(v7, "MP: Graphics texture B protection error!");
            DbgPrint(
              v7,
              "MP: GRAPHICS HARDWARE ERROR\n"
              "MP: Source: %08x\n"
              "MP:   ChID: %d\n"
              "MP:  Class: %x\n"
              "MP: Offset: %08x\n"
              "MP:   Data: %08x\n",
              v4,
              ChID,
              Class,
              Offset,
              v7);
            if ( !D3D__SingleStepPusher )
              D3DK::WARNING(
                v7,
                "\n"
                "(The graphics chip detected a command error.  The offending command\n"
                "may have been written to the push-buffer several API calls ago.  Re-\n"
                "run with the global variable 'D3D__SingleStepPusher' set to 1 to die\n"
                "immediately after the offending API call.)\n");
            D3DK::g_DpcRIPFired = 1;
            __debugbreak();
          }
          v8 = intra;
        }
      }
      if ( v8 & 0x10000 )
      {
        while ( *((_DWORD *)v13->m_RegisterBase + 1049024) )
          ;
        D3DK::WARNING(v7, "MP: Software assisted buffer notification");
        BYTE1(v8) = BYTE1(intra);
      }
      if ( v8 & 0x100 )
      {
        D3DK::WARNING(v7, "MP: Graphics DMA TLB not present or valid (A)");
        BYTE1(v8) = BYTE1(intra);
      }
      if ( v8 & 0x200 )
        D3DK::WARNING(v7, "MP: Graphics DMA TLB not present or valid (B)");
    }
  }
  v2[1049032] = 1;
  return v2[1048640];
}