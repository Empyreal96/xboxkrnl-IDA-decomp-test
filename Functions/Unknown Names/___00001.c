SIZE_T __stdcall ___00001(const void *Source1, const void *Source2, SIZE_T Length)
{
  return RtlCompareMemory(Source1, Source2, Length);
}