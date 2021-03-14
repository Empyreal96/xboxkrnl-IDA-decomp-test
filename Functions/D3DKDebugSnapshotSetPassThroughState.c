void __thiscall D3DK::DebugSnapshot::SetPassThroughState(D3DK::DebugSnapshot *this)
{
  int v1; // eax
  int v2; // ecx
  _D3DRECT rect; // [esp+0h] [ebp-10h]

  v1 = this->dwX;
  v2 = this->dwY;
  rect.x1 = v1;
  rect.x2 = v1 + 1;
  rect.y1 = v2;
  rect.y2 = v2 + 1;
  D3DDevice_SetScissors(1u, 0, &rect);
  D3DDevice_SetRenderStateNotInline(D3DRS_ALPHATESTENABLE, 0);
  D3DDevice_SetRenderStateNotInline(D3DRS_STENCILENABLE, 0);
  D3DDevice_SetRenderStateNotInline(D3DRS_ZENABLE, 0);
  D3DDevice_SetRenderStateNotInline(D3DRS_ALPHABLENDENABLE, 1u);
  D3DDevice_SetRenderStateNotInline(D3DRS_SRCBLEND, 1u);
  D3DDevice_SetRenderStateNotInline(D3DRS_DESTBLEND, 0);
  D3DDevice_SetRenderStateNotInline(D3DRS_COLORWRITEENABLE, 0x1010101u);
  D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSABCD, 0xC0C00u);
  D3DDevice_SetRenderStateNotInline(D3DRS_PSFINALCOMBINERINPUTSEFG, 0x1C80u);
}