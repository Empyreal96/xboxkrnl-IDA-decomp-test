// write access to const memory has been detected, the output may be wrong!
void __fastcall AniSetLogo(int a1, int a2, void *pv, unsigned int Size)
{
  int *v4; // eax

  if ( !g_EventLogo.Header.SignalState )
  {
    if ( gpd3dDev && pv && Size <= 0x1000 )
    {
      v4 = MemAlloc(a2, a1, (int)pv, Size);
      g_ImageLogo = (char *)v4;
      if ( v4 )
      {
        qmemcpy(v4, pv, Size);
        a1 = 0;
        g_ImageLogoSize = Size;
      }
    }
    KeSetEvent(a1, a2, &g_EventLogo, 1, 0);
  }
}