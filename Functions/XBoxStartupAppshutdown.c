void __usercall XBoxStartupApp::shutdown(XBoxStartupApp *this@<ecx>, int *a2@<edi>)
{
  XBoxStartupApp *v2; // esi
  int v3; // edx
  int v4; // ecx

  v2 = this;
  SceneRenderer::destroy(&this->sceneGeom);
  LogoRenderer::destroy(&v2->logoGeom, a2);
  VBlob::destroy(&v2->vblob, a2);
  GreenFog::destroy(&v2->greenFog, a2);
  D3DResource_Release(a2, (D3DResource *)&v2->pNormalCubeMapLoRes->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pNormalCubeMapHiRes->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pStaticReflectionCubeMap->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pRoughBumpMap->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pGlowMap->Common);
  D3DDevice_DeleteVertexShader(v2->dwVShader[0]);
  D3DDevice_DeleteVertexShader(v2->dwVShader[1]);
  D3DDevice_DeleteVertexShader(v2->dwVShader[2]);
  D3DDevice_DeletePixelShader(v2->dwPShader[0]);
  D3DDevice_DeletePixelShader(v2->dwPShader[1]);
  D3DDevice_DeletePixelShader(v2->dwPShader[2]);
  WaitOnMicrosoftLogo(a2, v3, v4);
  Renderer::shutdown(&v2->theRenderer);
  v2->bActive = 0;
}