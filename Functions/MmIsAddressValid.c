bool __stdcall MmIsAddressValid(void *VirtualAddress)
{
  int v1; // eax
  int *v2; // ecx
  int v3; // eax
  bool result; // al

  v1 = *(_DWORD *)((((unsigned int)VirtualAddress >> 20) & 0xFFC) - 1070596096);
  result = 0;
  if ( v1 & 1 )
  {
    if ( (v1 & 0x80u) != 0
      || (v2 = (int *)((((unsigned int)VirtualAddress >> 10) & 0x3FFFFC) - 0x40000000), v3 = *v2, *v2 & 1)
      && ((v3 & 0x80u) == 0 || (_DWORD)(v2 + 512) << 20 > 0xFFFFFFFu) )
    {
      result = 1;
    }
  }
  return result;
}