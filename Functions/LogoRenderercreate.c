void __usercall LogoRenderer::create(LogoRenderer *this@<ecx>, int *a2@<edi>, int a3@<edx>)
{
  LogoRenderer *v3; // esi
  unsigned int dwDecl[4]; // [esp+8h] [ebp-10h]

  v3 = this;
  LogoRenderer::decompressData(this, a3);
  LogoRenderer::createSlash(v3, a2);
  LogoRenderer::createText(v3);
  LogoRenderer::createTMs(v3);
  v3->pSlashTexture = 0;
  dwDecl[3] = -1;
  v3->dwInteriorPShader = (unsigned int)XBoxStartupApp::loadPixelShader(&gApp, &gApp.nWidth, g_slash_interior_xpu);
  dwDecl[0] = 0x20000000;
  dwDecl[1] = 1077018624;
  dwDecl[2] = 1075970049;
  v3->dwInteriorVShader = (unsigned int)XBoxStartupApp::loadVertexShader(g_slash_interior_xvu, dwDecl);
}