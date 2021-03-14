void __thiscall LogoRenderer::advanceTime(LogoRenderer *this, float fElapsedTime, float fDt)
{
  double v3; // st7
  signed int v4; // eax
  double v5; // st7
  double v6; // st7
  double v7; // st7
  float v8; // [esp+0h] [ebp-10h]
  int pos_idx; // [esp+4h] [ebp-Ch]
  float f_pos; // [esp+8h] [ebp-8h]
  float f_norm_pos; // [esp+Ch] [ebp-4h]

  if ( fElapsedTime < 6.0 )
  {
    this->bRenderText = 0;
    v7 = 0.0;
    goto LABEL_15;
  }
  this->bRenderText = 1;
  v3 = (fElapsedTime - 6.0) * 4.0;
  v8 = v3;
  f_norm_pos = v3;
  f_pos = v3;
  pos_idx = (signed int)f_pos;
  if ( f_norm_pos <= 0.0 )
  {
    this->matText_Anim._41 = pos_anim_text[0].x;
    this->matText_Anim._42 = -267.65042;
    v4 = -1026681678;
LABEL_4:
    LODWORD(this->matText_Anim._43) = v4;
    goto LABEL_8;
  }
  if ( f_norm_pos >= 1.0 )
  {
    this->matText_Anim._41 = -0.229403;
    this->matText_Anim._42 = -141.05376;
    v4 = -1034304979;
    goto LABEL_4;
  }
  v5 = f_pos - (double)pos_idx;
  this->matText_Anim._41 = (1.0 - v5) * *(float *)(12 * pos_idx - 2146367952)
                         + v5 * *(float *)(12 * pos_idx - 2146367940);
  this->matText_Anim._42 = (1.0 - v5) * *(float *)(12 * pos_idx - 2146367948)
                         + v5 * *(float *)(12 * pos_idx - 2146367936);
  this->matText_Anim._43 = (1.0 - v5) * *(float *)(12 * pos_idx - 2146367944)
                         + v5 * *(float *)(12 * pos_idx - 2146367932);
LABEL_8:
  v6 = v8;
  this->fTMAlpha = v8;
  if ( v8 > 1.0 || v6 >= 0.0 )
  {
    if ( v6 > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = 0.0;
  }
  v7 = v6 * 255.0;
LABEL_15:
  this->fTMAlpha = v7;
  if ( fElapsedTime >= 6.0 )
    LogoRenderer::createSlashSurface(this);
}