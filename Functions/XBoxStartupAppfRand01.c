double __thiscall XBoxStartupApp::fRand01(XBoxStartupApp *this)
{
  return (double)(unsigned __int16)QRand::Rand(&this->qrand) * 0.000015258789;
}