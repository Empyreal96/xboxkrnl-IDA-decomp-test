void __userpurge D3DK::DebugSnapshot::GetColorAndDepth(D3DK::DebugSnapshot *this@<ecx>, int *a2@<edi>, unsigned int *pColor, unsigned int *pDepth)
{
  D3DK::DebugSnapshot *v4; // esi
  _D3DLOCKED_RECT lr; // [esp+4h] [ebp-8h]

  v4 = this;
  D3DDevice_BlockUntilIdle();
  D3DSurface_LockRect(a2, v4->pBackBuffer, &lr, 0, 0x40u);
  *pColor = *((_DWORD *)lr.pBits + v4->dwXScale * v4->dwX + (v4->dwY * lr.Pitch * v4->dwYScale >> 2));
  D3DSurface_LockRect(a2, v4->pDepthBuffer, &lr, 0, 0x40u);
  *pDepth = *((_DWORD *)lr.pBits + v4->dwXScale * v4->dwX + (v4->dwY * lr.Pitch * v4->dwYScale >> 2));
}