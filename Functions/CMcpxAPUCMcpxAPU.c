void __thiscall CMcpxAPU::CMcpxAPU(CMcpxAPU *this)
{
  CMcpxAPU *thisa; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  thisa = this;
  CRefCount::CRefCount((CRefCount *)&this->vfptr, 1u);
  CMcpxCore::CMcpxCore((CMcpxCore *)&thisa->vfptr);
  thisa->vfptr = (CRefCountVtbl *)&CMcpxAPU::`vftable'{for `CRefCount'};
  thisa->vfptr = (CMcpxCoreVtbl *)&CMcpxAPU::`vftable'{for `CMcpxCore'};
  CMcpxBufferSgeHeap::CMcpxBufferSgeHeap(&thisa->m_SgeHeap);
  _DS3DLISTENER::_DS3DLISTENER();
  D3DXVECTOR3::D3DXVECTOR3();
  for ( i = 0; i < 3; ++i )
  {
    thisa->m_alstActiveVoices[i].Blink = &thisa->m_alstActiveVoices[i];
    thisa->m_alstActiveVoices[i].Flink = thisa->m_alstActiveVoices[i].Blink;
  }
  thisa->m_lstPendingInactiveVoices.Blink = &thisa->m_lstPendingInactiveVoices;
  thisa->m_lstPendingInactiveVoices.Flink = thisa->m_lstPendingInactiveVoices.Blink;
  thisa->m_lst3dVoices.Blink = &thisa->m_lst3dVoices;
  thisa->m_lst3dVoices.Flink = thisa->m_lst3dVoices.Blink;
  thisa->m_lstDeferredCommandsHigh.Blink = &thisa->m_lstDeferredCommandsHigh;
  thisa->m_lstDeferredCommandsHigh.Flink = thisa->m_lstDeferredCommandsHigh.Blink;
  thisa->m_wFree2dVoiceCount = 192;
  thisa->m_wFree3dVoiceCount = 64;
  thisa->m_3dListener.dwSize = 64;
  thisa->m_3dListener.vPosition.x = 0.0;
  thisa->m_3dListener.vPosition.y = 0.0;
  thisa->m_3dListener.vPosition.z = 0.0;
  thisa->m_3dListener.vVelocity.x = 0.0;
  thisa->m_3dListener.vVelocity.y = 0.0;
  thisa->m_3dListener.vVelocity.z = 0.0;
  thisa->m_3dListener.vOrientFront.x = 0.0;
  thisa->m_3dListener.vOrientFront.y = 0.0;
  thisa->m_3dListener.vOrientFront.z = 1.0;
  thisa->m_3dListener.vOrientTop.x = 0.0;
  thisa->m_3dListener.vOrientTop.y = 1.0;
  thisa->m_3dListener.vOrientTop.z = 0.0;
  thisa->m_3dListener.flDistanceFactor = 1.0;
  thisa->m_3dListener.flRolloffFactor = 1.0;
  thisa->m_3dListener.flDopplerFactor = 1.0;
  thisa->m_I3dl2Listener.lRoom = -10000;
  thisa->m_I3dl2Listener.lRoomHF = 0;
  thisa->m_I3dl2Listener.flRoomRolloffFactor = 0.0;
  thisa->m_I3dl2Listener.flDecayTime = 1.0;
  thisa->m_I3dl2Listener.flDecayHFRatio = 0.5;
  thisa->m_I3dl2Listener.lReflections = -10000;
  thisa->m_I3dl2Listener.flReflectionsDelay = 0.02;
  thisa->m_I3dl2Listener.lReverb = -10000;
  thisa->m_I3dl2Listener.flReverbDelay = 0.039999999;
  thisa->m_I3dl2Listener.flDiffusion = 100.0;
  thisa->m_I3dl2Listener.flDensity = 100.0;
  thisa->m_I3dl2Listener.flHFReference = 5000.0;
  thisa->m_v3dNormalizedOrientation.x = 1.0;
  thisa->m_v3dNormalizedOrientation.y = 0.0;
  thisa->m_v3dNormalizedOrientation.z = 0.0;
}