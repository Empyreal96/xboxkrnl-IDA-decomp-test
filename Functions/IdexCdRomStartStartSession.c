void __usercall IdexCdRomStartStartSession(_IRP *Irp@<ecx>, int *a2@<edi>)
{
  _IO_STACK_LOCATION *v2; // edx
  _CDB Cdb; // [esp+0h] [ebp-10h]

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v2->Parameters.Create.DesiredAccess >= 4 )
  {
    Irp->IoStatus.Information = 4;
    *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
    *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
    Cdb.CDB6GENERIC.OperationCode = -92;
    *((_WORD *)&Cdb.PCDB6VERIFY + 4) = 2048;
    if ( Cdb.CDB12.Reserved2 & 0xC0 )
      RtlAssert(
        (int)v2,
        (int)Irp,
        0,
        (int)"d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        "Cdb.REPORT_KEY.AGID == 0",
        "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        0x73Bu,
        0);
    IdexCdRomIssueAtapiRequest(
      (int)v2,
      (int)Irp,
      0,
      &Cdb,
      &IdexCdRomStaticTransferBuffer,
      8u,
      0,
      (void (__stdcall *)())IdexCdRomFinishStartSession);
  }
  else
  {
    IdexChannelInvalidParameterRequest(Irp, a2);
  }
}