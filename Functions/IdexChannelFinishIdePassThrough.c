int __usercall IdexChannelFinishIdePassThrough@<eax>(int *a1@<edi>)
{
  IofCompleteRequest(Irp, 1, a1);
  return dword_80051354();
}