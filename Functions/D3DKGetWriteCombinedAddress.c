unsigned int __userpurge D3DK::GetWriteCombinedAddress@<eax>(int *a1@<edi>, unsigned int Offset)
{
  if ( Offset > 0x4000000 )
  {
    DbgPrint(a1, "DebugVerifyPhysical - Not a valid physical memory offset.");
    DbgPrint(a1, "\n");
    __debugbreak();
  }
  return Offset | 0x80000000;
}