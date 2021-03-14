void __stdcall A_SHAInit(A_SHA_CTX *context)
{
  context->count[0] = 0;
  context->count[1] = 0;
  context->state[0] = 1732584193;
  context->state[1] = -271733879;
  context->state[2] = -1732584194;
  context->state[3] = 271733878;
  context->state[4] = -1009589776;
}