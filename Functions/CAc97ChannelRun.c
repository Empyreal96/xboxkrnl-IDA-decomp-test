void __thiscall CAc97Channel::Run(CAc97Channel *this, unsigned int dwPosition)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-Ch]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( CAc97Channel::PeekAciRegister16(thisa, 6u) & 1 )
    CAc97Channel::Reset(thisa);
  if ( dwPosition != -1 )
    CAc97Channel::SetPosition(thisa, dwPosition);
  CAc97Channel::PokeAciRegister8(thisa, 0xBu, 29);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}