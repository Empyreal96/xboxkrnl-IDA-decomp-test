void __stdcall A_SHAUpdate(A_SHA_CTX *context, char *partIn, unsigned int partInLen)
{
  A_SHA_CTX *v3; // eax
  unsigned int v4; // ebp
  unsigned int v5; // ecx
  unsigned int v6; // edx
  char *v7; // ebx
  bool v8; // zf
  int *v9; // edi
  unsigned int v10; // esi
  unsigned int bufferLen; // [esp+10h] [ebp-4h]
  char *partIna; // [esp+1Ch] [ebp+8h]
  unsigned int partInLena; // [esp+20h] [ebp+Ch]

  v3 = context;
  v4 = partInLen;
  v5 = partInLen + context->count[1];
  v6 = context->count[1] & 0x3F;
  bufferLen = context->count[1] & 0x3F;
  context->count[1] = v5;
  if ( v5 < partInLen )
    ++context->count[0];
  if ( v6 && (partInLena = v6 + partInLen, v6 + v4 >= 0x40) )
  {
    qmemcpy(&context->buffer[v6], partIn, 64 - v6);
    v7 = &partIn[64 - v6];
    v4 = partInLena - 64;
    SHATransform((int *)context->state, (unsigned int *)context->buffer);
    v3 = context;
    bufferLen = 0;
    v6 = 0;
  }
  else
  {
    v7 = partIn;
  }
  if ( (unsigned __int8)v7 & 3 )
  {
    if ( v4 < 0x40 )
      goto LABEL_17;
    partIna = (char *)(v4 >> 6);
    do
    {
      qmemcpy(v3->buffer, v7, sizeof(v3->buffer));
      SHATransform((int *)v3->state, (unsigned int *)v3->buffer);
      v7 += 64;
      v4 -= 64;
      v8 = partIna-- == (char *)1;
      v3 = context;
    }
    while ( !v8 );
  }
  else
  {
    if ( v4 < 0x40 )
      goto LABEL_17;
    v9 = (int *)v3->state;
    v10 = v4 >> 6;
    do
    {
      SHATransform(v9, (unsigned int *)v7);
      v7 += 64;
      v4 -= 64;
      --v10;
    }
    while ( v10 );
    v3 = context;
  }
  v6 = bufferLen;
LABEL_17:
  if ( v4 )
    qmemcpy(&v3->buffer[v6], v7, v4);
}