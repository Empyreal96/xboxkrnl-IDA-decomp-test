void __usercall IdexChannelInvalidParameterRequest(_IRP *Irp@<ecx>, int *a2@<edi>)
{
  Irp->IoStatus.Status = -1073741811;
  IofCompleteRequest(Irp, 0, a2);
  dword_80051354();
}