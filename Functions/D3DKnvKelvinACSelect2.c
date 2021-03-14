int __userpurge D3DK::nvKelvinACSelect2@<eax>(D3DK::CDevice *pDevice@<ecx>, unsigned int dwHWStage@<edi>, unsigned int a3@<eax>, D3DK::CDevice *a4@<edx>, unsigned int dwD3DStage)
{
  a4->m_AlphaICW[a3] |= 32 << SLOBYTE(kelvinCombinerInputShift[2]);
  return D3DK::nvKelvinACSelectAlphaInput(a4, kelvinCombinerInputD, a3, dwD3DStage, 7u, 0, 0);
}