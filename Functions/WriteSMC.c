int __userpurge WriteSMC@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, char addr, char value)
{
  return HalWriteSMBusValue(a1, a2, a3, a4, 32, addr, 0, (unsigned __int8)value);
}