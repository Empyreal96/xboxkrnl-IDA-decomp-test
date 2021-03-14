D3DDevice *__usercall InitD3D@<eax>(int *a1@<edi>)
{
  D3DDevice *result; // eax
  _D3DPRESENT_PARAMETERS_ d3dpp; // [esp+4h] [ebp-38h]
  D3DDevice *pDev; // [esp+38h] [ebp-4h]

  result = (D3DDevice *)Direct3DCreate8(a1, 0);
  if ( result )
  {
    memset(&d3dpp, 0, sizeof(d3dpp));
    pDev = 0;
    d3dpp.BackBufferWidth = 640;
    d3dpp.BackBufferHeight = 480;
    d3dpp.BackBufferFormat = 7;
    d3dpp.BackBufferCount = 1;
    d3dpp.Windowed = 0;
    d3dpp.EnableAutoDepthStencil = 1;
    d3dpp.AutoDepthStencilFormat = 42;
    d3dpp.SwapEffect = 1;
    d3dpp.FullScreen_RefreshRateInHz = 60;
    d3dpp.hDeviceWindow = 0;
    d3dpp.FullScreen_PresentationInterval = 2147483648;
    Direct3D_CreateDevice((int *)&pDev, 0, D3DDEVTYPE_HAL, 0, 0x40u, &d3dpp, &pDev);
    result = pDev;
  }
  return result;
}