int *__fastcall IdexDiskDeviceControl(int a1, char a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v4; // eax
  int *v5; // edi
  int v6; // eax

  v4 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v4->Parameters.Read.ByteOffset.HighPart == 315432 )
  {
    v4->Control |= 1u;
    dword_80051350(0, a2, DeviceObject, Irp);
    v5 = (int *)259;
  }
  else
  {
    switch ( v4->Parameters.Read.ByteOffset.HighPart )
    {
      case 0x70000:
        v6 = IdexDiskGetDriveGeometry(DeviceObject, Irp);
        break;
      case 0x70014:
        v6 = IdexDiskVerify(DeviceObject, Irp);
        break;
      case 0x74004:
        v6 = IdexDiskGetPartitionInfo(DeviceObject, Irp);
        break;
      default:
        v5 = (int *)-1073741808;
LABEL_12:
        Irp->IoStatus.Status = (int)v5;
        IofCompleteRequest(Irp, 0, v5);
        return v5;
    }
    v5 = (int *)v6;
  }
  if ( v5 != (int *)259 )
    goto LABEL_12;
  return v5;
}