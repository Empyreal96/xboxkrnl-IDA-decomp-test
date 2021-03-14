// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::CMiniport::SoftwareMethod(D3DK::CMiniport *this@<ecx>, int *a2@<edi>, unsigned int Method, unsigned int Data)
{
  _DWORD *v4; // esi
  D3DK::CMiniport *v5; // ecx
  unsigned int v6; // esi
  unsigned int *v7; // eax
  D3DK::CMiniport::PUSHBUFFERFIXUPINFO PushBufferFixupInfo; // [esp+4h] [ebp-14h]
  D3DK::CMiniport *v9; // [esp+14h] [ebp-4h]

  v9 = this;
  v4 = this->m_RegisterBase;
  switch ( Method )
  {
    case 0x300u:
      if ( Data & 3 )
      {
        D3DK::DXGRIP(a2, "Assertion failure: %s", "(Data & 3) == 0");
        this = v9;
      }
      D3DK::CMiniport::DacProgramVideoStart(this, Data);
      v4[1049031] |= 2u;
      v5 = v9;
      v6 = v9->m_VBlankFlipCount & 1;
      if ( v9->m_GammaUpdated[v6] == 1 )
      {
        D3DK::CMiniport::DacProgramGammaRamp(v9, &v9->m_GammaRamp[v6]);
        v9->m_GammaUpdated[v6] = 0;
        v5 = v9;
      }
      ++v5->m_VBlankFlipCount;
      break;
    case 0x304u:
      if ( this->m_VBlankFlips[this->m_VBlankQueueNext].Pending )
      {
        D3DK::DXGRIP(a2, "Assertion failure: %s", "m_VBlankFlips[m_VBlankQueueNext].Pending == FALSE");
        this = v9;
      }
      this->m_VBlankFlips[this->m_VBlankQueueNext].Pending = 1;
      v9->m_VBlankFlips[v9->m_VBlankQueueNext++].Offset = Data;
      if ( v9->m_VBlankQueueNext == 5 )
        v9->m_VBlankQueueNext = 0;
      break;
    case 0x308u:
    case 0x30Cu:
      PushBufferFixupInfo.pFixup = *(unsigned int **)Data;
      PushBufferFixupInfo.pStart = *(char **)(Data + 4);
      v7 = *(unsigned int **)(Data + 12);
      PushBufferFixupInfo.ReturnOffset = *(_DWORD *)(Data + 8);
      PushBufferFixupInfo.ReturnAddress = v7;
      D3DK::CMiniport::FixupPushBuffer(this, a2, &PushBufferFixupInfo, Method);
      D3DK::FlushWCCache();
      break;
    case 0x310u:
      KeSetEvent((int)&this->m_BusyBlockEvent, Method, &this->m_BusyBlockEvent, 1, 0);
      break;
    case 0x314u:
      goto $L37450;
    case 0x318u:
      if ( v4[1049024] )
        D3DK::DXGRIP(a2, "Assertion failure: %s", "!REG_RD32(m_RegisterBase, NV_PGRAPH_STATUS)");
$L37450:
      ((void (__cdecl *)(_DWORD))Data)(v4[1050139]);
      break;
    case 0x31Cu:
      if ( v4[1049024] )
        D3DK::DXGRIP(a2, "Assertion failure: %s", "!REG_RD32(m_RegisterBase, NV_PGRAPH_STATUS)");
      v4[1049044] = 14680144;
      v4[1049045] = Data;
      v4[1049044] = 14614536;
      v4[1049045] = Data;
      break;
    case 0x320u:
      if ( v4[1049024] )
        D3DK::DXGRIP(a2, "Assertion failure: %s", "!REG_RD32(m_RegisterBase, NV_PGRAPH_STATUS)");
      *(_DWORD *)((char *)v4 + Data) = v4[1050139];
      break;
    default:
      DbgPrint(a2, "MP: Unhandled SoftwareMethod: 0x%08lx Data: 0x%08lx\n", Method, Data);
      DbgPrint(a2, "SW PUT=%x\n", D3DK::g_pDevice->m_Pusher.m_pPut);
      DbgPrint(a2, "HW PUT=%x\n", MEMORY[0xFD003240]);
      DbgPrint(a2, "HW GET=%x\n", MEMORY[0xFD003244]);
      D3DK::g_DpcRIPFired = 1;
      __debugbreak();
      break;
  }
}