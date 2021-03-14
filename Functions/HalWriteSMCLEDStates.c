void __userpurge HalWriteSMCLEDStates(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, unsigned int LEDStates)
{
  int v5; // edx
  int v6; // ecx

  HalWriteSMBusValue(a1, a2, a3, a4, 32, 8, 0, LEDStates);
  HalWriteSMBusValue(v5, v6, a3, a4, 32, 7, 0, 1u);
}