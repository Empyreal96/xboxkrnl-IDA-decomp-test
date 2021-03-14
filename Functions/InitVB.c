int __userpurge InitVB@<eax>(int *a1@<edi>, int a2@<ecx>, D3DDevice *pDev)
{
  int *v4; // edi
  void *pVerts; // [esp+8h] [ebp-8h]
  D3DVertexBuffer *pVB; // [esp+Ch] [ebp-4h]

  if ( D3DDevice_CreateVertexBuffer(a1, a2, 144, 0x90u, 8u, 0x104u, 1u, &pVB) < 0 )
    return 0;
  D3DVertexBuffer_Lock(a1, pVB, 0, 0x90u, (char **)&pVerts, 0);
  v4 = (int *)pVerts;
  qmemcpy(pVerts, Verts, 0x90u);
  v4 += 36;
  D3DDevice_SetStreamSource(v4, 0, pVB, 0x18u);
  D3DDevice_SetVertexShader(v4, 0x104u);
  return 1;
}