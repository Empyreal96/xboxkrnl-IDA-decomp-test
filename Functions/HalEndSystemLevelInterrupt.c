int __usercall HalEndSystemLevelInterrupt@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  if ( a1 >= 8 )
    __outbyte(0xA0u, a1 + 88);
  else
    __outbyte(0x20u, a1 | 0x60);
  return HalEndSystemInterrupt(a2);
}