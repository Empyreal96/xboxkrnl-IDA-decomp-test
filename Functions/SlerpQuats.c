void __stdcall SlerpQuats(D3DVECTOR4 *q0, D3DVECTOR4 *q1, float t, D3DVECTOR4 *pres)
{
  D3DVECTOR4 *v4; // ebx
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  float a; // ST00_4
  double v10; // st6
  float b; // ST04_4
  float v12; // ST04_4
  double v13; // st7
  D3DVECTOR4 *v14; // esi
  double v15; // st7
  float _q1; // [esp+14h] [ebp-10h]
  float _q1_4; // [esp+18h] [ebp-Ch]
  float _q1_8; // [esp+1Ch] [ebp-8h]
  float _q1_12; // [esp+20h] [ebp-4h]
  float angle; // [esp+2Ch] [ebp+8h]
  float anglea; // [esp+2Ch] [ebp+8h]
  float t0; // [esp+30h] [ebp+Ch]

  v4 = q0;
  v5 = DotQuats(q0, q1);
  angle = v5;
  _q1 = q1->x;
  _q1_4 = q1->y;
  _q1_8 = q1->z;
  _q1_12 = q1->w;
  if ( v7 | v8 )
  {
    _q1 = -q1->x;
    _q1_4 = -q1->y;
    _q1_8 = -q1->z;
    _q1_12 = -q1->w;
    angle = -v5;
    v5 = -v5;
  }
  a = v5;
  if ( (unsigned __int8)IsEq(a, 1.0) )
  {
    v10 = 1.0 - t;
    pres->x = v10 * v4->x + _q1 * t;
    pres->y = v10 * v4->y + _q1_4 * t;
    pres->z = v10 * v4->z + _q1_8 * t;
    pres->w = v10 * v4->w + _q1_12 * t;
  }
  else
  {
    anglea = fast_acos(angle);
    b = (1.0 - t) * anglea;
    t0 = fast_sin(b);
    v12 = anglea * t;
    v13 = fast_sin(v12);
    v14 = pres;
    pres->x = t0 * v4->x + v13 * _q1;
    pres->y = t0 * v4->y + v13 * _q1_4;
    pres->z = t0 * v4->z + v13 * _q1_8;
    pres->w = t0 * v4->w + v13 * _q1_12;
    v15 = 1.0 / fast_sin(anglea);
    v14->x = v15 * v14->x;
    v14->y = v15 * v14->y;
    v14->z = v15 * v14->z;
    v14->w = v15 * v14->w;
  }
}