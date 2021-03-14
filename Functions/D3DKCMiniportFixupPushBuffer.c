// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::CMiniport::FixupPushBuffer(D3DK::CMiniport *this@<ecx>, int *a2@<edi>, D3DK::CMiniport::PUSHBUFFERFIXUPINFO *pPushBufferFixupInfo, unsigned int Method)
{
  D3DK::CMiniport::PUSHBUFFERFIXUPINFO *v4; // eax
  unsigned int *v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  char *v9; // ebx
  char *v10; // edi
  char *v11; // esi
  int v12; // ecx
  unsigned int *v13; // esi
  unsigned int v14; // edi
  int v15; // esi
  D3DK::CMiniport *v16; // [esp+0h] [ebp-10h]
  unsigned int Offset; // [esp+4h] [ebp-Ch]
  char *pPushBuffer; // [esp+8h] [ebp-8h]
  unsigned int Size; // [esp+Ch] [ebp-4h]

  v16 = this;
  if ( Method != 776 && Method != 780 )
    D3DK::DXGRIP(a2, "Assertion failure: %s", "(Method == NVX_PUSH_BUFFER_RUN) || (Method == NVX_PUSH_BUFFER_FIXUP)");
  v4 = pPushBufferFixupInfo;
  v5 = pPushBufferFixupInfo->pFixup;
  pPushBuffer = pPushBufferFixupInfo->pStart;
  if ( pPushBufferFixupInfo->pFixup )
  {
    v6 = *v5;
    v7 = 0;
    Size = *v5;
    if ( *v5 != -1 )
    {
      while ( 1 )
      {
        v8 = v5[1];
        Offset = v5[1];
        if ( v8 & 3 || v6 & 3 || v8 < v7 )
        {
          D3DK::DXGRIP(a2, "MP: Bad RunPushBuffer fix-up data (got overwritten?)");
          v6 = Size;
          v8 = Offset;
          D3DK::g_DpcRIPFired = 1;
        }
        v9 = (char *)(v5 + 2);
        qmemcpy(&pPushBuffer[v8], v9, 4 * (v6 >> 2));
        v11 = &v9[4 * (v6 >> 2)];
        v10 = &pPushBuffer[4 * (v6 >> 2) + v8];
        v12 = v6 & 3;
        v5 = (unsigned int *)&v9[v6];
        qmemcpy(v10, v11, v12);
        a2 = (int *)&v10[v12];
        Size = *v5;
        if ( *v5 == -1 )
          break;
        v6 = *v5;
        v7 = v8;
      }
      v4 = pPushBufferFixupInfo;
    }
  }
  v13 = v4->ReturnAddress;
  v14 = v4->ReturnOffset;
  if ( ((_DWORD)v4->ReturnAddress & 0xF0000000) != 0x80000000 )
    D3DK::DXGRIP((int *)v14, "AssertContiguous - the memory is not contiguous.");
  v15 = (unsigned int)v13 & 0xFFFFFFF;
  *(_DWORD *)&pPushBuffer[v14] = v15 + 1;
  if ( Method == 776 )
  {
    if ( v15 & 1 )
      D3DK::DXGRIP(
        (int *)v14,
        "Assertion failure: %s",
        "!(ReturnAddress & NV_PFIFO_CACHE1_DMA_SUBROUTINE_STATE_ACTIVE)");
    *((_DWORD *)v16->m_RegisterBase + 3219) = v15;
    v16->m_PusherGetRunSize += v14;
  }
}