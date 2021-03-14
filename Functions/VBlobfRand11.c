double __stdcall VBlob::fRand11()
{
  return (double)(unsigned __int16)QRand::Rand(&VBlob::m_QRand) * 0.000030517578 - 1.0;
}