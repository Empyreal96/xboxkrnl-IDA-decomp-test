double __stdcall VBlob::fRand01()
{
  return (double)(unsigned __int16)QRand::Rand(&VBlob::m_QRand) * 0.000015258789;
}