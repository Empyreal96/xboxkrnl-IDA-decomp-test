int *__stdcall UdfxFsdCreate(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _UDF_VOLUME_EXTENSION *v2; // ebx
  _IO_STACK_LOCATION *v3; // esi
  _STRING *v4; // ecx
  int v5; // edx
  _FILE_OBJECT *v6; // eax
  _FILE_OBJECT *v7; // edi
  unsigned int v8; // edx
  char *v9; // ecx
  int *v10; // edi
  _UDF_FCB *v11; // esi
  _FILE_OBJECT *v12; // edi
  int v13; // eax
  int v14; // edx
  LONGAD ElementIcb; // [esp+Ch] [ebp-3Ch]
  _STRING ElementName; // [esp+1Ch] [ebp-2Ch]
  _STRING RemainingName; // [esp+24h] [ebp-24h]
  _SHARE_ACCESS ShareAccess; // [esp+2Ch] [ebp-1Ch]
  unsigned int DesiredAccess; // [esp+34h] [ebp-14h]
  _FILE_OBJECT *FileObject; // [esp+38h] [ebp-10h]
  _UDF_FCB *FoundOrNewFcb; // [esp+3Ch] [ebp-Ch]
  unsigned int CreateOptions; // [esp+40h] [ebp-8h]
  char TrailingBackslash; // [esp+47h] [ebp-1h]
  char CreateFcbCalled_3; // [esp+53h] [ebp+Bh]

  v2 = (_UDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = v3->Parameters.Create.RemainingName;
  v5 = *(_DWORD *)&v4->Length;
  DesiredAccess = v3->Parameters.Create.DesiredAccess;
  CreateOptions = v3->Parameters.Create.Options;
  v6 = v3->FileObject;
  *(_DWORD *)&RemainingName.Length = v5;
  RemainingName.Buffer = v4->Buffer;
  v7 = v6->RelatedFileObject;
  FileObject = v6;
  RtlEnterCriticalSectionAndRegion(&UdfxGlobalMutex);
  if ( !v2->Dismounted )
  {
    if ( v3->Flags & 4 || DesiredAccess & 0x50156 )
      goto LABEL_68;
    if ( CreateOptions & 0x2000 )
    {
      v10 = (int *)-1073741822;
      goto CleanupAndExit_35;
    }
    if ( CreateOptions >> 24 != 1 && CreateOptions >> 24 != 3 )
    {
LABEL_68:
      v10 = (int *)-1073741790;
      goto CleanupAndExit_35;
    }
    if ( v7 )
    {
      v11 = (_UDF_FCB *)v7->FsContext;
      if ( !v11 || !(v11->Flags & 2) )
      {
        v10 = (int *)-1073741811;
        goto CleanupAndExit_35;
      }
      if ( RemainingName.Length )
      {
        v9 = RemainingName.Buffer;
        if ( *RemainingName.Buffer != 92 )
          goto LABEL_15;
LABEL_25:
        v10 = (int *)-1073741773;
        goto CleanupAndExit_35;
      }
    }
    else
    {
      if ( !RemainingName.Length )
      {
        v11 = v2->VolumeFcb;
        if ( CreateOptions & 1 )
        {
          v10 = (int *)-1073741565;
          goto CleanupAndExit_35;
        }
        v12 = FileObject;
        v12->Flags |= 4u;
        ++v11->ReferenceCount;
        goto InitializeFileObject_0;
      }
      v9 = RemainingName.Buffer;
      v11 = v2->RootDirectoryFcb;
      if ( *RemainingName.Buffer != 92 )
        goto LABEL_25;
      if ( RemainingName.Length != 1 )
      {
LABEL_15:
        if ( RemainingName.Length <= 0u )
          RtlAssert(
            v8,
            (int)v9,
            (int *)"RemainingName.Length > 0",
            (int)v11,
            "RemainingName.Length > 0",
            "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
            0x2B4u,
            0);
        if ( RemainingName.Buffer[RemainingName.Length - 1] == 92 )
        {
          --RemainingName.Length;
          TrailingBackslash = 1;
        }
        else
        {
          TrailingBackslash = 0;
        }
        if ( !RemainingName.Length )
          RtlAssert(
            v8,
            (int)RemainingName.Buffer,
            (int *)"RemainingName.Length > 0",
            (int)v11,
            "RemainingName.Length > 0",
            "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
            0x2BEu,
            0);
        while ( 1 )
        {
          ObDissectName(RemainingName, &ElementName, &RemainingName);
          v10 = 0;
          if ( RemainingName.Length )
          {
            if ( *RemainingName.Buffer == 92 )
              break;
          }
          if ( !UdfxFindOpenChildFcb(v11, &ElementName, &FoundOrNewFcb) )
            break;
          v11 = FoundOrNewFcb;
          if ( !RemainingName.Length )
          {
            ++FoundOrNewFcb->ReferenceCount;
OpenCurrentFcb_1:
            if ( !(v11->Flags & 2) )
            {
              if ( TrailingBackslash || CreateOptions & 1 )
                v10 = (int *)-1073741565;
              goto LABEL_63;
            }
            goto OpenStartDirectoryFcb_1;
          }
        }
        CreateFcbCalled_3 = 0;
        while ( 1 )
        {
          if ( CreateFcbCalled_3 )
          {
            ObDissectName(RemainingName, &ElementName, &RemainingName);
            if ( RemainingName.Length )
            {
              if ( *RemainingName.Buffer == 92 )
              {
                v10 = (int *)-1073741773;
                goto LABEL_57;
              }
            }
          }
          v13 = UdfxLookupElementNameInDirectory(v8, (int)v9, v10, v2, Irp, v11, &ElementName, &ElementIcb);
          v10 = (int *)v13;
          if ( v13 < 0 )
            break;
          v10 = (int *)UdfxCreateFcbFromFileEntry((int)v9, v8, v2, Irp, &ElementIcb, v11, &ElementName, &FoundOrNewFcb);
          if ( (signed int)v10 < 0 )
            goto LABEL_57;
          if ( CreateFcbCalled_3 )
          {
            if ( v11->ReferenceCount < 2 )
              RtlAssert(
                v8,
                (int)v9,
                v10,
                (int)v11,
                "CurrentFcb->ReferenceCount >= 2",
                "d:\\xbox-apr03\\private\\ntos\\udfx\\create.c",
                0x338u,
                0);
            --v11->ReferenceCount;
          }
          v11 = FoundOrNewFcb;
          CreateFcbCalled_3 = 1;
          if ( !RemainingName.Length )
            goto LABEL_56;
          if ( !(FoundOrNewFcb->Flags & 2) )
            goto LABEL_55;
        }
        if ( v13 != -1073741772 )
          goto LABEL_56;
        if ( !RemainingName.Length )
          goto LABEL_57;
LABEL_55:
        v10 = (int *)-1073741766;
LABEL_56:
        if ( (signed int)v10 >= 0 )
          goto OpenCurrentFcb_1;
LABEL_57:
        if ( !CreateFcbCalled_3 )
          goto CleanupAndExit_35;
LABEL_58:
        UdfxDereferenceFcb(v8, (int)v9, v10, v11);
        goto CleanupAndExit_35;
      }
    }
    ++v11->ReferenceCount;
    v10 = 0;
OpenStartDirectoryFcb_1:
    if ( CreateOptions & 0x40 )
      v10 = (int *)-1073741638;
LABEL_63:
    if ( (signed int)v10 < 0 )
      goto LABEL_58;
    v12 = FileObject;
InitializeFileObject_0:
    IoSetShareAccess((int *)&v12->Type, (int)v11, DesiredAccess, 0, v12, &ShareAccess);
    v12->FsContext2 = 0;
    v12->FsContext = v11;
    ++v2->FileObjectCount;
    Irp->IoStatus.Information = 1;
    v10 = 0;
    goto CleanupAndExit_35;
  }
  v10 = (int *)-1073741202;
CleanupAndExit_35:
  RtlLeaveCriticalSectionAndRegion(v9, (_KEVENT *)&UdfxGlobalMutex);
  LOBYTE(v14) = 0;
  Irp->IoStatus.Status = (int)v10;
  IofCompleteRequest(Irp, v14, v10);
  return v10;
}