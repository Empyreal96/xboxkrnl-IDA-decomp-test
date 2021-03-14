void __thiscall CList<CDirectSoundVoice>::RemoveNode(CList<CDirectSoundVoice> *this, CDirectSoundVoice *pNode)
{
  if ( pNode->pPrev )
    pNode->pPrev->pNext = pNode->pNext;
  if ( pNode->pNext )
    pNode->pNext->pPrev = pNode->pPrev;
  if ( pNode == this->m_pHead )
    this->m_pHead = pNode->pNext;
  if ( pNode == this->m_pTail )
    this->m_pTail = pNode->pPrev;
  pNode->pPrev = 0;
  pNode->pNext = 0;
}