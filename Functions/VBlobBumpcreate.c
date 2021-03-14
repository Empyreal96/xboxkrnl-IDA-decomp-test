BOOL __thiscall VBlobBump::create(VBlobBump *this, float cur_time, VBloblet *p_bloblet)
{
  VBlobBump *v3; // ebx
  float *v4; // esi
  double v5; // st7
  double v6; // st7
  float rad_mag_rand; // ST14_4
  double v8; // st7
  double v9; // st7
  double v10; // st7
  bool v11; // zf
  _DWORD *v12; // edi
  double v13; // st7
  double v14; // st7
  double v15; // st7
  VBloblet *v16; // ecx
  float time_prog; // [esp+18h] [ebp-4h]
  float f_main_rad; // [esp+28h] [ebp+Ch]
  float f_main_rada; // [esp+28h] [ebp+Ch]

  v3 = this;
  if ( cur_time < 0.0 )
    this->pMyBloblet = 0;
  v4 = &this->vDirection.x;
  this->vDirection.x = VBlob::fRand11();
  v3->vDirection.y = VBlob::fRand11();
  v3->vDirection.z = VBlob::fRand11();
  if ( Length2(&v3->vDirection) < 0.001 )
  {
    *v4 = VBlob::fRand11();
    v3->vDirection.y = VBlob::fRand11();
    v3->vDirection.z = 1.0;
  }
  v3->vPosition.x = 0.0;
  v3->vPosition.y = 0.0;
  v3->vPosition.z = 0.0;
  QuickNormalize(&v3->vDirection);
  v5 = (cur_time - 0.60000002) * 0.24390244;
  if ( v5 < 0.0 )
    v5 = 0.0;
  time_prog = v5;
  v6 = VBlob::fRand01();
  rad_mag_rand = v6;
  v8 = (v6 + 1.0) * 0.40000001;
  v3->fRadius = v8;
  v9 = v8 * v8;
  v3->fRadius2 = v9;
  v3->fOORadius2 = 1.0 / v9;
  v3->fMagnitude = 0.0;
  VBlobBump::recalculateFacesOfInterest(v3);
  v10 = VBlob::fRand01();
  v11 = v3->pMyBloblet == 0;
  v3->fStartTime = v10 * 0.40000001 + cur_time;
  v3->fMaxMagnitude = ((1.0 - rad_mag_rand) * 0.5 + 0.2) * (time_prog + 1.0) * 0.5;
  if ( v11 && (v3->pMyBloblet = p_bloblet) == 0 )
  {
    f_main_rada = time_prog * 0.2 + 0.80000001;
    v3->fTimeMul = f_main_rada / ((VBlob::fRand01() + v3->fMaxMagnitude) * 0.30000001) * 3.1415927;
    if ( cur_time < -1.0 )
      v3->fStartTime = VBlob::fRand01() / v3->fTimeMul * -3.1415927;
  }
  else
  {
    f_main_rad = gpVBlob->m_fRadius;
    v3->pMyBloblet->fRadius = (VBlob::fRand01() + 1.0) * v3->fRadius * f_main_rad * 0.25;
    v12 = (_DWORD *)&v3->pMyBloblet->vDirection.x;
    *v12 = *(_DWORD *)v4;
    ++v12;
    *v12 = LODWORD(v3->vDirection.y);
    v12[1] = LODWORD(v3->vDirection.z);
    v13 = VBlob::fRand11();
    v3->pMyBloblet->fMaxDist = (v13 + v13 + 5.0) * f_main_rad;
    v3->pMyBloblet->fMaxDist = v3->pMyBloblet->fMaxDist * 0.60000002;
    if ( cur_time >= -1.0 )
      v14 = cur_time;
    else
      v14 = VBlob::fRand01() * -0.30000001;
    v3->pMyBloblet->fStartTime = v14;
    v15 = (VBlob::fRand01() * 0.30000001 + 0.80000001) * 1.6666666;
    v3->pMyBloblet->fTimeMultiple = 6.2831855 / v15;
    v3->pMyBloblet->fWobble = 1.2;
    v3->pMyBloblet->fWobbleDirection = 0.0;
    v16 = v3->pMyBloblet;
    v3->bStillAttachedToBloblet = v15 * 0.40000001 > cur_time - v3->fStartTime;
    VBloblet::update(v16, cur_time, 0.0);
    VBlobBump::update(v3, cur_time, 0.0, 0);
  }
  return v3->pMyBloblet != 0;
}