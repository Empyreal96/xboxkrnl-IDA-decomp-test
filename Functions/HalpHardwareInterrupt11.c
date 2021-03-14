void HalpHardwareInterrupt11()
{
  __asm
  {
    ffreep  st(3); (emulator call)
    fcmovne st, st(5); (emulator call)
  }
  JUMPOUT(*(_DWORD *)byte_8001BE18);
}