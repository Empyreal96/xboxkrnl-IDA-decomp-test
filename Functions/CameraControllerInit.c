void __thiscall CameraController::Init(CameraController *this)
{
  int v1; // ebx
  float *v2; // edx
  CamControlNodeData *v3; // eax
  double v4; // st6
  signed int v5; // ST10_4
  signed int v6; // esi

  v1 = 0;
  this->curPathNum = -1;
  this->numNodes = 21;
  this->numPaths = 0;
  v2 = &CameraController::svCameraList[0].ptPosition.x;
  v3 = CameraController::svCameraListData;
  do
  {
    if ( !v3->ucTime )
      ++this->numPaths;
    v4 = (double)(unsigned __int8)v3->ucTime;
    *v2 = v3->ptPosition.x;
    v2[1] = v3->ptPosition.y;
    v2[2] = v3->ptPosition.z;
    v2[6] = v3->vecLookAt.x;
    v2[7] = v3->vecLookAt.y;
    v2[8] = v3->vecLookAt.z;
    v5 = v3->scTension;
    v6 = v3->scBias;
    ++v1;
    *(v2 - 1) = v4 * 0.051999997;
    ++v3;
    v2 += 15;
    *(v2 - 3) = (double)v5 * 0.0099999998;
    *(v2 - 2) = (double)v6 * 0.0099999998;
  }
  while ( v1 < this->numNodes );
  CameraController::pickPath(this, -1);
}