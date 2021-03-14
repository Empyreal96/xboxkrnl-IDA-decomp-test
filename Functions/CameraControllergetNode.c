CamControlNode *__thiscall CameraController::getNode(CameraController *this, int i)
{
  int v2; // eax
  CamControlNode *result; // eax

  v2 = this->curVariableNodes;
  if ( i >= v2 )
    result = &this->finishNodes[i - v2];
  else
    result = &CameraController::svCameraList[i + this->curStartNode];
  return result;
}