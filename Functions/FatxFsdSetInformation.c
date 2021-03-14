int *__fastcall FatxFsdSetInformation(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int *v4; // edi
  _FAT_FCB *v5; // ebx
  _FILE_OBJECT *v6; // ecx
  int *v7; // eax
  unsigned int *v8; // eax
  unsigned int *v9; // eax
  int v10; // edx
  int v11; // ecx
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+Ch] [ebp-4h]
  _FILE_OBJECT *FileObject; // [esp+18h] [ebp+8h]
  int *FileObjecta; // [esp+18h] [ebp+8h]

  v4 = (int *)&Irp->Tail.Overlay.CurrentStackLocation->MajorFunction;
  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v5 = *(_FAT_FCB **)(v4[6] + 8);
  FileObject = (_FILE_OBJECT *)v4[6];
  if ( !(v5->Flags & 3) )
    FatxAcquireFileMutexExclusive(a2, a1, v4, v5);
  FatxAcquireVolumeMutexExclusive(a2, a1, v4, (int)Irp, VolumeExtension);
  if ( VolumeExtension->Flags & 1 )
  {
    FileObjecta = (int *)-1073741202;
    goto CleanupAndExit_15;
  }
  v6 = FileObject;
  if ( FileObject->Flags & 0x10 )
  {
    FileObjecta = (int *)-1073741528;
    goto CleanupAndExit_15;
  }
  v4 = (int *)(v4[2] - 4);
  FileObjecta = 0;
  if ( v4 )
  {
    v4 = (int *)((char *)v4 - 6);
    if ( v4 )
    {
      v4 = (int *)((char *)v4 - 3);
      if ( v4 )
      {
        v4 = (int *)((char *)v4 - 1);
        if ( v4 )
        {
          v4 = (int *)((char *)v4 - 5);
          if ( v4 )
          {
            v4 = (int *)((char *)v4 - 1);
            if ( !v4 && !(v5->Flags & 3) )
            {
              v7 = FatxSetEndOfFileInformation(
                     (int)v6,
                     0,
                     VolumeExtension,
                     Irp,
                     v6,
                     (_FILE_END_OF_FILE_INFORMATION *)Irp->UserBuffer);
LABEL_28:
              FileObjecta = v7;
              goto CleanupAndExit_15;
            }
          }
          else
          {
            v8 = (unsigned int *)Irp->UserBuffer;
            if ( !(v5->Flags & 3) )
            {
              if ( v8[1] )
              {
                FileObjecta = (int *)-1073741697;
                goto CleanupAndExit_15;
              }
              v7 = FatxSetAllocationSize(0, (int)v6, 0, VolumeExtension, Irp, v5, *v8, 0, 0);
              goto LABEL_28;
            }
          }
        }
        else
        {
          v9 = (unsigned int *)Irp->UserBuffer;
          if ( !(v6->Flags & 4) || !((VolumeExtension->CacheExtension.SectorSize - 1) & *v9) )
          {
            v6->CurrentByteOffset.LowPart = *v9;
            v6->CurrentByteOffset.HighPart = v9[1];
            goto CleanupAndExit_15;
          }
        }
      }
      else if ( !(v5->Flags & 5) )
      {
        v7 = (int *)FatxSetDispositionInformation(
                      (int)v6,
                      0,
                      VolumeExtension,
                      Irp,
                      v6,
                      (_FILE_DISPOSITION_INFORMATION *)Irp->UserBuffer);
        goto LABEL_28;
      }
    }
    else if ( !(v5->Flags & 5) )
    {
      v7 = FatxSetRenameInformation((int)v6, 0, VolumeExtension, Irp);
      goto LABEL_28;
    }
  }
  else if ( !(v5->Flags & 5) )
  {
    v7 = (int *)FatxSetBasicInformation(
                  (int)v6,
                  0,
                  VolumeExtension,
                  Irp,
                  v6,
                  (_FILE_BASIC_INFORMATION *)Irp->UserBuffer);
    goto LABEL_28;
  }
  FileObjecta = (int *)-1073741811;
CleanupAndExit_15:
  FatxReleaseVolumeMutex(VolumeExtension);
  if ( !(v5->Flags & 3) )
    FatxReleaseFileMutex(v10, v11, v4, v5);
  LOBYTE(v10) = 0;
  Irp->IoStatus.Status = (int)FileObjecta;
  IofCompleteRequest(Irp, v10, FileObjecta);
  return FileObjecta;
}