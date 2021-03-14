void __thiscall CList<_SGEHEAPRUNMARKER>::InsertNode(CList<_SGEHEAPRUNMARKER> *this, _SGEHEAPRUNMARKER *pPrev, _SGEHEAPRUNMARKER *pNode)
{
  _SGEHEAPRUNMARKER *v3; // [esp+0h] [ebp-Ch]

  if ( pPrev )
    v3 = pPrev->pNext;
  else
    v3 = this->m_pHead;
  if ( pPrev )
    pPrev->pNext = pNode;
  if ( v3 )
    v3->pPrev = pNode;
  pNode->pPrev = pPrev;
  pNode->pNext = v3;
  if ( this->m_pHead && this->m_pTail )
  {
    if ( this->m_pHead == v3 )
      this->m_pHead = pNode;
    if ( this->m_pTail == pPrev )
      this->m_pTail = pNode;
  }
  else
  {
    this->m_pTail = pNode;
    this->m_pHead = pNode;
  }
}