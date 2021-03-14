void __thiscall XBoxStartupApp::advanceTime(XBoxStartupApp *this, float dt, float cam_dt)
{
  XBoxStartupApp *v3; // esi
  bool v4; // zf
  double v5; // st7
  float et; // ST18_4
  double v7; // st7
  bool v8; // al
  double v9; // st7
  double v10; // st7
  float x; // ST10_4
  double v12; // st7
  float t; // ST00_4
  double v14; // st7
  float v15; // ST10_4
  float v16; // ST10_4
  double v17; // st7
  float v18; // ST10_4
  double v19; // st6
  double v20; // st5
  double v21; // st7
  double v22; // st6
  float v23; // eax
  _D3DMATRIX matX; // [esp+20h] [ebp-FCh]
  _D3DMATRIX matZ; // [esp+60h] [ebp-BCh]
  _D3DMATRIX matRot; // [esp+A0h] [ebp-7Ch]
  _D3DVECTOR tmp; // [esp+E0h] [ebp-3Ch]
  _D3DVECTOR up; // [esp+ECh] [ebp-30h]
  _D3DVECTOR look; // [esp+F8h] [ebp-24h]
  float s; // [esp+104h] [ebp-18h]
  float c; // [esp+108h] [ebp-14h]
  _D3DVECTOR pos; // [esp+10Ch] [ebp-10h]
  float old_theta; // [esp+118h] [ebp-4h]

  v3 = this;
  if ( dt > 1.0 )
    dt = 0.001;
  v4 = this->bUserControlledIntensity == 0;
  v5 = dt + this->fTimeElapsed;
  this->fTimeElapsed = v5;
  if ( v4 )
  {
    if ( v5 >= 1.1 )
      this->fBaseBlobIntensity = ((v5 - 1.1) * 0.24390244 + 1.0) * ((v5 - 1.1) * 0.24390244) * 0.5;
    else
      this->fBaseBlobIntensity = 0.0;
    et = v5;
    v7 = XBoxStartupApp::sumIntensityPulses(this, et) + this->fBaseBlobIntensity;
    v3->fBlobIntensity = v7;
    v3->fSmoothedBlobIntensity = (1.0 - dt * 0.5) * v3->fSmoothedBlobIntensity + v7 * (dt * 0.5);
    v3->fIIDT = v7 * dt + v3->fIIDT;
  }
  if ( v3->fTimeElapsed >= 8.0 )
  {
    if ( !v3->bLoop )
      return;
    put_fifo(1);
    v8 = v3->bUserControlledIntensity;
    v3->fIIDT = 0.0;
    if ( !v8 )
    {
      v3->fBaseBlobIntensity = 0.0;
      v3->fBlobIntensity = 0.0;
      v3->fSmoothedBlobIntensity = 0.0;
    }
    if ( g_bShortVersion )
      v3->fTimeElapsed = 7.5;
    else
      v3->fTimeElapsed = 0.0;
    if ( !v8 )
    {
      XBoxStartupApp::initIntensityPulses(v3);
      VBlob::restart(&v3->vblob);
      GreenFog::restart(&v3->greenFog);
      CameraController::pickPath(&v3->camController, -1);
    }
  }
  if ( !v3->bCameraUnderControl )
  {
    if ( v3->fCamPhi > 1.5707964 )
      v3->fCamPhi = 1.5707964;
    if ( v3->fCamPhi < -1.5707964 )
      v3->fCamPhi = -1.5707964;
    v9 = 10.0;
    if ( v3->fCamRad > 10.0 )
      v9 = v3->fCamRad;
    v3->fCamRad = v9;
  }
  SetXRotation(v3->fCamPhi, &matRot);
  SetZRotation(v3->fCamTheta, &matRot);
  v4 = v3->bCameraUnderControl == 0;
  look.x = 0.0;
  look.y = 0.0;
  v3->bRenderGeom = 1;
  v3->bRenderSlash = 0;
  look.z = 0.0;
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  if ( v4 )
  {
    SetXRotation(v3->fCamPhi, &matX);
    SetZRotation(v3->fCamTheta, &matZ);
    MulMats(&matX, &matZ, &matRot);
    v23 = v3->fCamRad;
    tmp.x = 0.0;
    tmp.y = v23;
    tmp.z = -10.0;
    TransformVector(&tmp, &matRot, &pos);
  }
  else
  {
    old_theta = v3->fTimeElapsed * v3->fTimeElapsed * 0.16666667 * 0.80000001;
    v10 = v3->fTimeElapsed * 0.28330001;
    if ( v10 > 1.5707964 )
      v10 = 1.5707964;
    x = v10;
    v12 = fast_sin(x);
    t = v12 * v3->fTimeElapsed * 0.2 + old_theta;
    CameraController::getPosition(&v3->camController, t, &pos, &look, &v3->bRenderGeom, &v3->bRenderSlash);
    v14 = Length(&pos);
    v3->fCamRad = v14;
    v15 = pos.z * (1.0 / v14);
    v3->fCamPhi = fast_asin(v15);
    v16 = pos.y * pos.y + pos.x * pos.x;
    v17 = 1.0 / fast_sqrt(v16);
    old_theta = v3->fCamTheta;
    c = pos.x * v17;
    s = pos.y * v17;
    v3->fCamTheta = AngleFromSinCos(&s, &c);
    if ( fast_fabs(old_theta) < 1000.0 )
    {
      v18 = v3->fCamTheta - old_theta;
      if ( fast_fabs(v18) > 3.1415927 )
      {
        v19 = old_theta - 3.1415927;
        if ( v19 > v3->fCamTheta )
        {
          v20 = v3->fCamTheta;
          do
            v20 = v20 + 6.2831855;
          while ( v19 > v20 );
          v3->fCamTheta = v20;
        }
        v21 = old_theta + 3.1415927;
        if ( v21 < v3->fCamTheta )
        {
          v22 = v3->fCamTheta;
          do
            v22 = v22 - 6.2831855;
          while ( v21 < v22 );
          v3->fCamTheta = v22;
        }
      }
    }
  }
  Camera::lookAt(&v3->theCamera, &pos, &look, &up);
  v3->fCamRadBlob = Distance(&v3->vblob.m_Pos, &pos);
  if ( v3->bRenderGeom )
  {
    SceneRenderer::advanceTime(&v3->sceneGeom, v3->fTimeElapsed, dt);
    VBlob::advanceTime(&v3->vblob, v3->fTimeElapsed, dt);
    if ( v3->bSceneShadowsOn )
      SceneRenderer::updateShadows(&v3->sceneGeom);
    if ( v3->bFogOn )
      GreenFog::advanceTime(&v3->greenFog, (int *)&v3->sceneGeom, v3->fTimeElapsed, dt);
  }
  if ( v3->bRenderSlash )
    LogoRenderer::advanceTime(&v3->logoGeom, v3->fTimeElapsed, dt);
}