int __thiscall QRand::Rand(QRand *this)
{
  int result; // eax

  result = __ROR4__(this->seed, 13) - (this->seed - 11);
  this->seed = result;
  return result;
}