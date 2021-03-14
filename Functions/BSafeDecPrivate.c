int __stdcall BSafeDecPrivate(BSAFE_PRV_KEY *const key, const char *part_in, char *part_out)
{
  unsigned int v4; // eax
  BSAFE_KEY_PARTS parts; // [esp+4h] [ebp-28h]

  if ( key->magic != 843141970 || !BSafeGetPrvKeyParts(key, &parts) )
    return 0;
  v4 = (key->bitlen >> 6) + 1;
  if ( (key->bitlen >> 1) & 0x1F )
    v4 = (key->bitlen >> 6) + 2;
  if ( key->pubexp != 1 )
    return BenalohModRoot(
             (int)part_out,
             (int)parts.prime1,
             (unsigned int *)part_out,
             (unsigned int *)part_in,
             (unsigned int *)parts.prime1,
             (unsigned int *)parts.prime2,
             (unsigned int *)parts.exp1,
             (unsigned int *)parts.exp2,
             (unsigned int *)parts.coef,
             v4);
  qmemcpy(part_out, part_in, 8 * v4);
  return 1;
}