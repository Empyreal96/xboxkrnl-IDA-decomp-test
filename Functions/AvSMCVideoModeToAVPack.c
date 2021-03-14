unsigned int __stdcall AvSMCVideoModeToAVPack(unsigned int VideoMode)
{
  switch ( VideoMode )
  {
    case 0u:
      return 3;
    case 1u:
      return 4;
    case 2u:
      return 5;
    case 3u:
      return 2;
  }
  if ( VideoMode != 4 )
    return VideoMode == 6;
  return 6;
}