int __stdcall GdfxFsdDirectoryControl(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v2; // ebx
  _IO_STACK_LOCATION *v3; // esi
  int v4; // edi
  _GDF_FCB *v5; // eax
  int v6; // edx
  void *v7; // ecx
  unsigned int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edx
  unsigned int v12; // edi
  _DWORD *v13; // edx
  _GDF_FCB *v14; // ebx
  bool v15; // zf
  char *v16; // edi
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // edx
  char *v21; // edi
  char *v22; // esi
  unsigned int v23; // eax
  int v24; // ecx
  int v25; // esi
  unsigned int v26; // eax
  int v27; // esi
  int v28; // edx
  unsigned int DirectoryByteOffset; // [esp+Ch] [ebp-20h]
  _IO_STACK_LOCATION *IrpSp; // [esp+10h] [ebp-1Ch]
  unsigned int FileInformationClass; // [esp+14h] [ebp-18h]
  _GDF_VOLUME_EXTENSION *VolumeExtension; // [esp+18h] [ebp-14h]
  _GDF_FCB *DirectoryFcb; // [esp+1Ch] [ebp-10h]
  _DIRECTORY_ENUM_CONTEXT *DirectoryEnumContext; // [esp+20h] [ebp-Ch]
  unsigned int FileInformationBaseLength; // [esp+24h] [ebp-8h]
  int status; // [esp+28h] [ebp-4h]
  char InitialQuery_3; // [esp+37h] [ebp+Bh]

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = (int)v3->FileObject;
  VolumeExtension = (_GDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v5 = *(_GDF_FCB **)(v4 + 8);
  IrpSp = v3;
  DirectoryFcb = v5;
  RtlEnterCriticalSectionAndRegion(&GdfxGlobalMutex);
  if ( DirectoryFcb->Flags & 2 )
  {
    v8 = v3->Parameters.Read.ByteOffset.LowPart;
    FileInformationClass = v8;
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 != 11 )
      {
        status = -1073741821;
        goto CleanupAndExit_23;
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
    }
    else
    {
      DirectoryEnumContext = *(_DIRECTORY_ENUM_CONTEXT **)(v4 + 12);
      if ( DirectoryEnumContext )
      {
        InitialQuery_3 = 0;
      }
      else
      {
        status = IoCreateDirectoryEnumContext(
                   v6,
                   (int)v3,
                   v3->Parameters.QueryDirectory.FileName,
                   &DirectoryEnumContext);
        if ( status < 0 )
          goto CleanupAndExit_23;
        *(_DWORD *)(v4 + 12) = DirectoryEnumContext;
        InitialQuery_3 = 1;
      }
      if ( v3->Flags & 1 )
        DirectoryEnumContext->QueryOffset = 0;
      v10 = GdfxFindNextDirectoryEntry(
              v6,
              (int)v7,
              (int *)v4,
              VolumeExtension,
              Irp,
              DirectoryFcb,
              DirectoryEnumContext,
              (_GDF_DIRECTORY_ENTRY **)&DirectoryFcb,
              &DirectoryByteOffset);
      status = v10;
      if ( v10 < 0 )
      {
        if ( v10 == -1073741807 )
          status = InitialQuery_3 != 0 ? -1073741809 : -2147483642;
      }
      else
      {
        v12 = FileInformationBaseLength;
        if ( v3->Parameters.Create.DesiredAccess < FileInformationBaseLength )
          RtlAssert(
            v11,
            (int)v7,
            (int *)FileInformationBaseLength,
            (int)v3,
            "IrpSp->Parameters.QueryDirectory.Length >= FileInformationBaseLength",
            "d:\\xbox-apr03\\private\\ntos\\gdfx\\dirctrl.c",
            0x16Eu,
            0);
        v13 = Irp->UserBuffer;
        memset(v13, 0, v12);
        v14 = DirectoryFcb;
        v15 = FileInformationClass == 1;
        v16 = (char *)&v13[FileInformationBaseLength / 4];
        v13[FileInformationBaseLength / 4 - 1] = BYTE1(DirectoryFcb->ParentFcb);
        if ( v15 )
        {
          v17 = VolumeExtension->TimeStamp.LowPart;
          v18 = VolumeExtension->TimeStamp.HighPart;
          v13[2] = v17;
          v13[3] = v18;
          v13[4] = v17;
          v13[5] = v18;
          v13[6] = v17;
          v13[7] = v18;
          v13[8] = v17;
          v13[9] = v18;
          if ( (_DWORD)v14->ParentFcb & 0x10 )
          {
            v19 = 0;
            v13[14] = 17;
          }
          else
          {
            v13[14] = 1;
            v19 = v14->ReferenceCount;
          }
          v13[11] = 0;
          v13[13] = 0;
          v13[10] = v19;
          v13[12] = v19;
        }
        v20 = BYTE1(v14->ParentFcb);
        if ( v20 <= ((v3->Parameters.Create.DesiredAccess - FileInformationBaseLength) & 0xFFFFFFFC) )
        {
          status = 0;
        }
        else
        {
          v20 = (v3->Parameters.Create.DesiredAccess - FileInformationBaseLength) & 0xFFFFFFFC;
          status = -2147483643;
        }
        qmemcpy(v16, (char *)&v14->ParentFcb + 2, 4 * (v20 >> 2));
        v22 = (char *)&v14->ParentFcb + 4 * (v20 >> 2) + 2;
        v21 = &v16[4 * (v20 >> 2)];
        v23 = FileInformationBaseLength;
        v24 = v20 & 3;
        qmemcpy(v21, v22, v24);
        v25 = (int)&v22[v24];
        v4 = (int)&v21[v24];
        v26 = v20 + v23;
        Irp->IoStatus.Information = v26;
        if ( v26 > IrpSp->Parameters.Create.DesiredAccess )
          RtlAssert(
            v20,
            (int)IrpSp,
            (int *)v4,
            v25,
            "Irp->IoStatus.Information <= IrpSp->Parameters.QueryDirectory.Length",
            "d:\\xbox-apr03\\private\\ntos\\gdfx\\dirctrl.c",
            0x1C8u,
            0);
        DirectoryEnumContext->QueryOffset = DirectoryByteOffset + ((BYTE1(v14->ParentFcb) + 17) & 0xFFFFFFFC);
        FscUnmapBuffer((int *)v4, v25, v14);
        v2 = Irp;
      }
    }
  }
  else
  {
    status = -1073741811;
  }
CleanupAndExit_23:
  RtlLeaveCriticalSectionAndRegion(v7, (_KEVENT *)&GdfxGlobalMutex);
  v27 = status;
  LOBYTE(v28) = 0;
  v2->IoStatus.Status = status;
  IofCompleteRequest(v2, v28, (int *)v4);
  return v27;
}