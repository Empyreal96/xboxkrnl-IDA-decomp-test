tWAVEFORMATEX *__userpurge CopyFormatAlloc@<eax>(int a1@<esi>, tWAVEFORMATEX *pwfxSrc)
{
  int v2; // ecx
  unsigned int cbSrc; // [esp+0h] [ebp-Ch]
  char *pwfxDest; // [esp+4h] [ebp-8h]
  unsigned int cbDest; // [esp+8h] [ebp-4h]

  cbSrc = GetFormatSize(pwfxSrc, 0x80000000);
  cbDest = GetFormatSize(pwfxSrc, 0x40000000u);
  pwfxDest = PoolAlloc(cbDest, v2, a1, cbDest, 0);
  if ( pwfxDest )
  {
    memcpy(pwfxDest, (char *)pwfxSrc, cbSrc);
    memset(&pwfxDest[cbSrc], 0, cbDest - cbSrc);
  }
  return (tWAVEFORMATEX *)pwfxDest;
}