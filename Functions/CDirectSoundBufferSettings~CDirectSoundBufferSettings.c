void __usercall CDirectSoundBufferSettings::~CDirectSoundBufferSettings(CDirectSoundBufferSettings *this@<ecx>, int a2@<esi>)
{
  CDirectSoundBufferSettings *v2; // ST08_4

  v2 = this;
  this->vfptr = (CRefCountVtbl *)&CDirectSoundBufferSettings::`vftable';
  CDirectSoundBufferSettings::SetBufferData(this, a2, 0, 0);
  CDirectSoundVoiceSettings::~CDirectSoundVoiceSettings((CDirectSoundVoiceSettings *)&v2->vfptr);
}