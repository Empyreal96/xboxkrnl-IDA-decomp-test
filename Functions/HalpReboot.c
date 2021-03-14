void __usercall __noreturn HalpReboot(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  if ( (unsigned __int8)dword_8004C5D0 < 2u )
    HalWriteSMBusValue(a1, a2, a3, a4, 32, 2, 0, 1u);
  __outbyte(0xCF9u, 0xEu);
  _disable();
  __halt();
  JUMPOUT(loc_8001D60B);
}