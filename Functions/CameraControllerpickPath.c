void __thiscall CameraController::pickPath(CameraController *this, int path)
{
  int v2; // edx
  CameraController *v3; // ebx
  int v4; // ecx
  int v5; // esi
  int v6; // ecx
  int v7; // ecx
  CamControlNode *v8; // edx
  int v9; // eax
  float *v10; // eax
  double v11; // st7
  double v12; // st7
  signed int v13; // eax
  __m128 **v14; // ecx
  double v15; // st6
  int v16; // esi
  int v17; // edi
  _D3DVECTOR *v18; // ST04_4
  CamControlNode *v19; // eax
  CamControlNode *v20; // edi
  float s; // ST08_4
  float v22; // ST08_4
  float v23; // ST08_4
  double v24; // st7
  float v25; // ST08_4
  float *v26; // edi
  float v27; // ST08_4
  float v28; // ST08_4
  _D3DVECTOR *v29; // esi
  signed int v30; // edi
  CamControlNode *v31; // esi
  _D3DVECTOR *v32; // edi
  float *v33; // eax
  CamControlNode *v34; // eax
  float v35; // ST08_4
  CamControlNode *v36; // eax
  float v37; // ST08_4
  CamControlNode *v38; // eax
  float v39; // ST08_4
  CamControlNode *v40; // eax
  float v41; // ST08_4
  const float cfZPositions[8]; // [esp+10h] [ebp-68h]
  const float cfYPositions[8]; // [esp+30h] [ebp-48h]
  _D3DVECTOR delta; // [esp+50h] [ebp-28h]
  _D3DVECTOR up; // [esp+5Ch] [ebp-1Ch]
  _D3DVECTOR y_dir; // [esp+68h] [ebp-10h]
  _D3DVECTOR *ptarget; // [esp+74h] [ebp-4h]
  CamControlNode *slash_y_offset; // [esp+80h] [ebp+8h]
  signed int slash_y_offseta; // [esp+80h] [ebp+8h]
  __m128 **slash_y_offsetb; // [esp+80h] [ebp+8h]
  float slash_y_offsete; // [esp+80h] [ebp+8h]
  float slash_y_offsetc; // [esp+80h] [ebp+8h]
  int slash_y_offsetd; // [esp+80h] [ebp+8h]

  v2 = path;
  v3 = this;
  if ( path < 0 )
    v2 = QRand::Rand(&stru_8010BD4C) & 0x7FFFFFFF;
  v4 = v3->numPaths;
  if ( v2 >= v4 )
    v2 %= v4;
  v5 = v3->numNodes;
  v6 = 0;
  v3->curPathNum = v2;
  if ( v5 > 0 )
  {
    slash_y_offset = CameraController::svCameraList;
    do
    {
      if ( slash_y_offset->fTime == 0.0 )
      {
        if ( !v2 )
          break;
        --v2;
      }
      ++slash_y_offset;
      ++v6;
    }
    while ( v6 < v3->numNodes );
  }
  v3->curStartNode = v6;
  v7 = v6 + 1;
  if ( v7 < v5 )
  {
    v8 = &CameraController::svCameraList[v7];
    do
    {
      if ( v8->fTime == 0.0 )
        break;
      ++v7;
      ++v8;
    }
    while ( v7 < v3->numNodes );
  }
  v9 = v7 - v3->curStartNode;
  v3->curVariableNodes = v9;
  slash_y_offseta = 0;
  v3->curNumNodes = v9 + 8;
  v10 = &v3->finishNodes[0].bias;
  do
  {
    v11 = (double)slash_y_offseta++;
    *(v10 - 14) = v11 * 0.11428571 + 5.1999998;
    *(v10 - 1) = 0.0;
    *v10 = 0.0;
    v10 += 15;
  }
  while ( slash_y_offseta < 8 );
  v12 = v3->finishNodes[2].fTime;
  v13 = v3->curVariableNodes;
  v3->fCameraLookatInterpStart = v3->finishNodes[2].fTime;
  v15 = 1.0 / (v3->finishNodes[5].fTime - v12);
  slash_y_offsetb = &pam_1p5 + 15 * (v13 + v3->curStartNode);
  v14 = &pam_1p5 + 15 * (v13 + v3->curStartNode);
  cfYPositions[0] = 95.0;
  cfYPositions[1] = 30.548;
  cfYPositions[2] = -70.819;
  cfYPositions[3] = -150.298;
  cfYPositions[4] = -220.64;
  cfYPositions[5] = -243.021;
  cfYPositions[6] = -261.44101;
  cfYPositions[7] = -287.77301;
  cfZPositions[1] = 0.322;
  cfZPositions[2] = 1.821;
  cfZPositions[3] = 2.323;
  cfZPositions[4] = -11.926;
  cfZPositions[5] = -39.973;
  cfZPositions[6] = -60.773998;
  cfZPositions[7] = -90.794998;
  v3->fOOCameraLookatInterpDelta = v15;
  LODWORD(v3->finishNodes[0].ptPosition.x) = v14[1];
  LODWORD(v3->finishNodes[0].ptPosition.y) = v14[2];
  LODWORD(v3->finishNodes[0].ptPosition.z) = v14[3];
  if ( v13 < 2 )
  {
    y_dir.x = 0.0;
    y_dir.y = 0.0;
    y_dir.z = 0.0;
  }
  else
  {
    v16 = v13 - 2;
    v17 = v13 - 1;
    v18 = &CameraController::getNode(v3, v13 - 2)->ptPosition;
    v19 = CameraController::getNode(v3, v17);
    Sub(&v19->ptPosition, v18, &y_dir);
    v20 = CameraController::getNode(v3, v17);
    s = 1.0 / (v20->fTime - CameraController::getNode(v3, v16)->fTime);
    Scale(&y_dir, s);
    v14 = slash_y_offsetb;
  }
  v22 = (v3->finishNodes[0].fTime - *(float *)v14) * 0.69999999;
  AddScaled(&v3->finishNodes[0].ptPosition, &y_dir, v22);
  slash_y_offsete = Length(&v3->finishNodes[0].ptPosition);
  v23 = 1.0 / slash_y_offsete;
  Scale(&v3->finishNodes[0].ptPosition, v23);
  delta.x = v3->finishNodes[0].ptPosition.x;
  v24 = slash_y_offsete * 1.2 - -95.0;
  delta.y = v3->finishNodes[0].ptPosition.y;
  delta.z = v3->finishNodes[0].ptPosition.z;
  if ( v24 >= 195.0 )
    slash_y_offsetc = v24;
  else
    slash_y_offsetc = 195.0;
  v25 = slash_y_offsetc - 95.0;
  Scale(&v3->finishNodes[0].ptPosition, v25);
  v3->finishNodes[0].vecLookAt.x = 0.0;
  v3->finishNodes[0].vecLookAt.y = 0.0;
  y_dir.x = delta.x;
  y_dir.y = delta.y;
  v3->finishNodes[0].vecLookAt.z = 0.0;
  up.x = 0.0;
  up.y = 0.0;
  up.z = 1.0;
  y_dir.x = y_dir.x * -1.0;
  y_dir.y = y_dir.y * -1.0;
  y_dir.z = delta.z * -1.0;
  Cross(&y_dir, &up, &delta);
  Normalize(&delta);
  Cross(&delta, &y_dir, &up);
  SetIdentity(&v3->xfSlash);
  v3->xfSlash._11 = delta.x;
  v26 = &v3->xfSlash._12;
  *v26 = delta.y;
  v26[1] = delta.z;
  *(_D3DVECTOR *)&v3->xfSlash.m[1][0] = y_dir;
  *(_D3DVECTOR *)&v3->xfSlash.m[2][0] = up;
  *(_D3DVECTOR *)&v3->xfSlash.m[3][0] = y_dir;
  v27 = -slash_y_offsetc;
  Scale((_D3DVECTOR *)v3->xfSlash.m[3], v27);
  v3->ptSlashCenter = y_dir;
  v28 = -132.14 - slash_y_offsetc;
  Scale(&v3->ptSlashCenter, v28);
  v29 = &v3->finishNodes[0].ptPosition;
  v30 = 0;
  delta.x = 0.0;
  do
  {
    v29 += 5;
    delta.y = cfYPositions[v30 + 1] + 132.14;
    delta.z = cfZPositions[v30 + 1];
    TransformVector(&delta, &v3->xfSlash, v29);
    Add(v29, &v3->ptSlashCenter, v29);
    v29[2].x = 0.0;
    ++v30;
    v29[2].y = 0.0;
    v29[2].z = 0.0;
  }
  while ( v30 < 7 );
  delta.x = 0.0;
  delta.y = 132.14;
  delta.z = 25.0;
  TransformVector(&delta, &v3->xfSlash, &v3->ptFinalLookAt);
  Add(&v3->ptFinalLookAt, &v3->ptSlashCenter, &v3->ptFinalLookAt);
  for ( slash_y_offsetd = 0; slash_y_offsetd < v3->curNumNodes; ++slash_y_offsetd )
  {
    v31 = CameraController::getNode(v3, slash_y_offsetd);
    v32 = &v31->vecVelocity;
    v32->x = 0.0;
    v33 = &v31->vecLookAtW.x;
    ptarget = &v31->vecLookAtW;
    v32->y = 0.0;
    v32->z = 0.0;
    *v33 = 0.0;
    v33[1] = 0.0;
    v33[2] = 0.0;
    if ( slash_y_offsetd )
    {
      v34 = CameraController::getNode(v3, slash_y_offsetd - 1);
      Sub(&v31->ptPosition, &v34->ptPosition, &delta);
      v35 = (1.0 - v31->tension) * (v31->bias + 1.0) * 0.5;
      AddScaled(v32, &delta, v35);
      v36 = CameraController::getNode(v3, slash_y_offsetd - 1);
      Sub(&v31->vecLookAt, &v36->vecLookAt, &delta);
      v37 = (1.0 - v31->tension) * (v31->bias + 1.0) * 0.5;
      AddScaled(ptarget, &delta, v37);
    }
    if ( slash_y_offsetd < v3->curNumNodes - 1 )
    {
      v38 = CameraController::getNode(v3, slash_y_offsetd + 1);
      Sub(&v38->ptPosition, &v31->ptPosition, &up);
      v39 = (1.0 - v31->tension) * (1.0 - v31->bias) * 0.5;
      AddScaled(v32, &up, v39);
      v40 = CameraController::getNode(v3, slash_y_offsetd + 1);
      Sub(&v40->vecLookAt, &v31->vecLookAt, &up);
      v41 = (1.0 - v31->tension) * (1.0 - v31->bias) * 0.5;
      AddScaled(ptarget, &up, v41);
    }
  }
}