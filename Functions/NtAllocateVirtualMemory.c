int __userpurge NtAllocateVirtualMemory@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void **BaseAddress, unsigned int ZeroBits, unsigned int *RegionSize, unsigned int AllocationType, unsigned int Protect)
{
  int *v10; // edi
  unsigned int v11; // ebx
  int v12; // edx
  void *v13; // ecx
  void *v14; // eax
  signed int v15; // esi
  _MMADDRESS_NODE *v16; // eax
  int v17; // edx
  unsigned int v18; // esi
  int v19; // edx
  _MMVAD *v20; // eax
  void *v21; // ecx
  unsigned int v22; // esi
  unsigned int v23; // esi
  unsigned int v24; // edi
  unsigned int v25; // edi
  _MMVAD *v26; // eax
  signed int v27; // edx
  _MMPTE *v28; // ebx
  unsigned int v29; // esi
  unsigned int v30; // eax
  char v31; // al
  int v32; // edx
  unsigned int v33; // ecx
  int i; // edi
  unsigned int *v35; // esi
  __int16 v36; // si
  unsigned int v37; // eax
  int v38; // esi
  unsigned int v39; // eax
  void *v40; // ecx
  int v41; // edx
  unsigned int OldProtect; // [esp+Ch] [ebp-54h]
  _MMPFN_BUSY_TYPE BusyType; // [esp+10h] [ebp-50h]
  _MMPTE *StartingPte; // [esp+14h] [ebp-4Ch]
  unsigned int PteProtectionMask; // [esp+1Ch] [ebp-44h]
  unsigned int (__fastcall *RemovePageRoutine)(_MMPFN_BUSY_TYPE, _MMPTE *); // [esp+20h] [ebp-40h]
  char *TopAddress; // [esp+24h] [ebp-3Ch]
  unsigned int EndVpn; // [esp+28h] [ebp-38h]
  char *StartingAddress; // [esp+2Ch] [ebp-34h]
  unsigned int CapturedRegionSize; // [esp+30h] [ebp-30h]
  _MMVAD *Vad; // [esp+34h] [ebp-2Ch]
  _MMPTE *EndingPte; // [esp+38h] [ebp-28h]
  _MMPTE *PointerPte; // [esp+3Ch] [ebp-24h]
  unsigned int PagesToCommit; // [esp+40h] [ebp-20h]
  char OldIrql; // [esp+45h] [ebp-1Bh]
  char DeleteVadOnFailure; // [esp+46h] [ebp-1Ah]
  char ChangeProtection; // [esp+47h] [ebp-19h]
  CPPEH_RECORD ms_exc; // [esp+48h] [ebp-18h]

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
      0xAFu,
      0);
  if ( ZeroBits > 0x15
    || AllocationType & 0xFF67CFFF
    || !(AllocationType & 0x83000)
    || AllocationType & 0x80000 && AllocationType != 0x80000 )
  {
    return -1073741811;
  }
  if ( !MiMakePteProtectionMask(Protect, &PteProtectionMask) )
    return -1073741755;
  v10 = (int *)*BaseAddress;
  v11 = *RegionSize;
  if ( (unsigned int)*BaseAddress > 0x7FFDFFFF || 2147352576 - (signed int)v10 < v11 || !v11 )
    return -1073741811;
  RtlEnterCriticalSectionAndRegion(&MmAddressSpaceLock);
  Vad = 0;
  DeleteVadOnFailure = 0;
  if ( v10 )
  {
    if ( !(AllocationType & 0x2000) )
    {
LABEL_32:
      v23 = ((unsigned int)v10 + v11 - 1) | 0xFFF;
      v24 = (unsigned int)v10 & 0xFFFFF000;
      StartingAddress = (char *)v24;
      v11 = v23 - v24 + 1;
      CapturedRegionSize = v23 - v24 + 1;
      EndVpn = v23 >> 12;
      v25 = v24 >> 12;
      v26 = (_MMVAD *)MiCheckForConflictingNode(v25, v23 >> 12, MmVadRoot);
      Vad = v26;
      if ( v26 )
      {
        if ( v25 >= v26->StartingVpn )
        {
          v13 = (void *)EndVpn;
          if ( EndVpn <= v26->EndingVpn )
          {
            if ( AllocationType == 0x80000 )
            {
              v15 = 0;
              goto ErrorReturn_0;
            }
            v27 = 4194300;
            v28 = (_MMPTE *)((((unsigned int)StartingAddress >> 10) & 0x3FFFFC) - 0x40000000);
            StartingPte = v28;
            EndingPte = (_MMPTE *)(((v23 >> 10) & 0x3FFFFC) - 0x40000000);
            PagesToCommit = 0;
            v29 = (((unsigned int)StartingAddress >> 10) & 0x3FFFFC) - 0x40000000;
            if ( v28 <= EndingPte )
            {
              do
              {
                if ( (_MMPTE *)v29 != v28 && v29 & 0xFFF || *(_BYTE *)(((v29 >> 10) & 0x3FFFFC) - 0x40000000) & 1 )
                {
                  if ( !*(_DWORD *)v29 )
                    ++PagesToCommit;
                  v29 += 4;
                }
                else
                {
                  v30 = ((v27 & (v29 >> 10)) - 0x40000000 + 4) << 10;
                  ++PagesToCommit;
                  if ( v30 <= (unsigned int)EndingPte )
                    PagesToCommit += (signed int)(v30 - v29) >> 2;
                  else
                    PagesToCommit += ((signed int)((signed int)EndingPte - v29) >> 2) + 1;
                  v29 = ((v27 & (v29 >> 10)) - 0x40000000 + 4) << 10;
                }
              }
              while ( v29 <= (unsigned int)EndingPte );
            }
            v31 = KeRaiseIrqlToDpcLevel();
            OldIrql = v31;
            v33 = PagesToCommit;
            if ( MmAvailablePages < PagesToCommit )
            {
              KfLowerIrql(v31);
              v15 = -1073741801;
              v11 = CapturedRegionSize;
              goto ErrorReturn_0;
            }
            RemovePageRoutine = MiRemoveAnyPage;
            if ( (AllocationType & 0x800000) == 0 )
              RemovePageRoutine = (unsigned int (__fastcall *)(_MMPFN_BUSY_TYPE, _MMPTE *))MiRemoveZeroPage;
            BusyType = (Protect & 0xF0) != 0 ? 7 : 5;
            ChangeProtection = 0;
            PointerPte = v28;
            for ( i = 0; PointerPte <= EndingPte; ++PointerPte )
            {
              if ( PointerPte == StartingPte || !((unsigned __int16)PointerPte & 0xFFF) )
              {
                v35 = (unsigned int *)((((unsigned int)PointerPte >> 10) & 0x3FFFFC) - 0x40000000);
                if ( !(*(_BYTE *)v35 & 1) )
                {
                  --PagesToCommit;
                  *v35 = (MiRemoveZeroPage(
                            MmVirtualPageTableUsage,
                            (_MMPTE *)((((unsigned int)PointerPte >> 10) & 0x3FFFFC) - 0x40000000),
                            (int *)i) << 12) | 0x67;
                }
                i = 4 * (*v35 >> 12) - 2080440320;
                if ( !(*(_BYTE *)(i + 2) & 1) )
                  RtlAssert(
                    v32,
                    v33,
                    (int *)i,
                    (int)v35,
                    "PdePageFrame->Busy.Busy == 1",
                    "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
                    0x24Fu,
                    0);
                if ( (*(_DWORD *)i & 0xF0000000) != 0x20000000 )
                  RtlAssert(
                    v32,
                    v33,
                    (int *)i,
                    (int)v35,
                    "PdePageFrame->Busy.BusyType == MmVirtualPageTableUsage",
                    "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
                    0x250u,
                    0);
              }
              if ( PointerPte->Long )
              {
                if ( (PointerPte->Long & 0x21B) != PteProtectionMask )
                  ChangeProtection = 1;
              }
              else
              {
                --PagesToCommit;
                v36 = PteProtectionMask;
                v37 = RemovePageRoutine(BusyType, PointerPte);
                v38 = v36 & 0xFFF;
                PointerPte->Long = v38 | (v37 << 12);
                v33 = *(_DWORD *)i;
                v39 = *(_DWORD *)i ^ (*(_DWORD *)i ^ ((*(_DWORD *)i & 0xFFFE0000) + 0x20000)) & 0xFFE0000;
                *(_DWORD *)i = v39;
                if ( (v39 & 0xFFE0000) > 0x8000000 )
                  RtlAssert(
                    v32,
                    v33,
                    (int *)i,
                    v38,
                    "PdePageFrame->Directory.NumberOfUsedPtes <= PTE_PER_PAGE",
                    "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
                    0x25Eu,
                    0);
              }
            }
            if ( PagesToCommit )
              RtlAssert(
                v32,
                v33,
                (int *)i,
                0,
                "PagesToCommit == 0",
                "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
                0x268u,
                0);
            if ( !i || !(*(_DWORD *)i & 0xFFE0000) )
              RtlAssert(
                v32,
                v33,
                (int *)i,
                0,
                "PdePageFrame != NULL && PdePageFrame->Directory.NumberOfUsedPtes > 0",
                "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
                0x269u,
                0);
            if ( Protect & 0x600 )
              KeFlushCurrentTbAndInvalidateAllCaches();
            KfLowerIrql(OldIrql);
            RtlLeaveCriticalSectionAndRegion(v40, (_KEVENT *)&MmAddressSpaceLock);
            *RegionSize = CapturedRegionSize;
            *BaseAddress = StartingAddress;
            if ( ChangeProtection )
              NtProtectVirtualMemory(
                v41,
                (int)BaseAddress,
                (int *)i,
                0,
                (void **)&StartingAddress,
                &CapturedRegionSize,
                Protect,
                &OldProtect);
            return 0;
          }
        }
      }
LABEL_78:
      v15 = -1073741800;
      goto ErrorReturn_0;
    }
    if ( v10 )
    {
      v18 = ((unsigned int)v10 + v11 - 1) | 0xFFF;
      v10 = (int *)((unsigned int)v10 & 0xFFFF0000);
      if ( MiCheckForConflictingNode((unsigned int)v10 >> 12, v18 >> 12, MmVadRoot) )
        goto LABEL_78;
      goto LABEL_27;
    }
  }
  v11 = (v11 + 4095) & 0xFFFFF000;
  CapturedRegionSize = v11;
  v13 = (void *)ZeroBits;
  if ( !ZeroBits )
  {
    v14 = (void *)2147352575;
    TopAddress = (char *)2147352575;
LABEL_21:
    ms_exc.registration.TryLevel = 0;
    if ( AllocationType & 0x100000 )
      v16 = (_MMADDRESS_NODE *)MiFindEmptyAddressRangeDownTree(ZeroBits, v12, v11, v14, 0x10000u, MmVadRoot);
    else
      v16 = MiFindEmptyAddressRange(ZeroBits, v12, v11, 0x10000u, ZeroBits);
    v10 = (int *)v16;
    StartingAddress = (char *)v16;
    ms_exc.registration.TryLevel = -1;
    v18 = ((unsigned int)v16 + v11 - 1) | 0xFFF;
    if ( v18 > (unsigned int)TopAddress )
    {
      v15 = -1073741801;
      goto ErrorReturn_0;
    }
LABEL_27:
    Vad = (_MMVAD *)ExAllocatePoolWithTag(v17, (int)v13, v18, 0x18u, 0x53646156u);
    if ( !Vad )
    {
      v15 = -1073741670;
      goto ErrorReturn_0;
    }
    v20 = Vad;
    Vad->StartingVpn = (unsigned int)v10 >> 12;
    v20->EndingVpn = v18 >> 12;
    v20->AllocationProtect = Protect;
    MiInsertVad(v19, Protect, v10, v20);
    v22 = v18 - (_DWORD)v10 + 1;
    v11 = v22;
    MmVirtualMemoryBytesReserved += v22;
    if ( !(AllocationType & 0x1000) )
    {
      RtlLeaveCriticalSectionAndRegion(v21, (_KEVENT *)&MmAddressSpaceLock);
      *RegionSize = v22;
      *BaseAddress = v10;
      return 0;
    }
    DeleteVadOnFailure = 1;
    goto LABEL_32;
  }
  v14 = (void *)(0xFFFFFFFF >> ZeroBits);
  TopAddress = (char *)(0xFFFFFFFF >> ZeroBits);
  if ( 0xFFFFFFFF >> ZeroBits <= 0x7FFDFFFF )
    goto LABEL_21;
  v15 = -1073741811;
ErrorReturn_0:
  if ( v15 < 0 )
  {
    if ( DeleteVadOnFailure )
    {
      MmVirtualMemoryBytesReserved -= v11;
      MiRemoveVad(Vad);
      ExFreePool(Vad);
    }
  }
  RtlLeaveCriticalSectionAndRegion(v13, (_KEVENT *)&MmAddressSpaceLock);
  return v15;
}