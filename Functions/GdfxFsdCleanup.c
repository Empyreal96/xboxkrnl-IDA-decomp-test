int __userpurge GdfxFsdCleanup@<eax>(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int v3; // eax
  int v4; // ecx
  _STRING FileName; // [esp+4h] [ebp-8h]

  v3 = *(_DWORD *)(Irp->Tail.Overlay.PacketType + 24);
  v4 = *(_DWORD *)(v3 + 8);
  if ( *(_DWORD *)(v3 - 16) > 1 )
  {
    FileName.Length = *(unsigned __int8 *)(v4 + 33);
    FileName.MaximumLength = FileName.Length;
    FileName.Buffer = (char *)(v4 + 34);
    DbgPrint(
      a1,
      "GDFX: I/O in progress while closing handle for file %Z\n"
      "GDFX: Wait for async I/O to complete prior to closing the file handle.\n",
      &FileName);
  }
  Irp->IoStatus.Status = 0;
  IofCompleteRequest(Irp, 0, a1);
  return 0;
}