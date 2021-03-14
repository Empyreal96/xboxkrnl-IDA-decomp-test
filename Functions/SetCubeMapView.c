void __stdcall SetCubeMapView(unsigned int dwFace, _D3DVECTOR *pos, _D3DMATRIX *pres)
{
  double v3; // st7
  double v4; // st7
  _D3DVECTOR lookat; // [esp+0h] [ebp-24h]
  _D3DVECTOR up; // [esp+Ch] [ebp-18h]
  _D3DVECTOR look; // [esp+18h] [ebp-Ch]

  switch ( dwFace )
  {
    case 0u:
      look.x = 1.0;
      goto LABEL_13;
    case 1u:
      look.x = -1.0;
LABEL_13:
      look.y = 0.0;
      v3 = 0.0;
      goto LABEL_14;
    case 2u:
      up.z = -1.0;
      look.x = 0.0;
      look.y = 1.0;
      look.z = 0.0;
      up.x = 0.0;
      up.y = 0.0;
      break;
    case 3u:
      look.y = -1.0;
      look.x = 0.0;
      look.z = 0.0;
      up.x = 0.0;
      up.y = 0.0;
      v4 = 1.0;
LABEL_16:
      up.z = v4;
      break;
    case 4u:
      look.x = 0.0;
      look.y = 0.0;
      v3 = 1.0;
LABEL_14:
      look.z = v3;
      goto LABEL_15;
    case 5u:
      look.z = -1.0;
      look.x = 0.0;
      look.y = 0.0;
LABEL_15:
      up.x = 0.0;
      up.y = 1.0;
      v4 = 0.0;
      goto LABEL_16;
  }
  Add(pos, &look, &lookat);
  SetLookAt(pos, &lookat, &up, pres);
}