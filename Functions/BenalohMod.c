void __stdcall BenalohMod(BenalohData *context, unsigned int *A, unsigned int *B)
{
  unsigned int *v3; // edx
  unsigned int *v4; // ebp
  unsigned int v5; // edi
  unsigned int *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  signed int v11; // eax
  int v12; // eax
  bool v13; // zf
  unsigned int v14; // eax
  unsigned int *V; // [esp+10h] [ebp-4h]
  BenalohData *contexta; // [esp+18h] [ebp+4h]

  v3 = context->V;
  v4 = context->M;
  v5 = context->N;
  v6 = &A[context->N - 2];
  v7 = 0;
  contexta = (BenalohData *)context->U;
  for ( V = v3; v6 >= A; --v6 )
  {
    v8 = v6[v5 + 1];
    if ( v8 >= v7 )
      v7 = Reduce(v6, v8 - v7, V, v5);
    else
      v7 = Reduce(v6, v7 - v8, &contexta->N, v5);
  }
  v9 = v5;
  v10 = A[v5];
  if ( v10 >= v7 )
  {
    A[v9] = v10 - v7;
    if ( Compare(A + 1, v4, v5) >= 0 )
      Sub((int)(A + 1), (int)(A + 1), v4, v5);
  }
  else
  {
    A[v9] = v10 - v7;
    while ( !Add((int)(A + 1), (int)(A + 1), v4, v5) )
      ;
  }
  v11 = BenalohEstimateQuotient(A[v9], A[v9 - 1], v4[v9 - 1]);
  v12 = Reduce(A, v11, v4, v5);
  v13 = A[v9] == v12;
  A[v9] -= v12;
  if ( !v13 )
  {
    do
    {
      v14 = Add((int)A, (int)A, v4, v5) + A[v9];
      A[v9] = v14;
    }
    while ( v14 );
  }
  qmemcpy(B, A, v9 * 4);
}