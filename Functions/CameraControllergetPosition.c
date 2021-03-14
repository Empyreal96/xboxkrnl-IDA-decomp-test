void __thiscall CameraController::getPosition(CameraController *this, float t, _D3DVECTOR *p_pos, _D3DVECTOR *p_look, bool *pb_render_geom, bool *pb_render_slash)
{
  CameraController *v6; // ebx
  float *v7; // esi
  _D3DVECTOR *v8; // edi
  float *v9; // esi
  _D3DVECTOR *v10; // edi
  int v11; // esi
  int v12; // edi
  bool v13; // zf
  CamControlNode *v14; // eax
  _D3DVECTOR *v15; // eax
  _D3DVECTOR *v16; // eax
  CamControlNode *v17; // esi
  CamControlNode *v18; // ebx
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st6
  double v23; // st5
  _D3DVECTOR *v24; // eax
  double v25; // st5
  double v26; // st4
  float s; // ST18_4
  double v28; // st5
  double v29; // st7
  double v30; // st6
  double v31; // st5
  double v32; // st4
  _D3DVECTOR *v33; // edx
  CameraController *v34; // eax
  double v35; // st7
  float scale; // ST08_4
  CameraController *v37; // esi
  float _sin; // [esp+14h] [ebp-14h]
  float v39; // [esp+18h] [ebp-10h]
  float v40; // [esp+1Ch] [ebp-Ch]
  CameraController *v41; // [esp+20h] [ebp-8h]
  float sss; // [esp+24h] [ebp-4h]

  v6 = this;
  v41 = this;
  if ( t > 6.0 )
  {
    v7 = &this->finishNodes[7].ptPosition.x;
LABEL_3:
    v8 = p_pos;
    p_pos->x = *v7;
    v9 = v7 + 1;
    v8 = (_D3DVECTOR *)((char *)v8 + 4);
    v8->x = *v9;
    v8->y = v9[1];
    v10 = p_look;
    p_look->x = v6->ptFinalLookAt.x;
    v10 = (_D3DVECTOR *)((char *)v10 + 4);
    v10->x = v6->ptFinalLookAt.y;
    v10->y = v6->ptFinalLookAt.z;
LABEL_12:
    *pb_render_slash = 1;
    *pb_render_geom = 0;
    return;
  }
  v11 = this->curNumNodes;
  v12 = 1;
  v13 = v11 == 1;
  if ( v11 > 1 )
  {
    do
    {
      v14 = CameraController::getNode(v6, v12);
      if ( v14->fTime > (double)t )
        break;
      ++v12;
    }
    while ( v12 < v11 );
    v13 = v12 == v11;
  }
  if ( v13 )
  {
    v7 = &CameraController::getNode(v6, v11 - 1)->ptPosition.x;
    goto LABEL_3;
  }
  if ( !v12 )
  {
    v15 = p_pos;
    p_pos->x = 0.0;
    v15->y = -90.0;
    v15->z = 0.0;
    v16 = p_look;
    p_look->x = 0.0;
    v16->y = 0.0;
    v16->z = 0.0;
    goto LABEL_12;
  }
  v17 = CameraController::getNode(v6, v12 - 1);
  v18 = CameraController::getNode(v6, v12);
  v19 = v18->fTime - v17->fTime;
  if ( v19 >= 0.001 )
    sss = v19;
  else
    sss = 0.001;
  if ( v12 < 2 )
    v20 = sss;
  else
    v20 = v17->fTime - CameraController::getNode(v41, v12 - 2)->fTime;
  if ( v20 >= 0.001 )
  {
    if ( v12 < 2 )
      v21 = sss;
    else
      v21 = v17->fTime - CameraController::getNode(v41, v12 - 2)->fTime;
  }
  else
  {
    v21 = 0.001;
  }
  v22 = t - v17->fTime;
  v23 = v22 / sss;
  if ( v23 < 0.0 || v23 <= 1.0 )
  {
    if ( v23 < 0.0 )
      v23 = 0.0;
  }
  else
  {
    v23 = 1.0;
  }
  v24 = p_pos;
  v25 = 3.0 * (v23 * v23) - (v23 * v23 * v23 + v23 * v23 * v23);
  v26 = v22 / ((1.0 - v25) * v21 + v25 * sss);
  s = v26;
  v40 = v26 * v26;
  v28 = v26 * v26 * v26;
  sss = v28;
  _sin = v28 + v28;
  v39 = v26 * v26 * 3.0;
  v29 = _sin - v39 + 1.0;
  v30 = sss - (v40 + v40) + s;
  v31 = sss - v40;
  v32 = v39 - _sin;
  p_pos->x = v32 * v18->ptPosition.x + v31 * v18->vecVelocity.x + v30 * v17->vecVelocity.x + v29 * v17->ptPosition.x;
  v24->y = v32 * v18->ptPosition.y + v31 * v18->vecVelocity.y + v30 * v17->vecVelocity.y + v29 * v17->ptPosition.y;
  v33 = p_look;
  v24->z = v32 * v18->ptPosition.z + v31 * v18->vecVelocity.z + v30 * v17->vecVelocity.z + v29 * v17->ptPosition.z;
  v34 = v41;
  v33->x = v32 * v18->vecLookAt.x + v31 * v18->vecLookAtW.x + v30 * v17->vecLookAtW.x + v29 * v17->vecLookAt.x;
  v33->y = v32 * v18->vecLookAt.y + v31 * v18->vecLookAtW.y + v30 * v17->vecLookAtW.y + v29 * v17->vecLookAt.y;
  v33->z = v32 * v18->vecLookAt.z + v31 * v18->vecLookAtW.z + v30 * v17->vecLookAtW.z + v29 * v17->vecLookAt.z;
  v35 = (t - v34->fCameraLookatInterpStart) * v34->fOOCameraLookatInterpDelta;
  if ( v35 > 1.0 || v35 >= 0.0 )
  {
    if ( v35 > 1.0 )
      v35 = 1.0;
  }
  else
  {
    v35 = 0.0;
  }
  v39 = COERCE_FLOAT(&t);
  *(float *)&p_pos = v35 * 3.1415927;
  v40 = COERCE_FLOAT(&p_pos);
  t = cos(*(float *)&p_pos);
  _sin = sin(*(float *)&p_pos);
  *(float *)&p_pos = (1.0 - t) * 0.5;
  scale = 1.0 - *(float *)&p_pos;
  Scale(v33, scale);
  v37 = v41;
  AddScaled(p_look, &v41->ptFinalLookAt, *(float *)&p_pos);
  *pb_render_slash = v12 > v37->curVariableNodes - 1;
  *pb_render_geom = v12 < v37->curNumNodes - 1;
}