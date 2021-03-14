unsigned int __userpurge CMcpxCore::GetPhysicalMemoryProperties@<eax>(int a1@<edx>, int *a2@<edi>, void *pvBuffer, unsigned int dwBufferSize, unsigned int *pdwPageOffset, unsigned int *pdwContiguousLength)
{
  unsigned int v7; // [esp+0h] [ebp-14h]
  unsigned int dwContiguousLength; // [esp+4h] [ebp-10h]
  unsigned int dwBasePhysicalAddress; // [esp+Ch] [ebp-8h]
  int dwBasePageOffset; // [esp+10h] [ebp-4h]

  dwBasePhysicalAddress = MmGetPhysicalAddress(a1, a2, pvBuffer);
  dwBasePageOffset = (unsigned __int16)pvBuffer & 0xFFF;
  if ( pdwPageOffset )
    *pdwPageOffset = dwBasePageOffset;
  if ( pdwContiguousLength )
  {
    for ( dwContiguousLength = 4096 - dwBasePageOffset;
          dwContiguousLength < dwBufferSize
       && dwContiguousLength + dwBasePhysicalAddress == MmGetPhysicalAddress(
                                                          dwContiguousLength,
                                                          a2,
                                                          (char *)pvBuffer + dwContiguousLength);
          dwContiguousLength += 4096 )
    {
      ;
    }
    if ( dwContiguousLength >= dwBufferSize )
      v7 = dwBufferSize;
    else
      v7 = dwContiguousLength;
    *pdwContiguousLength = v7;
  }
  return dwBasePhysicalAddress;
}