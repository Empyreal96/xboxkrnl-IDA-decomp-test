void __stdcall SetQuatFromAxis(_D3DVECTOR *axis, float angle, D3DVECTOR4 *pres)
{
  D3DVECTOR4 *v3; // eax
  double v4; // st7
  float c; // [esp+Ch] [ebp-8h]
  float v6; // [esp+10h] [ebp-4h]

  v6 = angle * 0.5;
  c = cos(v6);
  angle = sin(v6);
  v3 = pres;
  pres->x = angle * axis->x;
  v3->y = angle * axis->y;
  v4 = angle * axis->z;
  v3->w = c;
  v3->z = v4;
}