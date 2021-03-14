int __userpurge RawxFsdQueryInformation@<eax>(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v3; // eax
  int v4; // esi
  _FILE_OBJECT *v5; // eax
  _DWORD *v6; // edx

  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v3->Parameters.Create.Options == 14 )
  {
    v5 = v3->FileObject;
    v6 = Irp->UserBuffer;
    *v6 = v5->CurrentByteOffset.LowPart;
    v6[1] = v5->CurrentByteOffset.HighPart;
    Irp->IoStatus.Information = 8;
    v4 = 0;
  }
  else
  {
    v4 = -1073741811;
  }
  Irp->IoStatus.Status = v4;
  IofCompleteRequest(Irp, 0, a1);
  return v4;
}