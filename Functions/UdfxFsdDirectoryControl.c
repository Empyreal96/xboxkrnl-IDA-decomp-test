int __stdcall UdfxFsdDirectoryControl(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v2; // edi
  _IO_STACK_LOCATION *v3; // ebx
  int v4; // esi
  int v5; // edx
  void *v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edx
  _LARGE_INTEGER *v11; // esi
  int v12; // edx
  _LARGE_INTEGER *v13; // edi
  bool v14; // zf
  int *v15; // edi
  _LARGE_INTEGER *v16; // eax
  _LARGE_INTEGER v17; // rax
  int v18; // ecx
  unsigned int v19; // edx
  char *v20; // esi
  int *v21; // edi
  char *v22; // esi
  unsigned int v23; // eax
  int v24; // ecx
  int *v25; // edi
  int v26; // esi
  unsigned int v27; // eax
  int v28; // esi
  int v29; // edx
  _STRING FileName; // [esp+Ch] [ebp-24h]
  unsigned int FileInformationClass; // [esp+14h] [ebp-1Ch]
  _UDF_VOLUME_EXTENSION *VolumeExtension; // [esp+18h] [ebp-18h]
  NSR_FID *FileIdentifierDescriptor; // [esp+1Ch] [ebp-14h]
  _UDF_FCB *InformationFcb; // [esp+20h] [ebp-10h]
  _DIRECTORY_ENUM_CONTEXT *DirectoryEnumContext; // [esp+24h] [ebp-Ch]
  unsigned int FileInformationBaseLength; // [esp+28h] [ebp-8h]
  int status; // [esp+2Ch] [ebp-4h]
  char InitialQuery_3; // [esp+3Bh] [ebp+Bh]

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = (int)v3->FileObject;
  VolumeExtension = (_UDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  FileIdentifierDescriptor = *(NSR_FID **)(v4 + 8);
  RtlEnterCriticalSectionAndRegion(&UdfxGlobalMutex);
  if ( !(FileIdentifierDescriptor->Destag.Ident & 2) )
  {
    status = -1073741811;
    goto CleanupAndExit_32;
  }
  v7 = v3->Parameters.Read.ByteOffset.LowPart;
  FileInformationClass = v7;
  v8 = v7 - 1;
  if ( v8 )
  {
    if ( v8 != 11 )
    {
      status = -1073741821;
      goto CleanupAndExit_32;
    }
    FileInformationBaseLength = 12;
  }
  else
  {
    FileInformationBaseLength = 64;
  }
  if ( v3->Flags & 4 )
  {
    status = -1073741822;
    goto CleanupAndExit_32;
  }
  DirectoryEnumContext = *(_DIRECTORY_ENUM_CONTEXT **)(v4 + 12);
  if ( DirectoryEnumContext )
  {
    InitialQuery_3 = 0;
  }
  else
  {
    status = IoCreateDirectoryEnumContext(v5, v4, v3->Parameters.QueryDirectory.FileName, &DirectoryEnumContext);
    if ( status < 0 )
      goto CleanupAndExit_32;
    *(_DWORD *)(v4 + 12) = DirectoryEnumContext;
    InitialQuery_3 = 1;
  }
  if ( v3->Flags & 1 )
    DirectoryEnumContext->QueryOffset = 0;
  v9 = UdfxFindNextFileIdentifierDescriptor(
         v5,
         (int)v6,
         (NSR_FID *)v4,
         VolumeExtension,
         Irp,
         (_UDF_FCB *)FileIdentifierDescriptor,
         DirectoryEnumContext,
         &FileIdentifierDescriptor,
         &FileName);
  status = v9;
  if ( v9 >= 0 )
  {
    if ( v3->Parameters.Create.DesiredAccess < FileInformationBaseLength )
      RtlAssert(
        v10,
        (int)v6,
        (int *)&Irp->Type,
        v4,
        "IrpSp->Parameters.QueryDirectory.Length >= FileInformationBaseLength",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\dirctrl.c",
        0x23Cu,
        0);
    v12 = FileInformationBaseLength;
    v13 = (_LARGE_INTEGER *)Irp->UserBuffer;
    v11 = v13;
    memset(v13, 0, FileInformationBaseLength);
    v14 = FileInformationClass == 1;
    v15 = (int *)((char *)v13 + v12);
    *(v15 - 1) = FileName.Length;
    if ( v14 )
    {
      status = UdfxCreateFcbFromFileEntry(
                 0,
                 v12,
                 VolumeExtension,
                 Irp,
                 &FileIdentifierDescriptor->Icb,
                 0,
                 0,
                 &InformationFcb);
      if ( status < 0 )
      {
LABEL_28:
        ExFreePool(FileName.Buffer);
        ExFreePool(FileIdentifierDescriptor);
        v2 = Irp;
        goto CleanupAndExit_32;
      }
      v16 = &InformationFcb->FileSize;
      v11[6].LowPart = InformationFcb->FileSize.LowPart;
      v11[6].HighPart = v16->HighPart;
      v11[5].LowPart = v16->LowPart;
      v11[5].HighPart = v16->HighPart;
      v17 = UdfxUdfTimestampToTime(&InformationFcb->ModifyTime);
      v11[4].LowPart = v17.LowPart;
      v11[3] = v17;
      v11[2].LowPart = v11[4].LowPart;
      v11[2].HighPart = v17.HighPart;
      v11[1].LowPart = v11[4].LowPart;
      v11[1].HighPart = v17.HighPart;
      v11[4].HighPart = v17.HighPart;
      v11[7].LowPart = 8 * (InformationFcb->Flags & 2) | 1;
      UdfxDereferenceFcb(v17.HighPart, v18, v15, InformationFcb);
    }
    v19 = FileName.Length;
    if ( FileName.Length <= ((v3->Parameters.Create.DesiredAccess - FileInformationBaseLength) & 0xFFFFFFFC) )
    {
      status = 0;
    }
    else
    {
      v19 = (v3->Parameters.Create.DesiredAccess - FileInformationBaseLength) & 0xFFFFFFFC;
      status = -2147483643;
    }
    v20 = FileName.Buffer;
    qmemcpy(v15, FileName.Buffer, 4 * (v19 >> 2));
    v22 = &v20[4 * (v19 >> 2)];
    v21 = &v15[v19 >> 2];
    v23 = FileInformationBaseLength;
    v24 = v19 & 3;
    qmemcpy(v21, v22, v24);
    v26 = (int)&v22[v24];
    v25 = (int *)((char *)v21 + v24);
    v27 = v19 + v23;
    Irp->IoStatus.Information = v27;
    if ( v27 > v3->Parameters.Create.DesiredAccess )
      RtlAssert(
        v19,
        (int)Irp,
        v25,
        v26,
        "Irp->IoStatus.Information <= IrpSp->Parameters.QueryDirectory.Length",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\dirctrl.c",
        0x297u,
        0);
    DirectoryEnumContext->QueryOffset += (FileIdentifierDescriptor->ImpUseLen
                                        + (unsigned __int8)FileIdentifierDescriptor->FileIDLen
                                        + 41) & 0xFFFFFFFC;
    goto LABEL_28;
  }
  if ( v9 == -1073741807 )
    status = InitialQuery_3 != 0 ? -1073741809 : -2147483642;
CleanupAndExit_32:
  RtlLeaveCriticalSectionAndRegion(v6, (_KEVENT *)&UdfxGlobalMutex);
  v28 = status;
  LOBYTE(v29) = 0;
  v2->IoStatus.Status = status;
  IofCompleteRequest(v2, v29, (int *)&v2->Type);
  return v28;
}