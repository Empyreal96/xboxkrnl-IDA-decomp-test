const char *__userpurge XBoxStartupApp::loadPixelShader@<eax>(XBoxStartupApp *this@<ecx>, int *a2@<edi>, const char *pb)
{
  D3DDevice_CreatePixelShader(a2, (_D3DPixelShaderDef *)(pb + 4), (unsigned int *)&pb);
  return pb;
}