_D3DFORMAT __stdcall D3DK::MapToLinearD3DFORMAT(_D3DFORMAT Format)
{
  _D3DFORMAT result; // eax

  result = Format;
  switch ( Format )
  {
    case 2u:
      result = 16;
      break;
    case 3u:
      result = 28;
      break;
    case 5u:
      result = 17;
      break;
    case 6u:
      result = 18;
      break;
    case 7u:
      result = 30;
      break;
    case 0x2Au:
      result = 46;
      break;
    case 0x2Bu:
      result = 47;
      break;
    case 0x2Cu:
      result = 48;
      break;
    case 0x2Du:
      result = 49;
      break;
    default:
      return result;
  }
  return result;
}