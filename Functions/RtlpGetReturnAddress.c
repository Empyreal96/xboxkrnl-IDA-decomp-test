int __usercall RtlpGetReturnAddress@<eax>(int a1@<ebp>)
{
  return *(_DWORD *)(a1 + 4);
}