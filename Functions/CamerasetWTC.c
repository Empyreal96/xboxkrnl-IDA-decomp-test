void __thiscall Camera::setWTC(Camera *this, _D3DMATRIX *wtc)
{
  Camera *v2; // ebx

  v2 = this;
  qmemcpy(&this->matWTC, wtc, sizeof(this->matWTC));
  SetInverse(&this->matWTC, &this->matCTW);
  v2->bClipPlanesSet = 0;
  v2->bWTPValid = 0;
}