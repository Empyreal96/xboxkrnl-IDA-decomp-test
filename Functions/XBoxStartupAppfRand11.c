double __thiscall XBoxStartupApp::fRand11(XBoxStartupApp *this)
{
  return (double)(unsigned __int16)QRand::Rand(&this->qrand) * 0.000030517578 - 1.0;
}