int __thiscall D3DK::CMiniport::BindToChannel(D3DK::CMiniport *this, D3DK::CMiniport::OBJECTINFO *Object)
{
  D3DK::CMiniport::HalFifoHashAdd(
    this,
    ((unsigned __int16)Object->Handle ^ (unsigned __int16)((Object->Handle ^ (Object->Handle >> 11)) >> 11)) & 0x7FF,
    Object->Handle,
    this->m_HalInfo.FifoChID,
    Object->Instance,
    Object->Engine);
  return 1;
}