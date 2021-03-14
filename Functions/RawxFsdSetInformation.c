int __userpurge RawxFsdSetInformation@<eax>(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _DWORD *v3; // edx
  int v4; // eax
  int v5; // esi

  v3 = &Irp->Tail.Overlay.CurrentStackLocation->MajorFunction;
  v4 = v3[6];
  if ( v3[2] != 14 || (v3 = Irp->UserBuffer, *(_BYTE *)(v4 + 3) & 4) && (DeviceObject->SectorSize - 1) & *v3 )
  {
    v5 = -1073741811;
  }
  else
  {
    *(_DWORD *)(v4 + 20) = *v3;
    v3 = (_DWORD *)v3[1];
    *(_DWORD *)(v4 + 24) = v3;
    v5 = 0;
  }
  LOBYTE(v3) = 0;
  Irp->IoStatus.Status = v5;
  IofCompleteRequest(Irp, (int)v3, a1);
  return v5;
}