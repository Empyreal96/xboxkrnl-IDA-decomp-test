int __userpurge XCryptModExp@<eax>(int a1@<ebx>, unsigned int *pA, unsigned int *pB, unsigned int *pC, unsigned int *pD, unsigned int dwN)
{
  return BenalohModExp(a1, pA, pB, pC, pD, dwN);
}