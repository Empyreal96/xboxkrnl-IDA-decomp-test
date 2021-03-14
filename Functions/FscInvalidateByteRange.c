void __userpurge FscInvalidateByteRange(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FSCACHE_EXTENSION *CacheExtension, unsigned __int64 ByteOffset, unsigned int Length)
{
  if ( !Length )
    RtlAssert(a1, a2, a3, 0, "Length != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c", 0x8A5u, 0);
  FscInvalidateBlocks(CacheExtension, ByteOffset >> 12, (ByteOffset + Length - 1) >> 12);
}