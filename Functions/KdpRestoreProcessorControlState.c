_BYTE *__stdcall KdpRestoreProcessorControlState(int a1)
{
  _BYTE *result; // eax

  _EDX = a1;
  __writecr0(*(unsigned int *)(a1 + 716));
  __writecr2(*(unsigned int *)(a1 + 720));
  __writecr3(*(unsigned int *)(a1 + 724));
  __writecr4(*(unsigned int *)(a1 + 728));
  __writedr(0, *(_DWORD *)(a1 + 732));
  __writedr(1u, *(_DWORD *)(a1 + 736));
  __writedr(2u, *(_DWORD *)(a1 + 740));
  __writedr(3u, *(_DWORD *)(a1 + 744));
  __writedr(6u, *(_DWORD *)(a1 + 748));
  __writedr(7u, *(_DWORD *)(a1 + 752));
  __lgdt((void *)(a1 + 758));
  __lidt((void *)(a1 + 766));
  result = (_BYTE *)(*(unsigned __int16 *)(a1 + 772) + *(_DWORD *)(a1 + 760) + 5);
  *result &= 0xFDu;
  __asm
  {
    ltr     word ptr [edx+304h]
    lldt    word ptr [edx+306h]
  }
  return result;
}