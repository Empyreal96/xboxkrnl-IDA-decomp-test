int *__userpurge RSA32Alloc@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int size)
{
  return ExAllocatePoolWithTag(a1, a2, a3, size, 0x79724358u);
}