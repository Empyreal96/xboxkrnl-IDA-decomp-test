void __usercall AnipRunAnimation(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  IDirectSound *pDSound; // [esp+8h] [ebp-4h]

  WriteSMC(a1, a2, a3, a4, 11, 1);
  DirectSoundCreate(0, a4, 0, &pDSound, 0);
  XBoxStartupApp::Construct(&gApp);
  if ( XBoxStartupApp::init(&gApp, 0, 640, 480) )
  {
    IDirectSound_Release(pDSound);
    WriteSMC(v4, v5, 0, (int)&gApp, 11, 0);
    XBoxStartupApp::run(&gApp, v6, 0);
    XBoxStartupApp::shutdown(&gApp, 0);
    if ( gcMemAllocsContiguous )
      __debugbreak();
    if ( gcMemAllocs )
      __debugbreak();
  }
}