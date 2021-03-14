_D3DMATRIX *__thiscall Camera::getWTP(Camera *this)
{
  Camera *v1; // esi

  v1 = this;
  if ( !this->bWTPValid )
  {
    MulMats(&this->matWTC, &this->matProj, &this->matWTP);
    v1->bWTPValid = 1;
  }
  return &v1->matWTP;
}