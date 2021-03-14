void __thiscall D3DK::DebugSnapshot::SaveUserState(D3DK::DebugSnapshot *this)
{
  unsigned int v1; // edx
  unsigned int *v2; // eax

  v1 = 0;
  if ( this->UserStateCount )
  {
    v2 = &this->UserState[0].Value;
    do
    {
      *v2 = *(_DWORD *)(4 * *(v2 - 1) - 2146688056);
      ++v1;
      v2 += 2;
    }
    while ( v1 < this->UserStateCount );
  }
  D3DDevice_GetScissors(&this->dwScissorRectCount, &this->bScissorExclusive, this->ScissorRects);
}