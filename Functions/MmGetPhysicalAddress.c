unsigned int __userpurge MmGetPhysicalAddress@<eax>(int a1@<edx>, int *a2@<edi>, void *BaseAddress)
{
  unsigned int v3; // ecx
  int v4; // eax
  int v6; // ecx
  unsigned int v7; // esi
  int v8; // eax

  v3 = (unsigned int)BaseAddress;
  v4 = *(_DWORD *)((((unsigned int)BaseAddress >> 20) & 0xFFC) - 1070596096);
  if ( !(v4 & 1) )
    goto InvalidAddress;
  if ( (v4 & 0x80u) != 0 )
  {
    v6 = v3 & 0x3FFFFF;
  }
  else
  {
    v4 = *(_DWORD *)((((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000);
    if ( !(v4 & 1) )
    {
InvalidAddress:
      DbgPrint(a2, "MmGetPhysicalAddress failed, base address was %p", BaseAddress);
      return 0;
    }
    v6 = (unsigned __int16)BaseAddress & 0xFFF;
  }
  v7 = (v4 & 0xFFFFF000) + v6;
  if ( v7 >> 12 <= MmHighestPhysicalPage )
  {
    v8 = *(_DWORD *)(4 * (v7 >> 12) - 2080440320);
    if ( !(v8 & 1) && !(_WORD)v8 )
      RtlAssert(
        a1,
        v6,
        a2,
        v7,
        "PageFrame->Busy.LockCount != 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x5Bu,
        0);
  }
  return v7;
}