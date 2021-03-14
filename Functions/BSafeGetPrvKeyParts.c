int __stdcall BSafeGetPrvKeyParts(BSAFE_PRV_KEY *key, BSAFE_KEY_PARTS *parts)
{
  char *v3; // edx
  char *v4; // edx
  char *v5; // edx
  char *v6; // edx
  char *v7; // edx
  char *v8; // edx
  char *v9; // edx
  char *v10; // edx

  if ( key->magic != 843141970 )
    return 0;
  parts->modulus = (char *)&key[1];
  v3 = (char *)&key[1] + key->keylen;
  parts->prime1 = v3;
  v4 = &v3[key->keylen >> 1];
  parts->prime2 = v4;
  v5 = &v4[key->keylen >> 1];
  parts->exp1 = v5;
  v6 = &v5[key->keylen >> 1];
  parts->exp2 = v6;
  v7 = &v6[key->keylen >> 1];
  parts->coef = v7;
  v8 = &v7[key->keylen >> 1];
  parts->prvexp = v8;
  v9 = &v8[key->keylen];
  parts->invmod = v9;
  v10 = &v9[key->keylen];
  parts->invpr1 = v10;
  parts->invpr2 = &v10[key->keylen >> 1];
  return 1;
}