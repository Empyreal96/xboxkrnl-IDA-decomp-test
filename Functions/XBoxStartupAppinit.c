char __userpurge XBoxStartupApp::init@<al>(XBoxStartupApp *this@<ecx>, int *a2@<edi>, int width, int height)
{
  XBoxStartupApp *v4; // esi
  const char *v5; // eax
  double v6; // st7
  float r; // ST20_4
  float v8; // eax
  int *v9; // edi
  double v10; // st7
  float aspect; // ST1C_4
  int v12; // edx
  int v13; // edx
  volatile unsigned int v14; // eax
  _D3DMATRIX matRot; // [esp+2Ch] [ebp-138h]
  _D3DMATRIX matZ; // [esp+6Ch] [ebp-F8h]
  _D3DMATRIX matX; // [esp+ACh] [ebp-B8h]
  _D3DVECTOR pos; // [esp+ECh] [ebp-78h]
  unsigned int dwBumpDecl[8]; // [esp+F8h] [ebp-6Ch]
  unsigned int dwPhongDecl[7]; // [esp+118h] [ebp-4Ch]
  unsigned int dwDepthDecl[3]; // [esp+134h] [ebp-30h]
  _D3DVECTOR tmp; // [esp+140h] [ebp-24h]
  _D3DVECTOR look; // [esp+14Ch] [ebp-18h]
  _D3DVECTOR up; // [esp+158h] [ebp-Ch]

  v4 = this;
  this->fIIDT = 0.0;
  this->fBaseBlobIntensity = 0.0;
  this->fBlobIntensity = 0.0;
  this->fSmoothedBlobIntensity = 0.0;
  XBoxStartupApp::initIntensityPulses(this);
  v4->nHeight = height;
  v4->nWidth = width;
  Renderer::init(&v4->theRenderer, a2, width, height);
  v4->pNormalCubeMapHiRes = CreateNormalizationCubeMap(0x80u);
  v4->pNormalCubeMapLoRes = CreateNormalizationCubeMap(0x40u);
  v4->pRoughBumpMap = CreateIntensityTexture(128, 1, 0.001953125, 512, 0, 0xFFFFFF, 255, 0, 0xFFu, 50);
  dwBumpDecl[7] = -1;
  dwPhongDecl[6] = -1;
  dwDepthDecl[2] = -1;
  v4->pGlowMap = CreateGlowTexture(256, 256, -1, 0, 12345);
  dwBumpDecl[1] = 1077018624;
  dwPhongDecl[1] = 1077018624;
  dwDepthDecl[1] = 1077018624;
  dwBumpDecl[4] = 1077018626;
  dwPhongDecl[4] = 1077018626;
  dwBumpDecl[0] = 0x20000000;
  dwPhongDecl[0] = 0x20000000;
  dwDepthDecl[0] = 0x20000000;
  dwBumpDecl[2] = 536870913;
  dwBumpDecl[3] = 1075970049;
  dwBumpDecl[5] = 1077018627;
  dwBumpDecl[6] = 1077018628;
  dwPhongDecl[2] = 536870913;
  dwPhongDecl[3] = 1077018625;
  dwPhongDecl[5] = 1077018627;
  v4->dwVShader[0] = (unsigned int)XBoxStartupApp::loadVertexShader(g_scene_phong_xvu, dwPhongDecl);
  v4->dwPShader[0] = (unsigned int)XBoxStartupApp::loadPixelShader(&gApp, &gApp.nWidth, g_scene_phong_xpu);
  v4->dwVShader[1] = (unsigned int)XBoxStartupApp::loadVertexShader(g_scene_bump_xvu, dwBumpDecl);
  v4->dwPShader[1] = (unsigned int)XBoxStartupApp::loadPixelShader(&gApp, &gApp.nWidth, g_scene_bump_xpu);
  v4->dwVShader[2] = (unsigned int)XBoxStartupApp::loadVertexShader(g_scene_zr_xvu, dwDepthDecl);
  v5 = XBoxStartupApp::loadPixelShader(&gApp, &gApp.nWidth, g_scene_zr_xpu);
  v6 = v4->fCamPhi;
  v4->dwPShader[2] = (unsigned int)v5;
  r = v6;
  SetXRotation(r, &matX);
  SetZRotation(v4->fCamTheta, &matZ);
  MulMats(&matX, &matZ, &matRot);
  v8 = v4->fCamRad;
  tmp.x = 0.0;
  tmp.y = v8;
  tmp.z = -10.0;
  TransformVector(&tmp, &matRot, &pos);
  look.x = 0.0;
  look.y = 0.0;
  look.z = 0.0;
  v9 = (int *)&v4->theCamera;
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  Camera::lookAt(&v4->theCamera, &pos, &look, &up);
  if ( v4->bWideScreen )
    v10 = 0.5625;
  else
    v10 = 0.75;
  aspect = v10;
  Camera::setProjection(&v4->theCamera, 0.78539819, aspect, 0.40000001, 800.0);
  SceneRenderer::create(&v4->sceneGeom, v12);
  LogoRenderer::create(&v4->logoGeom, v9, v13);
  VBlob::create(&v4->vblob, v9);
  GreenFog::create(&v4->greenFog, v9);
  v4->pStaticReflectionCubeMap = CreateStaticReflectionCubeMap(0x100u);
  v14 = KeTickCount;
  v4->dwLastTick = KeTickCount;
  v4->dwLastFramecountTick = v14;
  return 1;
}