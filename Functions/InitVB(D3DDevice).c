// write access to const memory has been detected, the output may be wrong!
int __userpurge InitVB@<eax>(int *a1@<edi>, int a2@<ecx>, D3DDevice *pDev)
{
  void *pVerts; // [esp+4h] [ebp-8h]
  D3DVertexBuffer *pVB; // [esp+8h] [ebp-4h]

  if ( D3DDevice_CreateVertexBuffer(a1, a2, 144, 0x90u, 8u, 0x104u, 1u, &pVB) < 0 )
    return 0;
  g_pVBMicrosoftLogo = pVB;
  D3DVertexBuffer_Lock(a1, pVB, 0, 0x90u, (char **)&pVerts, 0);
  qmemcpy(pVerts, Verts, 0x90u);
  return 1;
}