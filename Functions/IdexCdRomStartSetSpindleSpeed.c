void __usercall IdexCdRomStartSetSpindleSpeed(_IRP *Irp@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  _IO_STACK_LOCATION *v3; // eax
  unsigned int *v4; // eax
  int v5; // edx

  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v3->Parameters.Read.ByteOffset.LowPart == 4
    && (v4 = (unsigned int *)v3->Parameters.Create.Options, v5 = *v4, *v4 <= 2) )
  {
    IdexCdRomMaximumSpindleSpeed = *v4;
    Irp->IoStatus.Information = 0;
    IdexCdRomSetSpindleSpeed(v5, (int)Irp, a2, a3, *v4, (void (__stdcall *)())IdexCdRomFinishGeneric);
  }
  else
  {
    IdexChannelInvalidParameterRequest(Irp, a2);
  }
}