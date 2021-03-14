void __thiscall VBlob::getLightForPosition(VBlob *this, _D3DVECTOR *p_light_pos, float *p_intensity, _D3DVECTOR position)
{
  VBlob *v4; // esi
  _D3DVECTOR *v5; // edi
  double v6; // st7
  float scale; // ST08_4
  int v8; // eax
  _D3DVECTOR *v9; // esi
  int v10; // edi
  double v11; // st7
  float v12; // ST08_4
  double v13; // st7
  _D3DVECTOR av_pos; // [esp+Ch] [ebp-1Ch]
  float v15; // [esp+18h] [ebp-10h]
  float light_intensity; // [esp+1Ch] [ebp-Ch]
  float av_intensity; // [esp+20h] [ebp-8h]
  float weight; // [esp+24h] [ebp-4h]

  av_pos.x = 0.0;
  v4 = this;
  av_pos.y = 0.0;
  light_intensity = *(float *)qword_8010B6E0;
  v5 = &this->m_Pos;
  av_pos.z = 0.0;
  v6 = 1.0 / Distance2(&position, &this->m_Pos);
  weight = v6;
  av_intensity = 0.0 * v6 * 4.0;
  scale = v6;
  AddScaled(&av_pos, v5, scale);
  v8 = v4->m_NumBloblets;
  if ( v8 > 0 )
  {
    v9 = &v4->m_Bloblets[0].vPosition;
    v10 = v8;
    do
    {
      v11 = 1.0 / Distance2(&position, v9);
      v15 = v11;
      av_intensity = light_intensity * v11 + av_intensity;
      v12 = v11;
      AddScaled(&av_pos, v9, v12);
      v9 = (_D3DVECTOR *)((char *)v9 + 56);
      --v10;
      weight = v15 + weight;
    }
    while ( v10 );
  }
  v13 = 1.0 / weight;
  p_light_pos->x = av_pos.x * v13;
  p_light_pos->y = av_pos.y * v13;
  p_light_pos->z = av_pos.z * v13;
  *p_intensity = v13 * av_intensity;
}