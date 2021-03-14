void __stdcall tripledes(char *pbOut, char *pbIn, void *pKey, int op)
{
  char rgbEnc1[8]; // [esp+4h] [ebp-10h]
  char rgbEnc2[8]; // [esp+Ch] [ebp-8h]

  if ( op == 1 )
  {
    des(rgbEnc1, pbIn, pKey, 1);
    des(rgbEnc2, rgbEnc1, (char *)pKey + 128, 0);
    des(pbOut, rgbEnc2, (char *)pKey + 256, 1);
  }
  else
  {
    des(rgbEnc1, pbIn, (char *)pKey + 256, 0);
    des(rgbEnc2, rgbEnc1, (char *)pKey + 128, 1);
    des(pbOut, rgbEnc2, pKey, 0);
  }
}