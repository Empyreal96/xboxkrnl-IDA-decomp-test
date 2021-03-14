void __userpurge IdexCdRomStartIo(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  char v6; // dl
  int v7; // ecx
  _IO_STACK_LOCATION *v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0xF23u,
      0);
  if ( HalIsResetOrShutdownPending() )
  {
    IdexChannelAbortCurrentPacket(v6, v7, a3, a4);
    return;
  }
  v8 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v8->MajorFunction == 2 )
  {
    IdexCdRomStartRead((unsigned __int8)v8->MajorFunction - 2, a3, Irp);
  }
  else
  {
    if ( v8->MajorFunction != 10 )
      IdexBugCheckWorker(0x10F78u, (unsigned int)Irp);
    v9 = v8->Parameters.FileSystemControl.FsControlCode;
    if ( v9 > 0x4D028 )
    {
      v16 = v9 - 3362816;
      if ( v16 )
      {
        v17 = v16 - 4;
        if ( v17 )
        {
          v18 = v17 - 4;
          if ( v18 )
          {
            v19 = v18 - 4;
            if ( !v19 )
            {
              IdexCdRomStartEndSession(Irp, a3);
              return;
            }
            v20 = v19 - 308;
            if ( !v20 )
            {
              IdexCdRomStartReadStructure(Irp);
              return;
            }
            if ( v20 != 32472 )
              goto LABEL_30;
          }
          IdexCdRomStartSendKey(Irp);
        }
        else
        {
          IdexCdRomStartReadKey(Irp);
        }
      }
      else
      {
        IdexCdRomStartStartSession(Irp, a3);
      }
    }
    else if ( v9 == 315432 )
    {
      IdexChannelStartIdePassThrough(315432, a3, Irp, 1, (void (__stdcall *)())IdexCdRomResetDevice);
    }
    else
    {
      v10 = v9 - 147456;
      if ( v10 && (v11 = v10 - 56) != 0 )
      {
        v12 = v11 - 6;
        if ( v12 )
        {
          v13 = v12 - 14;
          if ( v13 )
          {
            v14 = v13 - 56;
            if ( v14 )
            {
              v15 = v14 - 1916;
              if ( v15 )
              {
                if ( v15 == 165908 )
                {
                  IdexCdRomStartScsiPassThrough(Irp, 315432);
                  return;
                }
LABEL_30:
                IdexBugCheckWorker(0x10F72u, (unsigned int)Irp);
              }
              IdexCdRomStartCheckVerify(Irp);
            }
            else
            {
              IdexCdRomStartSetSpindleSpeed(Irp, a3, a4);
            }
          }
          else
          {
            IdexCdRomStartGetDriveGeometry(Irp, 315432);
          }
        }
        else
        {
          IdexCdRomStartRawRead(Irp, a3);
        }
      }
      else
      {
        IdexCdRomStartReadTOC(Irp, 315432, a3);
      }
    }
  }
}