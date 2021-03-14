void __usercall FscSetCacheBufferProtection(void *CacheBuffer@<ecx>, char MapAsReadWrite@<dl>, int *a3@<edi>)
{
  char v3; // bl
  unsigned int v4; // esi
  _MMPTE *PointerPte; // ST18_4

  v3 = MapAsReadWrite;
  v4 = (unsigned int)CacheBuffer;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      MapAsReadWrite,
      (int)CacheBuffer,
      a3,
      (int)CacheBuffer,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x2F5u,
      0);
  PointerPte = (_MMPTE *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000);
  PointerPte->Long ^= (PointerPte->Long ^ 2 * (v3 != 0)) & 2;
  __invlpg((void *)((_DWORD)PointerPte << 10));
}