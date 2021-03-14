void __thiscall CDirectSoundSettings::SetEffectImageLocations(CDirectSoundSettings *this, _DSEFFECTIMAGELOC *pImageLoc)
{
  if ( pImageLoc )
    memcpy((char *)&this->m_EffectLocations, (char *)pImageLoc, 8u);
  else
    memset(&this->m_EffectLocations, 255, 8u);
}