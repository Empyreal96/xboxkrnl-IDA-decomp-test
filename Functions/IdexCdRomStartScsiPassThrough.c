void __fastcall IdexCdRomStartScsiPassThrough(_IRP *Irp, int a2)
{
  _IRP *v2; // edi
  _IO_STACK_LOCATION *v3; // eax
  unsigned int v4; // ecx
  int v5; // esi
  unsigned int v6; // eax
  int v7; // ecx

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = v3->Parameters.Create.DesiredAccess;
  if ( v4 && v4 < 0x12
    || v3->Parameters.Read.ByteOffset.LowPart < 0x2C
    || (v5 = v3->Parameters.Create.Options, *(_WORD *)v5 != 44)
    || (v6 = *(_DWORD *)(v5 + 12), v6 > 0x20000)
    || (v7 = *(_DWORD *)(v5 + 20), v7 & 1)
    || v6 & 1 )
  {
    IdexChannelInvalidParameterRequest(v2, (int *)&v2->Type);
  }
  else
  {
    if ( v6 )
      MmLockUnlockBufferPages(a2, v7, (int *)&v2->Type, v5, (void *)v7, v6, 0);
    v2->IoStatus.Information = 0;
    IdexCdRomIssueAtapiRequest(
      a2,
      v7,
      (int *)&v2->Type,
      (_CDB *)(v5 + 28),
      *(void **)(v5 + 20),
      *(_DWORD *)(v5 + 12),
      *(_BYTE *)(v5 + 8) == 0,
      (void (__stdcall *)())IdexCdRomFinishScsiPassThrough);
  }
}