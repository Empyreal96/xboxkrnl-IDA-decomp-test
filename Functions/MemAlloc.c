// write access to const memory has been detected, the output may be wrong!
int *__userpurge MemAlloc@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int cBytes)
{
  int *v4; // edx

  ++gcMemAllocs;
  v4 = ExAllocatePoolWithTag(a1, a2, a3, cBytes, 0x4B443344u);
  if ( v4 )
    memset(v4, 0, cBytes);
  return v4;
}