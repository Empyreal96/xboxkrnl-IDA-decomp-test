unsigned int __stdcall AvpQueryAvCapabilities()
{
  unsigned int v0; // edi
  int v1; // edx
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // edi
  unsigned int Type; // [esp+4h] [ebp-Ch]
  unsigned int ResultLength; // [esp+8h] [ebp-8h]
  unsigned int VideoMode; // [esp+Ch] [ebp-4h]

  v0 = AvSMCVideoModeToAVPack(HalBootSMCVideoMode);
  if ( ExQueryNonVolatileSetting(v2, v1, 0x103u, &Type, &VideoMode, 4u, &ResultLength) || ResultLength != 4 )
  {
    v5 = 4194560;
    VideoMode = 4194560;
  }
  else
  {
    v5 = VideoMode;
  }
  v6 = v5 & 0xC0FF00 | v0;
  if ( ExQueryNonVolatileSetting(v4, v3, 8u, &Type, &VideoMode, 4u, &ResultLength) || ResultLength != 4 )
    VideoMode = 0;
  return v6 | VideoMode & 0xFFFF0000;
}