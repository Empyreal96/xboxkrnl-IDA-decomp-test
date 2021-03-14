int *__userpurge IdexCdRomDeviceControl@<eax>(int a1@<esi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v3; // eax
  unsigned int v4; // edx
  int v5; // edx
  bool v6; // zf
  int *v7; // esi

  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = v3->Parameters.FileSystemControl.FsControlCode;
  if ( v4 > 0x4D014 )
  {
    v4 -= 315432;
    if ( v4 )
    {
      v4 -= 3047384;
      if ( v4 )
      {
        v4 -= 4;
        if ( v4 )
        {
          v4 -= 4;
          if ( v4 )
          {
            v4 -= 4;
            if ( v4 )
            {
              v4 -= 308;
              if ( v4 )
              {
                v4 -= 32472;
                v6 = v4 == 0;
LABEL_18:
                if ( !v6 )
                {
                  v7 = (int *)-1073741808;
LABEL_22:
                  LOBYTE(v4) = 0;
                  Irp->IoStatus.Status = (int)v7;
                  IofCompleteRequest(Irp, v4, (int *)&Irp->Type);
                  return v7;
                }
                goto LABEL_20;
              }
            }
          }
        }
      }
    }
  }
  else if ( v4 != 315412 )
  {
    v4 -= 147456;
    if ( v4 )
    {
      v4 -= 56;
      if ( v4 )
      {
        v4 -= 6;
        if ( v4 )
        {
          v4 -= 14;
          if ( v4 )
          {
            v5 = v4 - 52;
            if ( !v5 )
            {
              v7 = IdexCdRomAuthenticationSequence(0, 315412, (int *)&Irp->Type, a1);
              goto LABEL_21;
            }
            v4 = v5 - 4;
            if ( v4 )
            {
              v4 -= 1916;
              v6 = v4 == 0;
              goto LABEL_18;
            }
          }
        }
      }
    }
  }
LABEL_20:
  v3->Control |= 1u;
  dword_80051350(315412, v4, DeviceObject, Irp);
  v7 = (int *)259;
LABEL_21:
  if ( v7 != (int *)259 )
    goto LABEL_22;
  return v7;
}