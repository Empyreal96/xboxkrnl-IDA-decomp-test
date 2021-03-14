void __thiscall Camera::setProjection(Camera *this, float fov_in_y, float aspect, float near_plane, float far_plane)
{
  Camera *v5; // esi

  v5 = this;
  SetProjection(fov_in_y, aspect, near_plane, far_plane, &this->matProj);
  v5->fNearPlane = near_plane;
  v5->fFarPlane = far_plane;
  v5->fAspectRatio = aspect;
  v5->bClipPlanesSet = 0;
  v5->bWTPValid = 0;
}