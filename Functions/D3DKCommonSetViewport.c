unsigned int *__usercall D3DK::CommonSetViewport@<eax>(D3DK::CDevice *pDevice@<eax>, unsigned int *pPush@<ecx>, int *a3@<edx>)
{
  unsigned int *v3; // esi
  int *v4; // edi
  unsigned int v5; // eax
  float fm11; // ST24_4
  float fm22; // ST28_4
  float fm33; // ST20_4
  float c; // ST10_4
  float b; // ST0C_4
  float a; // ST08_4
  unsigned int *result; // eax
  float v13; // ST14_4
  float v14; // ST10_4
  float xViewport; // [esp+24h] [ebp-8h]
  float yViewport; // [esp+28h] [ebp-4h]

  v3 = pPush;
  v4 = a3;
  xViewport = (double)pPush[704] * *((float *)pPush + 321) + 0.53125;
  yViewport = (double)v3[705] * *((float *)v3 + 322) + 0.53125;
  if ( *(_BYTE *)(pPush[285] + 8) & 6 )
  {
    v5 = pPush[3];
    if ( !(v5 & 0x200) )
    {
      fm11 = (double)pPush[706] * *((float *)pPush + 321) * 0.5;
      fm22 = (double)pPush[707] * *((float *)pPush + 322) * -0.5;
      fm33 = (*((float *)pPush + 709) - *((float *)pPush + 708)) * *((float *)pPush + 319);
      c = *((float *)pPush + 708) * *((float *)pPush + 319);
      b = yViewport - fm22;
      a = fm11 + xViewport;
      XMETAL_Push4f(a3, (unsigned int *)a3, 0xA20u, a, b, c, 0.0);
      XMETAL_Push4f(v4, (unsigned int *)v4 + 5, 0xAF0u, fm11, fm22, fm33, 0.0);
      v4 += 10;
    }
    XMETAL_Push2f(v4, (unsigned int *)v4, 0x394u, 0.0, *((float *)v3 + 319));
    result = (unsigned int *)(v4 + 3);
  }
  else
  {
    XMETAL_Push4f(a3, (unsigned int *)a3, 0xA20u, xViewport, yViewport, 0.0, 0.0);
    v13 = *((float *)v3 + 709) * *((float *)v3 + 319);
    v14 = *((float *)v3 + 708) * *((float *)v3 + 319);
    XMETAL_Push2f(v4, (unsigned int *)v4 + 5, 0x394u, v14, v13);
    result = (unsigned int *)(v4 + 8);
  }
  return result;
}