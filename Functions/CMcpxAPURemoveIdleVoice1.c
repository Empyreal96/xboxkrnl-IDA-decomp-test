void __thiscall CMcpxAPU::RemoveIdleVoice(CMcpxAPU *this, CMcpxVoiceClient *pVoice)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-38h]
  void *dwCVL; // [esp+4h] [ebp-34h]
  unsigned int dwCVLa; // [esp+4h] [ebp-34h]
  unsigned int dwPrevVoice; // [esp+8h] [ebp-30h]
  unsigned int dwRegister; // [esp+10h] [ebp-28h]
  unsigned int dwTVL; // [esp+14h] [ebp-24h]
  unsigned int dwVoiceList; // [esp+18h] [ebp-20h]
  int fFixNVL; // [esp+1Ch] [ebp-1Ch]
  void *dwNVL; // [esp+20h] [ebp-18h]
  unsigned int dwNVLa; // [esp+20h] [ebp-18h]
  unsigned int dwNVLb; // [esp+20h] [ebp-18h]
  unsigned int i; // [esp+24h] [ebp-14h]
  unsigned int dwNextVoice; // [esp+28h] [ebp-10h]
  CMcpxVoiceClient *pPrev; // [esp+2Ch] [ebp-Ch]
  int fFixCVL; // [esp+30h] [ebp-8h]
  CMcpxVoiceClient *pNext; // [esp+34h] [ebp-4h]

  thisa = this;
  dwVoiceList = (unsigned __int8)pVoice->m_bVoiceList;
  dwTVL = *(_DWORD *)(ListRegisters[dwVoiceList].TVL - 25165824);
  dwCVL = *(void **)(dword_800EE388[3 * dwVoiceList] - 25165824);
  dwNVL = *(void **)(dword_800EE38C[3 * dwVoiceList] - 25165824);
  if ( &this->m_alstActiveVoices[dwVoiceList] == pVoice->m_leActiveVoice.Blink )
  {
    pPrev = 0;
    dwPrevVoice = 0xFFFF;
  }
  else
  {
    pPrev = (CMcpxVoiceClient *)&pVoice->m_leActiveVoice.Blink[-24].Blink;
    dwPrevVoice = *((_DWORD *)&pPrev->m_pMcpxApu + CMcpxVoiceClient::GetHwVoiceCount(pPrev));
  }
  if ( &thisa->m_alstActiveVoices[dwVoiceList] == pVoice->m_leActiveVoice.Flink )
  {
    pNext = 0;
    dwNextVoice = 0xFFFF;
  }
  else
  {
    pNext = (CMcpxVoiceClient *)&pVoice->m_leActiveVoice.Flink[-24].Blink;
    dwNextVoice = (unsigned int)pNext->m_ahVoices[0];
  }
  if ( pPrev )
  {
    *((_DWORD *)thisa->m_ctxMemory[3].VirtualAddress + 32 * dwPrevVoice + 31) = dwNextVoice | *((_DWORD *)thisa->m_ctxMemory[3].VirtualAddress
                                                                                              + 32 * dwPrevVoice
                                                                                              + 31) & 0xFFFF0000;
  }
  else
  {
    dwTVL = dwNextVoice;
    *(_DWORD *)(ListRegisters[dwVoiceList].TVL - 25165824) = dwNextVoice;
  }
  i = 0;
  fFixCVL = 0;
  fFixNVL = 0;
  while ( i < CMcpxVoiceClient::GetHwVoiceCount(pVoice) )
  {
    if ( dwCVL == pVoice->m_ahVoices[i] )
      fFixCVL = 1;
    if ( dwNVL == pVoice->m_ahVoices[i] )
      fFixNVL = 1;
    *((_DWORD *)thisa->m_ctxMemory[3].VirtualAddress + 32 * (_DWORD)pVoice->m_ahVoices[i] + 31) = LOWORD(pVoice->m_ahVoices[i]) | *((_DWORD *)thisa->m_ctxMemory[3].VirtualAddress + 32 * (_DWORD)pVoice->m_ahVoices[i] + 31) & 0xFFFF0000;
    ++i;
  }
  if ( fFixCVL )
  {
    if ( pNext )
    {
      dwCVLa = dwNextVoice;
      dwRegister = (unsigned __int16)*((_DWORD *)thisa->m_ctxMemory[3].VirtualAddress + 32 * dwNextVoice + 31);
      if ( (unsigned __int16)dwRegister == 0xFFFF )
        dwRegister = dwTVL;
      dwNVLa = dwRegister;
    }
    else
    {
      dwCVLa = 0xFFFF;
      dwNVLa = dwTVL;
    }
    *(_DWORD *)(dword_800EE388[3 * dwVoiceList] - 25165824) = dwCVLa;
    *(_DWORD *)(dword_800EE38C[3 * dwVoiceList] - 25165824) = dwNVLa;
  }
  else if ( fFixNVL )
  {
    if ( pNext )
      dwNVLb = dwNextVoice;
    else
      dwNVLb = dwTVL;
    *(_DWORD *)(dword_800EE38C[3 * dwVoiceList] - 25165824) = dwNVLb;
  }
  RemoveEntryList(&pVoice->m_leActiveVoice);
  pVoice->m_bVoiceList = -1;
  if ( pVoice->m_dwStatus & 0x10000000 )
    pVoice->m_dwStatus &= 0xEFFFFFFF;
  else
    InsertTailList(&thisa->m_lstPendingInactiveVoices, &pVoice->m_lePendingInactiveVoice);
}