void __userpurge D3DK::CMiniport::GetAddressInfo(D3DK::CMiniport *this@<ecx>, int *a2@<edi>, void *pLinearAddress, void **ppAddress, unsigned int *pAddressSpace, int IsAlias)
{
  D3DK::AssertContiguousOrPhysical(a2, pLinearAddress);
  if ( IsAlias )
  {
    *ppAddress = (void *)((unsigned int)pLinearAddress & 0xFFFFFFF | 0x40000000);
    *pAddressSpace = 3;
  }
  else if ( ((unsigned int)pLinearAddress & 0xF0000000) == 0x80000000 )
  {
    *ppAddress = (void *)D3DK::GetGPUAddress(a2, pLinearAddress);
    *pAddressSpace = 1;
  }
  else
  {
    *ppAddress = pLinearAddress;
    *pAddressSpace = 2;
  }
}