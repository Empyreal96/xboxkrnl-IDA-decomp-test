void __usercall IdexCdRomFinishReadKey(char a1@<dl>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _IRP *v4; // ebx
  _IO_STACK_LOCATION *v5; // esi
  void *v6; // edi
  USHORT v7; // ax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  _DVD_COPY_PROTECT_KEY *v10; // edi
  unsigned int v11; // ecx
  unsigned int *v12; // edi
  char *v13; // esi
  int v14; // ecx
  int *v15; // edi
  _DVD_COPY_PROTECT_KEY *v16; // ecx
  int v17; // edx
  unsigned int *v18; // edi
  int v19; // ecx
  int v20; // eax
  _DVD_COPY_PROTECT_KEY *CopyProtectKey; // [esp+0h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x762u,
      0);
  v4 = Irp;
  v5 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( Irp->IoStatus.Status == -1073741764 )
    Irp->IoStatus.Status = 0;
  if ( v4->IoStatus.Status >= 0 )
  {
    v6 = v4->UserBuffer;
    CopyProtectKey = (_DVD_COPY_PROTECT_KEY *)v4->UserBuffer;
    v7 = RtlUshortByteSwap(IdexCdRomStaticTransferBuffer);
    v8 = v7;
    if ( v7 > 2u )
      v8 = v7 - 2;
    v9 = v5->Parameters.Create.DesiredAccess - 24;
    if ( v8 < v9 )
      v9 = v8;
    qmemcpy(v6, v5->Parameters.Read.CacheBuffer, 0x18u);
    v10 = CopyProtectKey + 1;
    if ( CopyProtectKey->KeyType == 4 )
    {
      v11 = (v9 - 1) >> 2;
      qmemcpy(v10, &unk_80051305, 4 * v11);
      v13 = (char *)&unk_80051305 + 4 * v11;
      v12 = &v10->KeyLength + v11;
      v14 = ((_BYTE)v9 - 1) & 3;
      qmemcpy(v12, v13, v14);
      v15 = (int *)((char *)v12 + v14);
      v16 = CopyProtectKey;
      *((_BYTE *)&CopyProtectKey->Parameters.TitleOffset.QuadPart + v9 + 7) = 0;
      v17 = (unsigned __int8)byte_80051304[0];
      CopyProtectKey->KeyFlags = (unsigned __int8)byte_80051304[0];
    }
    else
    {
      v17 = v9;
      qmemcpy(v10, byte_80051304, 4 * (v9 >> 2));
      v18 = &v10->KeyLength + (v9 >> 2);
      v19 = v9 & 3;
      qmemcpy(v18, &byte_80051304[4 * (v9 >> 2)], v19);
      v15 = (int *)((char *)v18 + v19);
      v16 = CopyProtectKey;
    }
    v20 = v9 + 24;
    v16->KeyLength = v20;
    v4->IoStatus.Status = 0;
    LOBYTE(v17) = 1;
    v4->IoStatus.Information = v20;
    IofCompleteRequest(v4, v17, v15);
    dword_80051354();
  }
  else
  {
    IdexCdRomFinishGeneric(a1, a3, (int)v5);
  }
}