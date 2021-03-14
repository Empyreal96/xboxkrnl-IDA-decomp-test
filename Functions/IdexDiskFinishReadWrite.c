void __fastcall IdexDiskFinishReadWrite(int a1, char a2)
{
  _IRP *v2; // edi
  _IO_STACK_LOCATION *v3; // esi
  int v4; // edx
  int v5; // ecx

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( Irp->IoStatus.Status >= 0 )
  {
    if ( v3->Parameters.Create.DesiredAccess <= 0x20000 )
    {
      Irp->IoStatus.Status = 0;
      IofCompleteRequest(v2, 1, (int *)&v2->Type);
      dword_80051354();
    }
    else if ( HalIsResetOrShutdownPending() )
    {
      IdexChannelAbortCurrentPacket(v4, v5, (int *)&v2->Type, (int)v3);
    }
    else
    {
      v3->Parameters.Create.DesiredAccess -= 0x20000;
      v3->Parameters.Read.ByteOffset.HighPart += 0x20000;
      v3->Parameters.Read.ByteOffset.LowPart += 256;
      dword_80051350(v5, v4, v3->DeviceObject, v2);
      dword_80051354();
    }
  }
  else
  {
    IdexDiskFinishGeneric(a2, (int *)&Irp->Type, (int)v3);
  }
}