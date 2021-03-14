void __stdcall HalpHardwareInterruptTable()
{
  __asm { int     30h; (NOT A VECTOR!) FAR JMP instruction for CP/M-style calls }
}