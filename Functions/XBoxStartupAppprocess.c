void __thiscall XBoxStartupApp::process(XBoxStartupApp *this)
{
  XBoxStartupApp *v1; // esi
  volatile unsigned int v2; // edi
  int v3; // eax
  double v4; // st7
  double v5; // st6
  float cam_dt; // ST04_4
  float dt; // ST00_4
  const float f_app_time_muls[3]; // [esp+10h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = KeTickCount;
  v9 = abs(this->dwLastTick - KeTickCount);
  v3 = this->appSpeedId;
  v4 = (double)v9 * 0.001;
  f_app_time_muls[1] = 0.5;
  f_app_time_muls[0] = 1.0;
  f_app_time_muls[2] = 0.0;
  v5 = this->fJogDeltaTime;
  this->fJogDeltaTime = 0.0;
  cam_dt = v4;
  dt = v4 * f_app_time_muls[v3] + v5;
  XBoxStartupApp::advanceTime(this, dt, cam_dt);
  XBoxStartupApp::drawFrame(v1);
  v1->dwLastTick = v2;
}