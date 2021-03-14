void __thiscall CAc97Channel::Pause(CAc97Channel *this)
{
  CAc97Channel *v1; // ST08_4
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  v1 = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  CAc97Channel::PokeAciRegister8(v1, 0xBu, 0);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}