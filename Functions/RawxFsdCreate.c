int __stdcall RawxFsdCreate(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _RAW_VOLUME_EXTENSION *v2; // ebx
  _IO_STACK_LOCATION *v3; // esi
  _FILE_OBJECT *v4; // edi
  _RAW_VOLUME_EXTENSION *v5; // ST10_4
  signed int v6; // esi
  int v7; // edx
  unsigned int DesiredAccess; // [esp+Ch] [ebp-8h]
  unsigned __int16 ShareAccess; // [esp+10h] [ebp-4h]
  unsigned int CreateOptions; // [esp+1Ch] [ebp+8h]

  v2 = (_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  DesiredAccess = v3->Parameters.Create.DesiredAccess;
  v4 = v3->FileObject;
  ShareAccess = v3->Parameters.Create.ShareAccess;
  v5 = (_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  CreateOptions = v3->Parameters.Create.Options;
  RawxAcquireVolumeMutexExclusive(v5);
  if ( v2->Dismounted )
  {
    v6 = -1073741202;
  }
  else if ( v3->FileObject->RelatedFileObject )
  {
    v6 = -1073741811;
  }
  else if ( v3->Parameters.Create.RemainingName->Length )
  {
    v6 = -1073741766;
  }
  else if ( CreateOptions >> 24 == 1 || CreateOptions >> 24 == 3 )
  {
    if ( !(CreateOptions & 1) )
    {
      if ( v2->ShareAccess.OpenCount )
      {
        v6 = IoCheckShareAccess((int *)&v4->Type, (int)v3, DesiredAccess, ShareAccess, v4, &v2->ShareAccess, 1);
        if ( v6 < 0 )
          goto CleanupAndExit_6;
      }
      else
      {
        IoSetShareAccess((int *)&v4->Type, (int)v3, DesiredAccess, ShareAccess, v4, &v2->ShareAccess);
      }
      v4->Flags |= 4u;
      Irp->IoStatus.Information = 1;
      v6 = 0;
      goto CleanupAndExit_6;
    }
    v6 = -1073741565;
  }
  else
  {
    v6 = -1073741790;
  }
CleanupAndExit_6:
  RawxReleaseVolumeMutex(v2);
  LOBYTE(v7) = 0;
  Irp->IoStatus.Status = v6;
  IofCompleteRequest(Irp, v7, (int *)&v4->Type);
  return 0;
}