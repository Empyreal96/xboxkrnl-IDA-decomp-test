char *__userpurge D3DK::GetDataFromResource@<eax>(int *a1@<edi>, D3DResource *pResource)
{
  unsigned int v2; // esi

  v2 = pResource->Data;
  if ( v2 > 0x4000000 )
  {
    DbgPrint(a1, "DebugVerifyPhysical - Not a valid physical memory offset.");
    DbgPrint(a1, "\n");
    __debugbreak();
  }
  return (char *)(v2 | 0x80000000);
}