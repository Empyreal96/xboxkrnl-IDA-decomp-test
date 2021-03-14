CMcpxVoiceClient *__thiscall CMcpxVoiceClient::`scalar deleting destructor'(CMcpxVoiceClient *this, unsigned int a2)
{
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CMcpxVoiceClient::~CMcpxVoiceClient(this);
  if ( a2 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}