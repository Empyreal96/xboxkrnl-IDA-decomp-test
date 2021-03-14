void __usercall HalEnableSecureTrayEject(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  if ( XboxBootFlags & 8 )
  {
    XboxBootFlags &= 0xFFFFFFF7;
    while ( HalWriteSMBusValue(a1, a2, a3, a4, 32, 25, 0, 0) < 0 )
      ;
  }
}