void __thiscall VBlobBump::recalculateFacesOfInterest(VBlobBump *this)
{
  signed int v1; // ebx
  signed int v2; // edi
  signed int v3; // esi
  signed int v4; // edx
  signed int v5; // eax

  if ( this->vDirection.y - this->fRadius >= -0.57735002 )
    v1 = 0;
  else
    v1 = 2;
  if ( this->vDirection.z - this->fRadius >= -0.57735002 )
    v2 = 0;
  else
    v2 = 4;
  if ( this->fRadius + this->vDirection.x <= 0.57735002 )
    v3 = 0;
  else
    v3 = 8;
  if ( this->vDirection.y + this->fRadius <= 0.57735002 )
    v4 = 0;
  else
    v4 = 16;
  if ( this->fRadius + this->vDirection.z <= 0.57735002 )
    v5 = 0;
  else
    v5 = 32;
  this->facesOfInterest = (this->vDirection.x - this->fRadius < -0.57735002) + v1 + v2 + v3 + v4 + v5;
}