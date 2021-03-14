int *__userpurge FatxFsdFileSystemControl@<eax>(char a1@<dl>, int a2@<ecx>, int *a3@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int v5; // eax
  int *v6; // edi
  int v7; // eax

  v5 = *(_DWORD *)(Irp->Tail.Overlay.PacketType + 16);
  if ( v5 == 589856 )
  {
    v7 = FatxDismountVolume(a1, a2, a3, DeviceObject);
    goto LABEL_7;
  }
  if ( v5 == 606492 || v5 == 622880 )
  {
    v7 = FatxReadWriteVolumeMetadata(a1, a3, DeviceObject, Irp);
LABEL_7:
    v6 = (int *)v7;
    goto LABEL_8;
  }
  v6 = (int *)-1073741808;
LABEL_8:
  Irp->IoStatus.Information = 0;
  Irp->IoStatus.Status = (int)v6;
  IofCompleteRequest(Irp, 0, v6);
  return v6;
}