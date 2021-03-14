int __usercall D3DK::nvKelvinACPremodulate@<eax>(unsigned int dwHWStage@<edi>, unsigned int dwD3DStage@<edx>, unsigned int a3@<eax>, unsigned int a4@<ebx>, D3DK::CDevice *a5@<esi>)
{
  unsigned int v5; // edi
  unsigned int v6; // edi
  int hr; // ST24_4
  unsigned int dwTemp; // ST20_4
  int v9; // eax
  int result; // eax

  v5 = a3;
  if ( a3 )
  {
    result = D3DK::nvKelvinACSelectAlphaInput(a5, 0, a3, a4, 6u, 0, 0);
    a5->m_AlphaICW[v5] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
  }
  else
  {
    v6 = a4 << 7;
    if ( dword_800C2258[32 * a4] == 1 )
    {
      result = D3DK::nvKelvinACSelectAlphaInput(a5, 0, 0, a4, 6u, 0, 0);
      a5->m_AlphaICW[0] |= 32 << SLOBYTE(kelvinCombinerInputShift[1]);
    }
    else
    {
      hr = D3DK::nvKelvinACSelectAlphaInput(a5, 0, 0, a4, 6u, 0, 0);
      dwTemp = *(int *)((char *)dword_800C21E4 + v6);
      *(int *)((char *)dword_800C21E4 + v6) = 2;
      v9 = D3DK::nvKelvinACSelectAlphaInput(a5, kelvinCombinerInputB, 0, a4, 7u, 0, 0);
      *(int *)((char *)dword_800C21E4 + v6) = dwTemp;
      result = v9 | hr;
    }
  }
  return result;
}