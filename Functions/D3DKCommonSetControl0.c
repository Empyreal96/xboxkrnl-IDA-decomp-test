unsigned int *__usercall D3DK::CommonSetControl0@<eax>(D3DK::CDevice *pDevice@<eax>, unsigned int *pPush@<ecx>, unsigned int *a3@<edx>, int *a4@<edi>)
{
  unsigned int *v4; // esi
  signed int v5; // edx
  unsigned int v6; // eax
  int v7; // eax

  v4 = a3;
  v5 = 1048577;
  v6 = pPush[260];
  if ( v6 )
  {
    v7 = *(unsigned __int8 *)(v6 + 13);
    if ( v7 == 45 || v7 == 43 || v7 == 49 || v7 == 47 )
      v5 = 1052673;
  }
  XMETAL_Push1f(a4, v4, 0x290u, *(float *)&v5);
  return v4 + 2;
}