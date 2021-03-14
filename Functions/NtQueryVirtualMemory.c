int __userpurge NtQueryVirtualMemory@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *BaseAddress, _MEMORY_BASIC_INFORMATION *MemoryInformation)
{
  _MMADDRESS_NODE *v7; // ecx
  _MMADDRESS_NODE *v8; // edi
  unsigned int v9; // eax
  signed int v10; // edi
  _MMADDRESS_NODE *v11; // eax
  signed int v12; // ebx
  unsigned int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // ecx
  signed int v16; // eax
  char *v17; // ecx
  unsigned int v18; // ebx
  unsigned int AllocationProtect; // [esp+0h] [ebp-18h]
  _MMPTE *EndingPte; // [esp+4h] [ebp-14h]
  unsigned int Protect; // [esp+8h] [ebp-10h]
  int PteProtectionMask; // [esp+Ch] [ebp-Ch]
  signed int State; // [esp+14h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
      0x47Eu,
      0);
  if ( (unsigned int)BaseAddress > 0x7FFDFFFF )
    return -1073741811;
  RtlEnterCriticalSectionAndRegion(&MmAddressSpaceLock);
  v8 = MmVadRoot;
  v9 = (unsigned int)BaseAddress >> 12;
  while ( 1 )
  {
    if ( !v8 )
      goto LABEL_17;
    v7 = (_MMADDRESS_NODE *)v8->StartingVpn;
    if ( v9 < v8->StartingVpn )
    {
LABEL_9:
      v7 = v8->LeftChild;
      goto LABEL_12;
    }
    if ( v9 <= v8->EndingVpn )
      break;
    if ( v9 < (unsigned int)v7 )
      goto LABEL_9;
    if ( v9 < v8->EndingVpn )
      goto LABEL_16;
    v7 = v8->RightChild;
LABEL_12:
    if ( !v7 )
    {
LABEL_16:
      if ( v8 )
      {
        if ( v8->StartingVpn >= v9 )
        {
          v7 = (_MMADDRESS_NODE *)(v8->StartingVpn << 12);
          v10 = v8->StartingVpn << 12;
        }
        else
        {
          v11 = MiGetNextNode(v8);
          if ( v11 )
            v10 = v11->StartingVpn << 12;
          else
            v10 = 2147352576;
        }
      }
      else
      {
LABEL_17:
        v10 = 2147352576;
      }
      RtlLeaveCriticalSectionAndRegion(v7, (_KEVENT *)&MmAddressSpaceLock);
      MemoryInformation->AllocationBase = 0;
      MemoryInformation->AllocationProtect = 0;
      MemoryInformation->BaseAddress = (void *)((unsigned int)BaseAddress & 0xFFFFF000);
      MemoryInformation->RegionSize = v10 - ((unsigned int)BaseAddress & 0xFFFFF000);
      MemoryInformation->State = 0x10000;
      MemoryInformation->Protect = 1;
      MemoryInformation->Type = 0;
      return 0;
    }
    v8 = v7;
  }
  Protect = 0;
  PteProtectionMask = 0;
  v12 = 4194300;
  v13 = (((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000;
  AllocationProtect = v8[1].StartingVpn;
  v14 = 4 * (v8->EndingVpn & 0xFFFFF) - 0x40000000;
  v15 = v13;
  EndingPte = (_MMPTE *)(4 * (v8->EndingVpn & 0xFFFFF) - 0x40000000);
  if ( *(_BYTE *)(((v13 >> 10) & 0x3FFFFC) - 0x40000000) & 1 && *(_DWORD *)v13 )
  {
    State = 4096;
    PteProtectionMask = *(_DWORD *)v13 & 0x21B;
    v16 = MiDecodePteProtectionMask(PteProtectionMask);
    v14 = (unsigned int)EndingPte;
    Protect = v16;
    v15 = (((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000;
  }
  else
  {
    State = 0x2000;
  }
  if ( v13 > v14 )
  {
LABEL_42:
    v14 += 4;
    v15 = v14;
    goto LABEL_43;
  }
  while ( 2 )
  {
    if ( (v15 == v13 || !(v15 & 0xFFF)) && !(*(_BYTE *)(((v15 >> 10) & 0x3FFFFC) - 0x40000000) & 1) )
    {
      if ( State == 4096 )
        goto LABEL_41;
      v15 = ((v12 & (v15 >> 10)) - 0x40000000 + 4) << 10;
LABEL_40:
      if ( v15 > v14 )
        goto LABEL_41;
      continue;
    }
    break;
  }
  if ( !*(_DWORD *)v15 )
  {
    if ( State == 4096 )
      goto LABEL_41;
    goto LABEL_39;
  }
  if ( State != 0x2000 && (*(_DWORD *)v15 & 0x21B) == PteProtectionMask )
  {
LABEL_39:
    v15 += 4;
    goto LABEL_40;
  }
LABEL_41:
  if ( v15 > v14 )
    goto LABEL_42;
LABEL_43:
  v17 = (char *)(v15 << 10);
  v18 = (unsigned int)&v17[-((unsigned int)BaseAddress & 0xFFFFF000)];
  if ( v17 == (char *)((unsigned int)BaseAddress & 0xFFFFF000) )
    RtlAssert(
      v14,
      (int)v17,
      (int *)v8,
      -4096,
      "RegionSize > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\virtual.c",
      0x53Eu,
      0);
  RtlLeaveCriticalSectionAndRegion(v17, (_KEVENT *)&MmAddressSpaceLock);
  MemoryInformation->AllocationBase = (void *)(v8->StartingVpn << 12);
  MemoryInformation->AllocationProtect = AllocationProtect;
  MemoryInformation->BaseAddress = (void *)((unsigned int)BaseAddress & 0xFFFFF000);
  MemoryInformation->State = State;
  MemoryInformation->RegionSize = v18;
  MemoryInformation->Protect = Protect;
  MemoryInformation->Type = 0x20000;
  return 0;
}