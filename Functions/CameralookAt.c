void __thiscall Camera::lookAt(Camera *this, _D3DVECTOR *cam_pos, _D3DVECTOR *look_pt, _D3DVECTOR *up)
{
  Camera *v4; // ebx

  v4 = this;
  SetLookAt(cam_pos, look_pt, up, &this->matWTC);
  v4->vPos = *cam_pos;
  v4->vLook = *look_pt;
  v4->vUp = *up;
  SetInverse(&v4->matWTC, &v4->matCTW);
  v4->bClipPlanesSet = 0;
  v4->bWTPValid = 0;
}