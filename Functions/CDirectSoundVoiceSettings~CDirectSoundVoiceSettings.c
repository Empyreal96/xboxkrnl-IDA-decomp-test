void __thiscall CDirectSoundVoiceSettings::~CDirectSoundVoiceSettings(CDirectSoundVoiceSettings *this)
{
  CDirectSoundVoiceSettings *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  this->vfptr = (CRefCountVtbl *)&CDirectSoundVoiceSettings::`vftable';
  if ( this->m_pMixinBuffer )
    CDirectSoundVoiceSettings::SetOutputBuffer(this, 0);
  if ( !(thisa->m_dwFlags & 0x82000) )
    PoolFree((void **)&thisa->m_pwfxFormat);
  __Release((CDirectSoundBufferSettings **)&thisa->m_pGlobalSettings);
  CRefCount::~CRefCount((CRefCount *)&thisa->vfptr);
}