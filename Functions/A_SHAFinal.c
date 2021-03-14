void __stdcall A_SHAFinal(A_SHA_CTX *context, char *digest)
{
  unsigned int v2; // edx
  unsigned int v3; // ebx
  unsigned int bitCount[2]; // [esp+10h] [ebp-50h]
  char pad[72]; // [esp+18h] [ebp-48h]

  v2 = context->count[1];
  v3 = 64 - (context->count[1] & 0x3F);
  if ( v3 <= 8 )
    v3 += 64;
  memset(pad, 0, v3 - 6);
  bitCount[0] = (v2 >> 29) | 8 * context->count[0];
  pad[0] = -128;
  bitCount[1] = 8 * v2;
  DWORDToBigEndian((char *)bitCount + v3, bitCount, 2u);
  A_SHAUpdate(context, pad, v3);
  DWORDToBigEndian(digest, context->state, 5u);
  context->state[0] = 1732584193;
  context->count[0] = 0;
  context->count[1] = 0;
  context->state[1] = -271733879;
  context->state[2] = -1732584194;
  context->state[3] = 271733878;
  context->state[4] = -1009589776;
}