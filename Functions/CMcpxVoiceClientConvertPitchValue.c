void __thiscall CMcpxVoiceClient::ConvertPitchValue(CMcpxVoiceClient *this, unsigned int *pdwPitch)
{
  CMcpxBuffer *pSubMixDestination; // [esp+4h] [ebp-8h]
  signed int lPitch; // [esp+8h] [ebp-4h]

  if ( this->m_pSettings->m_dwFlags & 0x82000 )
  {
    LOWORD(lPitch) = 0;
  }
  else
  {
    lPitch = this->m_pSettings->m_lPitch;
    pSubMixDestination = CMcpxVoiceClient::GetSubMixDestination(this);
    if ( pSubMixDestination )
      lPitch += pSubMixDestination->m_pSettings->m_lPitch;
    if ( lPitch <= 0x1FFF )
    {
      if ( lPitch < -32767 )
        LOWORD(lPitch) = -32767;
    }
    else
    {
      LOWORD(lPitch) = 0x1FFF;
    }
  }
  *pdwPitch = (unsigned __int16)lPitch << 16;
}