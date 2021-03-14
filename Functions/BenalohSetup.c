int __stdcall BenalohSetup(BenalohData *context, unsigned int *modulus, unsigned int length)
{
  unsigned int v3; // ebp
  int *v4; // eax
  unsigned int *v5; // ecx
  char *SlowBuffer; // [esp+10h] [ebp-4h]

  if ( !length )
    return 0;
  v3 = length;
  if ( !modulus[length - 1] )
    return 0;
  v4 = RSA32Alloc(20 * length + 4, 12 * length, (int)modulus, 20 * length + 4);
  SlowBuffer = (char *)v4;
  if ( !v4 )
    return 0;
  context->U = (unsigned int *)&v4[v3];
  v5 = (unsigned int *)&v4[v3 + v3];
  context->V = v5;
  context->product = &v5[v3];
  context->M = (unsigned int *)v4;
  qmemcpy(v4, modulus, v3 * 4);
  if ( (context->M[v3 - 1] & 0x80000000) == 0 )
  {
    do
      Add((int)context->M, (int)context->M, context->M, length);
    while ( !(context->M[v3 - 1] & 0x80000000) );
  }
  memset(context->product, 0, v3 * 4 + 4);
  context->product[v3 + 1] = 1;
  if ( !Mod(length + 2, context->U, context->product, modulus, context->U, length + 2, length) )
  {
    RSA32Free(SlowBuffer);
    return 0;
  }
  Sub((int)context->V, (int)modulus, context->U, length);
  context->N = length;
  return 1;
}