int __fastcall FatxFsdDirectoryControl(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v4; // edi
  _IO_STACK_LOCATION *v5; // ebx
  int v6; // esi
  _FAT_FCB *v7; // ecx
  int v8; // edx
  unsigned int v9; // eax
  int v10; // eax
  _DIRECTORY_ENUM_CONTEXT *v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  _LARGE_INTEGER *v15; // esi
  unsigned int v16; // edx
  _LARGE_INTEGER *v17; // edi
  bool v18; // zf
  char *v19; // edi
  unsigned int v20; // eax
  unsigned int v21; // eax
  _LARGE_INTEGER v22; // rax
  unsigned int v23; // eax
  int v24; // edx
  char *v25; // edi
  char *v26; // esi
  int v27; // ecx
  int *v28; // edi
  int v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // eax
  int v32; // esi
  int v33; // edx
  _DIRENT DirectoryEntry; // [esp+Ch] [ebp-5Ch]
  unsigned int DirectoryByteOffset; // [esp+4Ch] [ebp-1Ch]
  unsigned int FileInformationClass; // [esp+50h] [ebp-18h]
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+54h] [ebp-14h]
  _FAT_FCB *DirectoryFcb; // [esp+58h] [ebp-10h]
  _DIRECTORY_ENUM_CONTEXT *DirectoryEnumContext; // [esp+5Ch] [ebp-Ch]
  unsigned int FileInformationBaseLength; // [esp+60h] [ebp-8h]
  int status; // [esp+64h] [ebp-4h]
  char InitialQuery_3; // [esp+73h] [ebp+Bh]

  v4 = Irp;
  v5 = Irp->Tail.Overlay.CurrentStackLocation;
  v6 = (int)v5->FileObject;
  v7 = *(_FAT_FCB **)(v6 + 8);
  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  DirectoryFcb = v7;
  FatxAcquireVolumeMutexExclusive(a2, (int)v7, (int *)&Irp->Type, v6, VolumeExtension);
  if ( VolumeExtension->Flags & 1 )
  {
    status = -1073741202;
  }
  else if ( DirectoryFcb->Flags & 2 )
  {
    if ( DirectoryFcb->Flags & 0x10 )
    {
      status = -1073741738;
    }
    else
    {
      v9 = v5->Parameters.Read.ByteOffset.LowPart;
      FileInformationClass = v9;
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 != 11 )
        {
          status = -1073741821;
          goto CleanupAndExit_12;
        }
        FileInformationBaseLength = 12;
      }
      else
      {
        FileInformationBaseLength = 64;
      }
      if ( v5->Flags & 4 )
      {
        status = -1073741822;
      }
      else
      {
        DirectoryEnumContext = *(_DIRECTORY_ENUM_CONTEXT **)(v6 + 12);
        v11 = DirectoryEnumContext;
        if ( DirectoryEnumContext )
        {
          InitialQuery_3 = 0;
        }
        else
        {
          status = IoCreateDirectoryEnumContext(v8, v6, v5->Parameters.QueryDirectory.FileName, &DirectoryEnumContext);
          if ( status < 0 )
            goto CleanupAndExit_12;
          *(_DWORD *)(v6 + 12) = DirectoryEnumContext;
          v11 = DirectoryEnumContext;
          InitialQuery_3 = 1;
        }
        if ( v5->Flags & 1 )
        {
          v11->QueryOffset = 0;
          v11 = DirectoryEnumContext;
        }
        v12 = FatxFindNextDirectoryEntry(
                v8,
                (int)&v11->TemplateFileName,
                v6,
                VolumeExtension,
                Irp,
                DirectoryFcb,
                v11->QueryOffset,
                &v11->TemplateFileName,
                &DirectoryEntry,
                &DirectoryByteOffset);
        status = v12;
        if ( v12 < 0 )
        {
          if ( v12 == -1073741807 )
            status = InitialQuery_3 != 0 ? -1073741809 : -2147483642;
        }
        else
        {
          if ( v5->Parameters.Create.DesiredAccess < FileInformationBaseLength )
            RtlAssert(
              v13,
              v14,
              (int *)&Irp->Type,
              v6,
              "IrpSp->Parameters.QueryDirectory.Length >= FileInformationBaseLength",
              "d:\\xbox-apr03\\private\\ntos\\fatx\\dirctrl.c",
              0x1D1u,
              0);
          v16 = FileInformationBaseLength;
          v17 = (_LARGE_INTEGER *)Irp->UserBuffer;
          v15 = v17;
          memset(v17, 0, FileInformationBaseLength);
          v18 = FileInformationClass == 1;
          v19 = (char *)v17 + v16;
          *((_DWORD *)v19 - 1) = (unsigned __int8)DirectoryEntry.FileNameLength;
          if ( v18 )
          {
            if ( DirectoryEntry.FileAttributes & 0x10 )
            {
              v20 = 0;
              v15[5].LowPart = 0;
              v15[5].HighPart = 0;
            }
            else
            {
              v21 = DirectoryEntry.FileSize;
              v15[5].HighPart = 0;
              v15[5].LowPart = v21;
              v20 = DirectoryEntry.FileSize;
            }
            v15[6].HighPart = 0;
            v15[6].LowPart = v20;
            v15[1] = FatxFatTimestampToTime(&DirectoryEntry.CreationTime);
            v22 = FatxFatTimestampToTime(&DirectoryEntry.LastWriteTime);
            v15[4].LowPart = v22.LowPart;
            v15[3] = v22;
            v15[2].LowPart = v15[4].LowPart;
            v15[4].HighPart = v22.HighPart;
            v15[2].HighPart = v22.HighPart;
            if ( DirectoryEntry.FileAttributes )
              v15[7].LowPart = (unsigned __int8)DirectoryEntry.FileAttributes;
            else
              v15[7].LowPart = 128;
          }
          v23 = (unsigned __int8)DirectoryEntry.FileNameLength;
          if ( (unsigned __int8)DirectoryEntry.FileNameLength <= ((v5->Parameters.Create.DesiredAccess
                                                                 - FileInformationBaseLength) & 0xFFFFFFFC) )
          {
            status = 0;
          }
          else
          {
            v23 = (v5->Parameters.Create.DesiredAccess - FileInformationBaseLength) & 0xFFFFFFFC;
            status = -2147483643;
          }
          v24 = v23;
          qmemcpy(v19, DirectoryEntry.FileName, 4 * (v23 >> 2));
          v26 = &DirectoryEntry.FileName[4 * (v23 >> 2)];
          v25 = &v19[4 * (v23 >> 2)];
          v27 = v23 & 3;
          qmemcpy(v25, v26, v27);
          v29 = (int)&v26[v27];
          v28 = (int *)&v25[v27];
          v30 = FileInformationBaseLength + v23;
          Irp->IoStatus.Information = v30;
          if ( v30 > v5->Parameters.Create.DesiredAccess )
            RtlAssert(
              v24,
              (int)Irp,
              v28,
              v29,
              "Irp->IoStatus.Information <= IrpSp->Parameters.QueryDirectory.Length",
              "d:\\xbox-apr03\\private\\ntos\\fatx\\dirctrl.c",
              0x234u,
              0);
          v31 = DirectoryByteOffset;
          v4 = Irp;
          DirectoryEnumContext->QueryOffset = DirectoryByteOffset + 64;
          DirectoryFcb->File.FileMutex.ReadersWaitingCount = v31;
        }
      }
    }
  }
  else
  {
    status = -1073741811;
  }
CleanupAndExit_12:
  FatxReleaseVolumeMutex(VolumeExtension);
  v32 = status;
  LOBYTE(v33) = 0;
  v4->IoStatus.Status = status;
  IofCompleteRequest(v4, v33, (int *)&v4->Type);
  return v32;
}