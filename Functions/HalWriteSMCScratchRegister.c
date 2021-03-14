int __userpurge HalWriteSMCScratchRegister@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, unsigned int ScratchRegister)
{
  HalpSMCScratchRegister = ScratchRegister;
  return HalWriteSMBusValue(a1, a2, a3, a4, 32, 27, 0, ScratchRegister);
}