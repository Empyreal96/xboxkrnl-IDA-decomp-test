int __userpurge D3DK::nvKelvinCCSelect2@<eax>(D3DK::CDevice *pDevice@<ecx>, unsigned int dwHWStage@<edi>, unsigned int a3@<eax>, D3DK::CDevice *a4@<edx>, unsigned int dwD3DStage)
{
  a4->m_ColorICW[a3] |= 32 << SLOBYTE(kelvinCombinerInputShift[2]);
  return D3DK::nvKelvinCCSelectColorInput(a4, kelvinCombinerInputD, a3, dwD3DStage, 3u, 0, 0, 0);
}