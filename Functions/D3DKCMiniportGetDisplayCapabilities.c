unsigned int __stdcall D3DK::CMiniport::GetDisplayCapabilities()
{
  if ( !D3D__AvInfo )
    AvSendTVEncoderOption(0, 6u, 0, &D3D__AvInfo);
  return D3D__AvInfo;
}