int __thiscall QRand::Rand(QRand *this, int scale)
{
  int v2; // eax

  v2 = __ROR4__(this->seed, 13) - (this->seed - 11);
  this->seed = v2;
  return (unsigned int)scale * (unsigned __int64)(unsigned int)v2 >> 32;
}