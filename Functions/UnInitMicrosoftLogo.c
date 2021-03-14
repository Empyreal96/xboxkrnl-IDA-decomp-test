void __usercall UnInitMicrosoftLogo(int *a1@<edi>)
{
  if ( g_ImageLogo )
    MemFree(g_ImageLogo);
  if ( g_pVBMicrosoftLogo )
    D3DResource_Release(a1, (D3DResource *)&g_pVBMicrosoftLogo->Common);
  if ( g_pTexMicrosoftLogo )
    D3DResource_Release(a1, (D3DResource *)&g_pTexMicrosoftLogo->Common);
}