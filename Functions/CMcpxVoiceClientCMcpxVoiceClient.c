void __thiscall CMcpxVoiceClient::CMcpxVoiceClient(CMcpxVoiceClient *this, CMcpxAPU *pMcpxApu)
{
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]

  thisa = this;
  CRefCount::CRefCount((CRefCount *)&this->vfptr, 1u);
  thisa->vfptr = (CRefCountVtbl *)&CMcpxVoiceClient::`vftable';
  _DS3DBUFFER::_DS3DBUFFER();
  thisa->m_pMcpxApu = __AddRef(pMcpxApu);
  for ( i = 0; i < 3; ++i )
    thisa->m_ahVoices[i] = (void *)-1;
  thisa->m_3dBuffer.dwSize = 64;
  thisa->m_3dBuffer.vPosition.x = 0.0;
  thisa->m_3dBuffer.vPosition.y = 0.0;
  thisa->m_3dBuffer.vPosition.z = 0.0;
  thisa->m_3dBuffer.vVelocity.x = 0.0;
  thisa->m_3dBuffer.vVelocity.y = 0.0;
  thisa->m_3dBuffer.vVelocity.z = 0.0;
  thisa->m_3dBuffer.dwInsideConeAngle = 360;
  thisa->m_3dBuffer.dwOutsideConeAngle = 360;
  thisa->m_3dBuffer.vConeOrientation.x = 0.0;
  thisa->m_3dBuffer.vConeOrientation.y = 0.0;
  thisa->m_3dBuffer.vConeOrientation.z = 1.0;
  thisa->m_3dBuffer.lConeOutsideVolume = 0;
  thisa->m_3dBuffer.flMaxDistance = 1000000000.0;
  thisa->m_3dBuffer.flMinDistance = 1.0;
  thisa->m_3dBuffer.dwMode = 0;
  thisa->m_I3dl2Buffer.lDirect = 0;
  thisa->m_I3dl2Buffer.lDirectHF = 0;
  thisa->m_I3dl2Buffer.lRoom = 0;
  thisa->m_I3dl2Buffer.lRoomHF = 0;
  thisa->m_I3dl2Buffer.flRoomRolloffFactor = 0.0;
  thisa->m_I3dl2Buffer.Obstruction.lHFLevel = 0;
  thisa->m_I3dl2Buffer.Obstruction.flLFRatio = 0.0;
  thisa->m_I3dl2Buffer.Occlusion.lHFLevel = 0;
  thisa->m_I3dl2Buffer.Occlusion.flLFRatio = 0.25;
  thisa->m_dw3dParameterMask = 255;
  thisa->m_leActiveVoice.Blink = &thisa->m_leActiveVoice;
  thisa->m_leActiveVoice.Flink = thisa->m_leActiveVoice.Blink;
  thisa->m_lePendingInactiveVoice.Blink = &thisa->m_lePendingInactiveVoice;
  thisa->m_lePendingInactiveVoice.Flink = thisa->m_lePendingInactiveVoice.Blink;
  thisa->m_le3dVoice.Blink = &thisa->m_le3dVoice;
  thisa->m_le3dVoice.Flink = thisa->m_le3dVoice.Blink;
  thisa->m_leSourceVoice.Blink = &thisa->m_leSourceVoice;
  thisa->m_leSourceVoice.Flink = thisa->m_leSourceVoice.Blink;
  thisa->m_lstSourceVoices.Blink = &thisa->m_lstSourceVoices;
  thisa->m_lstSourceVoices.Flink = thisa->m_lstSourceVoices.Blink;
  thisa->m_bVoiceList = -1;
}