void __thiscall CAc97Channel::ServiceInterrupt(CAc97Channel *this)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  if ( this->m_bPrdCount )
  {
    this->m_dwPosition += *((_DWORD *)&this->m_pPrdl[(unsigned __int8)this->m_bCurrentPrd] + 1) & 0xFFFF;
    if ( this->m_dwFlags & 1 )
    {
      if ( (signed int)(unsigned __int8)this->m_bPrdCount <= 2 )
        CAc97Channel::Flush(this, 0);
      else
        CAc97Channel::SetPrdIndeces(this, this->m_bCurrentPrd + 1, this->m_bPrdCount - 1, 0, 0);
    }
    else
    {
      CAc97Channel::SetPrdIndeces(this, this->m_bCurrentPrd + 1, this->m_bPrdCount, 0, 0);
    }
    if ( thisa->m_pfnCallback )
      thisa->m_pfnCallback(thisa->m_pvCallbackContext);
  }
}