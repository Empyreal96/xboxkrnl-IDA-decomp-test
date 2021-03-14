void __thiscall D3DK::DebugSnapshot::RestoreUserState(D3DK::DebugSnapshot *this)
{
  D3DK::CDevice *v1; // eax
  D3DK::DebugSnapshot *v2; // edi
  unsigned int v3; // ebx
  D3DK::_userstateentry *v4; // esi

  v1 = D3DK::g_pDevice;
  v2 = this;
  v3 = 0;
  if ( this->UserStateCount )
  {
    v4 = this->UserState;
    do
    {
      D3DDevice_SetRenderStateNotInline(v4->Enum, v4->Value);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->UserStateCount );
    v1 = D3DK::g_pDevice;
  }
  v1->m_DirtyFlags |= 0x448u;
  D3DDevice_SetScissors(v2->dwScissorRectCount, v2->bScissorExclusive, v2->ScissorRects);
}