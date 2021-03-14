void __usercall IdexCdRomFinishRead(char a1@<dl>, int *a2@<edi>)
{
  _IRP *v2; // ecx
  _IO_STACK_LOCATION *v3; // esi
  int v4; // edi
  int v5; // eax
  unsigned int v6; // edx
  _DEVICE_OBJECT *v7; // ST10_4
  int v8; // edx
  int *v9; // [esp-4h] [ebp-Ch]

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  ++IdexCdRomDebugReadsFinished;
  if ( Irp->IoStatus.Status >= 0 )
  {
    v9 = a2;
    v4 = unk_8004C824;
    if ( unk_8004C824 )
    {
      if ( *(_BYTE *)(unk_8004C824 + 8) & 0x20 )
      {
        v5 = *(_DWORD *)(unk_8004C824 + 60);
        if ( v5 )
        {
          if ( *(_BYTE *)(v5 + 11) < 0 )
          {
            v2 = Irp;
            *(_DWORD *)(*(_DWORD *)(unk_8004C824 + 60) + 12) = __rdtsc() / 0x2DD - **(_DWORD **)(unk_8004C824 + 60);
            *(_DWORD *)(v4 + 60) += 16;
          }
        }
      }
    }
    IdexCdRomDebugLastReadSectorNumber = v3->Parameters.Read.ByteOffset.LowPart;
    v6 = v3->Parameters.Create.DesiredAccess;
    if ( v6 <= 0x20000 )
    {
      v2->IoStatus.Status = 0;
      LOBYTE(v6) = 1;
      IofCompleteRequest(v2, v6, v9);
    }
    else
    {
      v3->Parameters.Read.ByteOffset.HighPart += 0x20000;
      v3->Parameters.Read.ByteOffset.LowPart += 64;
      v7 = v3->DeviceObject;
      v8 = v6 - 0x20000;
      v3->Parameters.Create.DesiredAccess = v8;
      dword_80051350(v2, v8, v7, v2);
    }
    dword_80051354();
  }
  else
  {
    IdexCdRomFinishGeneric(a1, a2, (int)v3);
  }
}