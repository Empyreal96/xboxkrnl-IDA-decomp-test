void __usercall IdexCdRomFinishScsiPassThrough(char a1@<dl>, int *a2@<edi>, int a3@<esi>)
{
  int v3; // eax
  unsigned int v4; // ecx

  v3 = *(_DWORD *)(Irp->Tail.Overlay.PacketType + 8);
  v4 = *(_DWORD *)(v3 + 12);
  if ( v4 )
    MmLockUnlockBufferPages(a1, v4, a2, a3, *(void **)(v3 + 20), v4, 1);
  IdexCdRomFinishGeneric(a1, a2, a3);
}