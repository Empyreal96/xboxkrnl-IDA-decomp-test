const char *__stdcall XBoxStartupApp::loadVertexShader(const char *pb, const unsigned int *pdwDecl)
{
  D3DDevice_CreateVertexShader(pdwDecl, (const unsigned int *)pb, (unsigned int *)&pb, 0);
  return pb;
}