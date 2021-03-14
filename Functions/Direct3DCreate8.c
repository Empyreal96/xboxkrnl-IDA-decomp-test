Direct3D *__userpurge Direct3DCreate8@<eax>(int *a1@<edi>, unsigned int SDKVersion)
{
  if ( !SDKVersion )
    return (Direct3D *)1;
  D3DK::DXGRIP(
    a1,
    "\n"
    "D3D ERROR: This application compiled against improper D3D headers.\n"
    "D3D_SDK_VERSION is (%d) but should be (%d).\n"
    "Please recompile with an up-to-date SDK.\n"
    "\n",
    SDKVersion,
    0);
  return 0;
}