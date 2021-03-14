void __thiscall CList<_SGEHEAPRUNMARKER>::AddNode(CList<_SGEHEAPRUNMARKER> *this, _SGEHEAPRUNMARKER *pNode)
{
  CList<_SGEHEAPRUNMARKER>::InsertNode(this, this->m_pTail, pNode);
}