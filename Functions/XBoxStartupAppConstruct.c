void __thiscall XBoxStartupApp::Construct(XBoxStartupApp *this)
{
  XBoxStartupApp *v1; // esi
  double v2; // st7
  double v3; // st7
  double v4; // st7
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // eax
  int v9; // eax
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax
  unsigned int AvInfo; // [esp+Ch] [ebp-4h]

  v1 = this;
  AvSendTVEncoderOption(0, 6u, 0, &AvInfo);
  v1->bWideScreen = BYTE2(AvInfo) & 1;
  GreenFog::Init(&v1->greenFog);
  v1->qrand.seed = 1985229328;
  Renderer::Init(&v1->theRenderer);
  Camera::Init(&v1->theCamera);
  VBlob::Init(&v1->vblob);
  CameraController::Init(&v1->camController);
  v1->fIIDT = 0.0;
  v1->bLoop = 0;
  v1->bPaused = 0;
  v1->fBaseBlobIntensity = 0.0;
  v1->bActive = 0;
  v1->bCameraUnderControl = 1;
  v1->bUserControlledIntensity = 0;
  v1->fBlobIntensity = 0.0;
  v1->appSpeedId = 0;
  v1->fSmoothedBlobIntensity = 0.0;
  if ( g_bShortVersion )
    v1->fTimeElapsed = 7.5;
  else
    v1->fTimeElapsed = 0.0;
  v1->bSceneShadowsOn = 1;
  v1->fCamPhi = 0.0;
  v1->bFogOn = 1;
  v1->fCamRad = 90.0;
  v1->fCamTheta = 3.1415927;
  v2 = v1->fCamRad;
  v1->fCamRad = v1->fSavedCamRad;
  v1->fSavedCamRad = v2;
  v3 = v1->fCamTheta;
  v1->fCamTheta = v1->fSavedCamTheta;
  v1->fSavedCamTheta = v3;
  v4 = v1->fCamPhi;
  v1->fCamPhi = v1->fSavedCamPhi;
  v1->fSavedCamPhi = v4;
  memset(&v1->blobLight, 0, sizeof(v1->blobLight));
  v5 = &v1->blobLight.Position.x;
  *v5 = 0.0;
  v5[1] = 0.0;
  v5[2] = 0.0;
  v6 = &v1->blobLight.Ambient.r;
  *v6 = 0.0;
  v6[1] = 0.0;
  v6[2] = 0.0;
  v6[3] = 1.0;
  v7 = &v1->blobLight.Diffuse.r;
  *v7 = 0.13;
  v7[1] = 0.13;
  v7[2] = 0.13;
  v7[3] = 1.0;
  v8 = &v1->blobLight.Specular.r;
  *v8 = 1.0;
  v8[1] = 1.0;
  v8[2] = 1.0;
  v8[3] = 1.0;
  v1->blobLight.Attenuation0 = 1.0;
  v1->blobLight.Attenuation1 = 0.001;
  v1->blobLight.Attenuation2 = 0.001;
  memset(&v1->moodLight, 0, sizeof(v1->moodLight));
  v9 = (int)&v1->moodLight.Position;
  *(_DWORD *)(v9 + 4) = -1038090240;
  *(_DWORD *)(v9 + 8) = 1106247680;
  *(float *)v9 = 0.0;
  v10 = &v1->moodLight.Ambient.r;
  *v10 = 0.0;
  v10[1] = 0.0;
  v10[2] = 0.0;
  v10[3] = 1.0;
  v11 = &v1->moodLight.Diffuse.r;
  *v11 = 0.25;
  v11[1] = 0.25;
  v11[2] = 0.25;
  v11[3] = 1.0;
  v12 = &v1->moodLight.Specular.r;
  *v12 = 0.75;
  v12[1] = 0.75;
  v12[2] = 0.75;
  v12[3] = 1.0;
  v1->pNormalCubeMapLoRes = 0;
  v1->moodLight.Attenuation0 = 1.0;
  v1->pNormalCubeMapHiRes = 0;
  v1->pRoughBumpMap = 0;
  v1->pStaticReflectionCubeMap = 0;
  v1->pGlowMap = 0;
  v1->moodLight.Attenuation1 = 0.001;
  v1->moodLight.Attenuation2 = 0.001;
}