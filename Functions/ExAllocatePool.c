int *__userpurge ExAllocatePool@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int NumberOfBytes)
{
  return ExAllocatePoolWithTag(a1, a2, a3, NumberOfBytes, 0x656E6F4Eu);
}