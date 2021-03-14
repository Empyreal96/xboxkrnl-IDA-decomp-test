void __stdcall BenalohModSquare(BenalohData *context, unsigned int *A, unsigned int *B)
{
  Square(context->product, B, context->N);
  BenalohMod(context, context->product, A);
}