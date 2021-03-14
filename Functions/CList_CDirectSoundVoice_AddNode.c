void __thiscall CList<CDirectSoundVoice>::AddNode(CList<CDirectSoundVoice> *this, CDirectSoundVoice *pNode)
{
  CList<CDirectSoundVoice>::InsertNode(this, this->m_pTail, pNode);
}