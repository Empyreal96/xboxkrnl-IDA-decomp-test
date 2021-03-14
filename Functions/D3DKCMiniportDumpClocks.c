void __fastcall D3DK::CMiniport::DumpClocks(D3DK::CMiniport *this, int a2)
{
  float v2; // eax
  int v3; // ebx
  double v4; // st7
  int v5; // eax
  int v6; // edx
  int v7; // esi
  unsigned __int64 v8; // rax
  unsigned int v9; // edi
  int v10; // ecx
  unsigned int v11; // eax
  const char *v12; // edx
  D3DK::CMiniport *v13; // [esp+Ch] [ebp-14h]
  _DWORD *nvpll; // [esp+14h] [ebp-Ch]
  unsigned int nvplla; // [esp+14h] [ebp-Ch]
  unsigned int MPLLCoeff; // [esp+18h] [ebp-8h]
  float XTAL; // [esp+1Ch] [ebp-4h]

  nvpll = this->m_RegisterBase;
  v2 = F_XTAL_166;
  v13 = this;
  if ( this->m_GenInfo.CrystalFreq != 16666666 )
    v2 = F_XTAL_135;
  XTAL = v2;
  HalReadWritePCISpace((int)this, a2, 0, 0x60u, 0x6Cu, &MPLLCoeff, 4u, 0);
  v3 = (unsigned __int16)MPLLCoeff >> 8;
  if ( (_BYTE)MPLLCoeff )
  {
    v5 = nvpll[1704256];
    v6 = nvpll[1704256] & 0xFF;
    nvplla = nvpll[1704256];
    if ( (_BYTE)nvplla )
      v7 = (unsigned __int64)((double)((unsigned __int16)v5 >> 8)
                            * XTAL
                            / (double)(1 << SBYTE2(nvplla))
                            / (double)(unsigned int)v6);
    else
      v7 = 0;
    v8 = (unsigned __int64)((double)(2 * v3 * ((MPLLCoeff >> 16) & 0xF)) * (XTAL / (double)(unsigned __int8)MPLLCoeff));
    v9 = 2 * ((MPLLCoeff >> 20) & 0xF);
    v10 = v8;
    v11 = (unsigned int)v8 / v9;
    v12 = "16.6";
    if ( v13->m_GenInfo.CrystalFreq != 16666666 )
      v12 = "13.5";
    v4 = XTAL / (double)(unsigned __int8)MPLLCoeff * (double)(unsigned int)v3;
    DbgPrint(
      (int *)v9,
      "Crystal=%s  FSB=%d  CPU=%d  NVCLK=%d  VCO=%d  MCLK=%d\n",
      v12,
      (unsigned int)(unsigned __int64)v4,
      (unsigned int)(unsigned __int64)(v4 * 5.5),
      v7,
      v10,
      v11);
  }
  else
  {
    D3DK::DXGRIP((int *)MPLLCoeff, "MP: Failed to display clock speeds because m=0");
  }
}