BOOL __thiscall VBloblet::update(VBloblet *this, float elapsed_time, float dt)
{
  VBloblet *v3; // ebx
  double v4; // st7
  bool v5; // c0
  bool v6; // c3
  double v7; // st7
  float x; // ST08_4
  double v9; // st7
  float v10; // ST08_4
  double v11; // st7
  double v12; // st7
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c2
  float v16; // ST08_4
  float time_prog; // [esp+10h] [ebp-4h]
  float s; // [esp+1Ch] [ebp+8h]
  float dta; // [esp+20h] [ebp+Ch]
  float dtb; // [esp+20h] [ebp+Ch]

  v3 = this;
  v4 = dt * this->fWobbleDirection + this->fWobble;
  if ( v4 < 0.5 || v4 <= 2.0 )
  {
    if ( v4 < 0.5 )
      v4 = 0.5;
  }
  else
  {
    v4 = 2.0;
  }
  this->fWobble = v4;
  if ( this->fWobbleDirection <= 0.0 )
  {
    if ( v4 >= 1.0 )
    {
      v5 = v4 < 1.05;
      v6 = v4 == 1.05;
LABEL_11:
      if ( v5 || v6 )
        goto LABEL_13;
      goto LABEL_12;
    }
  }
  else if ( v4 >= 0.94999999 )
  {
    v5 = v4 < 1.0;
    v6 = v4 == 1.0;
    goto LABEL_11;
  }
LABEL_12:
  this->fWobbleDirection = this->fWobbleDirection - (v4 - 1.0) * dt * 1000.0;
LABEL_13:
  v7 = (elapsed_time - 0.60000002) * 0.24390244;
  if ( v7 < 0.0 )
    v7 = 0.0;
  time_prog = v7;
  x = (elapsed_time - this->fStartTime) * this->fTimeMultiple * (elapsed_time * 0.1 + 1.0) * 1.4;
  v9 = fast_sin(x);
  s = v9;
  v10 = v9;
  dta = 1.0 - fast_fabs(v10);
  v11 = 1.0 - fast_sqrt(dta) * dta;
  if ( s <= 0.0 )
    v11 = -v11;
  v12 = v11 * v3->fMaxDist * time_prog;
  v3->fCurDist = v12;
  v3->bFarSide = (v14 | v15) != 0;
  v3->vPosition.x = gpVBlob->m_Pos.x;
  v3->vPosition.y = gpVBlob->m_Pos.y;
  v16 = v12;
  v3->vPosition.z = gpVBlob->m_Pos.z;
  AddScaled(&v3->vPosition, &v3->vDirection, v16);
  dtb = gpVBlob->m_fRadius;
  return dtb * 0.5 > fast_fabs(v3->fCurDist) + v3->fRadius;
}