void __thiscall XBoxStartupApp::drawFrame(XBoxStartupApp *this)
{
  XBoxStartupApp *v1; // esi
  bool v2; // cl
  bool b_render_fog; // [esp+17h] [ebp-1h]

  v1 = this;
  D3DDevice_Clear(0, 0, 0xF3u, 0xFF000000, 1.0, 0);
  if ( v1->bRenderGeom )
  {
    if ( v1->fBlobIntensity > 0.0 )
      SceneRenderer::render(&v1->sceneGeom, v1->bSceneShadowsOn, 1);
    if ( v1->fTimeElapsed >= 0.60000002 )
      VBlob::render(&v1->vblob);
  }
  v2 = v1->bRenderGeom;
  b_render_fog = v2 && v1->bFogOn && (v1->fBlobIntensity > 0.0 || v1->fTimeElapsed < 0.60000002);
  if ( v1->bRenderSlash )
  {
    if ( b_render_fog || v2 )
      D3DDevice_Clear(0, 0, 3u, 0xFF000000, 1.0, 0);
    LogoRenderer::render(&v1->logoGeom, (int *)0xFF000000, &v1->camController.xfSlash, 0);
  }
  if ( b_render_fog )
    GreenFog::render(&v1->greenFog, (int *)0xFF000000, v1->bRenderSlash);
  D3DDevice_Present(0, 0, 0, 0);
}