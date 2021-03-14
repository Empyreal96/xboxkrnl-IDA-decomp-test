int __userpurge CMcpxCore::AllocateContext@<eax>(int *a1@<edi>, int a2@<esi>, MCPX_ALLOC_CONTEXT *pContext, unsigned int dwSize, unsigned int dwAlignment, unsigned int dwFlags)
{
  int hr; // [esp+0h] [ebp-4h]

  pContext->VirtualAddress = PhysicalAlloc(a2, dwSize, dwAlignment, dwFlags, 0);
  hr = pContext->VirtualAddress != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 )
  {
    pContext->PhysicalAddress = MmGetPhysicalAddress((int)pContext->VirtualAddress, a1, pContext->VirtualAddress);
    pContext->Size = dwSize;
  }
  return hr;
}