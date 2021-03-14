char *__usercall CMcpxAPU::operator new@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int cbBuffer)
{
  return PoolAlloc(a1, a2, a3, cbBuffer, 0);
}