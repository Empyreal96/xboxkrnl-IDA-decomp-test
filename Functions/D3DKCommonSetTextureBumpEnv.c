unsigned int *__usercall D3DK::CommonSetTextureBumpEnv@<eax>(D3DK::CDevice *pDevice@<eax>, unsigned int *pPush@<ecx>, unsigned int *a3@<edx>)
{
  int *v3; // edi
  unsigned int v4; // ebx
  int *v6; // [esp+Ch] [ebp-Ch]
  unsigned int *v7; // [esp+10h] [ebp-8h]
  unsigned int *v8; // [esp+14h] [ebp-4h]

  v3 = (int *)pPush[261];
  v8 = a3;
  v7 = a3 + 1;
  v4 = 7016;
  v6 = &dword_800C2220[32 * (v3 != 0)];
  while ( 1 )
  {
    XMETAL_PushCount(v3, a3, v4, 6u);
    qmemcpy(v7, v6, 0x18u);
    v3 = (int *)(v8 + 7);
    v4 += 64;
    v8 += 7;
    v7 += 7;
    v6 += 32;
    if ( v4 > 0x1BE8 )
      break;
    a3 = v8;
  }
  return (unsigned int *)v3;
}