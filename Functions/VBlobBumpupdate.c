bool __thiscall VBlobBump::update(VBlobBump *this, float elapsed_time, float dt, VBloblet *p_bloblet)
{
  VBlobBump *v4; // ebx
  VBloblet *v5; // edi
  float v6; // ST14_4
  double v7; // st7
  double v8; // st6
  bool v9; // zf
  double v10; // st6
  float *v11; // esi
  double v12; // st7
  float x; // ST04_4
  float *v15; // esi

  v4 = this;
  if ( this->pMyBloblet )
  {
    v5 = this->pMyBloblet;
    v6 = gpVBlob->m_fRadius;
    v7 = (fast_fabs(v5->fCurDist) + v5->fRadius) / v6;
    v8 = v7 - 1.0;
    if ( v7 - 1.0 < 0.0 || v8 <= 2.0 )
    {
      if ( v8 < 0.0 )
        v8 = 0.0;
    }
    else
    {
      v8 = 2.0;
    }
    v9 = v4->bStillAttachedToBloblet == 0;
    v4->fMagnitude = v8;
    if ( !v9 )
    {
      if ( v8 <= 0.80000001 )
      {
        v11 = &v4->vDirection.x;
        if ( Dot(&v4->vDirection, &v5->vDirection) < 0.0 == v5->bFarSide )
          return 0;
        Scale(&v4->vDirection, -1.0);
LABEL_26:
        v4->vPosition.x = *v11;
        v15 = v11 + 1;
        v4->vPosition.y = *v15;
        v4->vPosition.z = v15[1];
        VBlobBump::recalculateFacesOfInterest(v4);
        return 0;
      }
      v4->fMaxMagnitude = v8;
      v4->bStillAttachedToBloblet = 0;
      v4->fTimeMul = 6.2831855 / (0.30000001 * v8);
      v4->fStartTime = elapsed_time - 0.30000001 * v8 * 0.25;
      v10 = v8 - 0.5;
      if ( v10 > 0.80000001 || v10 >= 0.60000002 )
      {
        if ( v10 > 0.80000001 )
          v10 = 0.80000001;
      }
      else
      {
        v10 = 0.60000002;
      }
      v5->fWobble = v10;
      v4->pMyBloblet->fWobbleDirection = 0.0;
    }
    if ( !v4->bStillAttachedToBloblet && v7 < 0.89999998 )
      v4->bStillAttachedToBloblet = 1;
  }
  v12 = (elapsed_time - v4->fStartTime) * v4->fTimeMul;
  if ( v12 <= 3.1415927 )
  {
    if ( v12 < 0.0 )
      return 0;
    x = v12;
    v11 = &v4->vDirection.x;
    v4->fMagnitude = fast_sin(x) * v4->fMaxMagnitude;
    goto LABEL_26;
  }
  if ( !v4->pMyBloblet )
    return VBlobBump::create(v4, elapsed_time, p_bloblet);
  v4->fMagnitude = 0.0;
  return 0;
}