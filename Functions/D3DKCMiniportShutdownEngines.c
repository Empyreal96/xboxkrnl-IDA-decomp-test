void __thiscall D3DK::CMiniport::ShutdownEngines(D3DK::CMiniport *this)
{
  D3DK::CMiniport *v1; // edi
  unsigned int *v2; // esi
  int v3; // edx
  int v4; // edx
  unsigned int v5; // eax
  int *v6; // ecx
  unsigned int FifoReassign; // [esp+Ch] [ebp-10h]
  unsigned int FifoPush; // [esp+10h] [ebp-Ch]
  int TileRegion; // [esp+18h] [ebp-4h]
  unsigned int TileRegiona; // [esp+18h] [ebp-4h]

  v1 = this;
  v2 = (unsigned int *)this->m_RegisterBase;
  if ( !AvGetSavedDataAddress() )
    AvSendTVEncoderOption(v2, 9u, 1u, 0);
  TileRegion = 0;
  do
    D3DK::CMiniport::DestroyTile(v1, v3, TileRegion++, 1u);
  while ( TileRegion < 8 );
  v2[2065] = 0;
  while ( !(v2[3205] & 0x10) || !(v2[2304] & 0x10) || v2[3208] & 0x10 )
  {
    D3DK::CMiniport::ServiceFifoInterrupt(v1, v3);
    if ( v2[1048640] )
      D3DK::CMiniport::ServiceGrInterrupt(v1, (int *)v1);
    if ( v2[64] & 0x1000000 )
      D3DK::CMiniport::VBlank(v1, v3);
  }
  v2[3208] = 0;
  while ( v2[3208] & 0x10 )
    ;
  v2[2368] = 0;
  v2[3072] = 0;
  v2[3092] = 0;
  v2[3200] = 0;
  v2[3220] = 0;
  D3DK::CMiniport::HalFifoContextSwitch(v1, 1u);
  v2[3204] = 0;
  v2[3228] = 0;
  FifoReassign = v2[2368];
  FifoPush = v2[3200];
  v5 = v2[3220];
  v2[2368] = 0;
  v2[3200] = 0;
  v2[3220] = 0;
  TileRegiona = 0;
  do
  {
    if ( v1->m_HalInfo.FifoInUse )
    {
      v6 = (int *)((char *)&v2[TileRegiona] + v1->m_HalInfo.FifoContextAddr1);
      v4 = *v6;
      v6[1] = *v6;
      *(unsigned int *)((char *)&v2[TileRegiona + 4] + v1->m_HalInfo.FifoContextAddr1) = 0;
    }
    TileRegiona += 16;
  }
  while ( TileRegiona < 32 );
  v2[3220] = v5;
  v2[3200] = FifoPush;
  v2[2368] = FifoReassign;
  v2[2370] = 0;
  v2[2128] = 0;
  D3DK::CMiniport::HalGrLoadChannelContext(v1, v4, (int *)v1, 2u);
  v2[262272] = v1->m_HalInfo.FbSave0;
  v2[262273] = v1->m_HalInfo.FbSave1;
  v2[128] = v1->m_HalInfo.McSave;
  v2[80] = v1->m_HalInfo.McSaveIntrEn0;
  HalRegisterShutdownNotification(&v1->m_ShutdownRegistration, 0);
  KeDisconnectInterrupt(&v1->m_InterruptObject);
}