unsigned int __userpurge CMcpxCore::MapTransfer@<eax>(int *a1@<edi>, void **ppvBuffer, unsigned int *pdwBufferSize, unsigned int *pdwBytesMapped)
{
  unsigned int v5; // [esp+0h] [ebp-10h]
  unsigned int dwPhysicalAddress; // [esp+4h] [ebp-Ch]
  unsigned int dwPageOffset; // [esp+Ch] [ebp-4h]

  dwPhysicalAddress = CMcpxCore::GetPhysicalMemoryProperties(
                        *pdwBufferSize,
                        a1,
                        *ppvBuffer,
                        *pdwBufferSize,
                        &dwPageOffset,
                        0);
  if ( 4096 - dwPageOffset >= *pdwBufferSize )
    v5 = *pdwBufferSize;
  else
    v5 = 4096 - dwPageOffset;
  *ppvBuffer = (char *)*ppvBuffer + v5;
  *pdwBufferSize -= v5;
  if ( pdwBytesMapped )
    *pdwBytesMapped = v5;
  return dwPhysicalAddress;
}