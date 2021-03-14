int __userpurge NtFreeVirtualMemory@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void **BaseAddress, unsigned int *RegionSize, unsigned int FreeType)
{
  signed int v7; // esi
  unsigned int v8; // ebx
  int v9; // ebx
  unsigned int v10; // esi
  unsigned int v11; // ebx
  _MMADDRESS_NODE *v12; // eax
  void *v13; // ecx
  _MMVAD *v14; // edi
  signed int v15; // esi
  unsigned int v16; // eax
  _MMVAD *v17; // eax
  int v19; // ecx
  unsigned int v20; // esi
  unsigned int v21; // eax
  unsigned int v22; // ecx
  _DWORD *v23; // ecx
  unsigned int v24; // ecx
  int v25; // eax
  unsigned int *v26; // esi
  unsigned int v27; // ecx
  void *v28; // ecx
  _MMPTE *StartingPte; // [esp+0h] [ebp-18h]
  unsigned int CapturedRegionSize; // [esp+4h] [ebp-14h]
  unsigned int CapturedBase; // [esp+8h] [ebp-10h]
  int *CapturedBasea; // [esp+8h] [ebp-10h]
  char *StartingAddress; // [esp+Ch] [ebp-Ch]
  _MMVAD *Vad; // [esp+10h] [ebp-8h]
  unsigned int Vada; // [esp+10h] [ebp-8h]
  char OldIrql; // [esp+17h] [ebp-1h]
  char FullTlbFlush_3; // [esp+2Bh] [ebp+13h]

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
      0x2D9u,
      0);
  if ( FreeType & 0xFFFF3FFF )
    return -1073741811;
  if ( !(FreeType & 0xC000) )
    return -1073741811;
  if ( (FreeType & 0xC000) == 49152 )
    return -1073741811;
  v7 = (signed int)*BaseAddress;
  v8 = *RegionSize;
  CapturedBase = (unsigned int)*BaseAddress;
  CapturedRegionSize = *RegionSize;
  if ( (unsigned int)*BaseAddress > 0x7FFEFFFF || 2147418111 - v7 < v8 )
    return -1073741811;
  v9 = v8 + v7 - 1;
  v10 = v7 & 0xFFFFF000;
  v11 = v9 | 0xFFF;
  StartingAddress = (char *)v10;
  RtlEnterCriticalSectionAndRegion(&MmAddressSpaceLock);
  v12 = MiLocateAddress((void *)v10);
  v14 = (_MMVAD *)v12;
  Vad = (_MMVAD *)v12;
  if ( !v12 )
  {
    v15 = -1073741664;
ErrorReturn_1:
    RtlLeaveCriticalSectionAndRegion(v13, (_KEVENT *)&MmAddressSpaceLock);
    return v15;
  }
  v16 = v12->EndingVpn;
  v13 = (void *)(v11 >> 12);
  if ( v16 < v11 >> 12 )
  {
    v15 = -1073741798;
    goto ErrorReturn_1;
  }
  if ( (FreeType & 0x8000) == 0 )
    goto LABEL_29;
  if ( !CapturedRegionSize )
  {
    v13 = (void *)v14->StartingVpn;
    if ( CapturedBase >> 12 != v14->StartingVpn )
    {
      v15 = -1073741665;
      goto ErrorReturn_1;
    }
    StartingAddress = (char *)(v14->StartingVpn << 12);
    v11 = (v16 << 12) | 0xFFF;
    MiRemoveVad(v14);
    ExFreePool(v14);
    goto LABEL_27;
  }
  if ( v10 >> 12 == v14->StartingVpn )
  {
    if ( v13 == (void *)v16 )
    {
      MiRemoveVad(v14);
      ExFreePool(v14);
    }
    else
    {
      v14->StartingVpn = (v11 + 1) >> 12;
    }
    goto LABEL_28;
  }
  if ( v13 != (void *)v16 )
  {
    v17 = (_MMVAD *)ExAllocatePoolWithTag(v10 >> 12, (int)v13, v10, 0x18u, 0x53646156u);
    if ( !v17 )
    {
      v15 = -1073741670;
      goto ErrorReturn_1;
    }
    qmemcpy(v17, v14, sizeof(_MMVAD));
    Vad->EndingVpn = (v10 - 1) >> 12;
    v19 = (v11 + 1) >> 12;
    v17->StartingVpn = v19;
    MiInsertVad((int)Vad, v19, (int *)&v17[1], v17);
LABEL_27:
    v10 = (unsigned int)StartingAddress;
    goto LABEL_28;
  }
  v14->EndingVpn = (v10 - 1) >> 12;
LABEL_28:
  MmVirtualMemoryBytesReserved = MmVirtualMemoryBytesReserved + v10 - v11 - 1;
LABEL_29:
  CapturedBasea = 0;
  OldIrql = KeRaiseIrqlToDpcLevel();
  v20 = ((v10 >> 10) & 0x3FFFFC) - 0x40000000;
  v21 = ((v11 >> 10) & 0x3FFFFC) - 0x40000000;
  v22 = v20;
  StartingPte = (_MMPTE *)v20;
  Vada = v20;
  FullTlbFlush_3 = 0;
  if ( v20 > v21 )
    goto LABEL_43;
  do
  {
    if ( v22 == v20 || !(v22 & 0xFFF) )
    {
      v23 = (_DWORD *)(((v22 >> 10) & 0x3FFFFC) - 0x40000000);
      if ( !(*v23 & 1) )
      {
        Vada = (_DWORD)(v23 + 1) << 10;
        goto LABEL_40;
      }
      CapturedBasea = (int *)(4 * (*v23 >> 12) - 2080440320);
    }
    v24 = *(_DWORD *)Vada;
    if ( *(_DWORD *)Vada )
    {
      *(_DWORD *)Vada = 0;
      __invlpg((void *)(Vada << 10));
      MiReleasePageOwnership(v24 >> 12, Vada);
      v25 = *CapturedBasea ^ (*CapturedBasea ^ ((((unsigned int)*CapturedBasea >> 17) - 1) << 17)) & 0xFFE0000;
      *CapturedBasea = v25;
      if ( !(v25 & 0xFFE0000) )
      {
        v26 = (unsigned int *)(((Vada >> 10) & 0x3FFFFC) - 0x40000000);
        v27 = *v26;
        *v26 = 0;
        FullTlbFlush_3 = 1;
        MiReleasePageOwnership(v27 >> 12, (int)CapturedBasea);
        v21 = ((v11 >> 10) & 0x3FFFFC) - 0x40000000;
        Vada = (_DWORD)(v26 + 1) << 10;
        v20 = (unsigned int)StartingPte;
        goto LABEL_40;
      }
      v21 = ((v11 >> 10) & 0x3FFFFC) - 0x40000000;
    }
    Vada += 4;
LABEL_40:
    v22 = Vada;
  }
  while ( Vada <= v21 );
  if ( FullTlbFlush_3 )
    KeFlushCurrentTb();
LABEL_43:
  KfLowerIrql(OldIrql);
  RtlLeaveCriticalSectionAndRegion(v28, (_KEVENT *)&MmAddressSpaceLock);
  *RegionSize = v11 - (_DWORD)StartingAddress + 1;
  *BaseAddress = StartingAddress;
  return 0;
}