void __fastcall IdexChannelPrepareBufferTransfer(char *Buffer, unsigned int ByteCount)
{
  unsigned int v2; // esi
  int v3; // edx
  int v4; // ecx
  unsigned int v5; // ebx
  _IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *v6; // esi
  unsigned int v7; // eax
  unsigned int CurrentPhysicalAddress; // [esp+Ch] [ebp-14h]
  _IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *PhysicalRegionDescriptor; // [esp+10h] [ebp-10h]
  unsigned int BytesRemaining; // [esp+14h] [ebp-Ch]
  int RegionPhysicalAddress; // [esp+18h] [ebp-8h]
  char *BaseAddress; // [esp+1Ch] [ebp-4h]
  char *BaseAddressa; // [esp+1Ch] [ebp-4h]

  v2 = ByteCount;
  BaseAddress = Buffer;
  if ( !ByteCount || ByteCount > 0x20000 )
    RtlAssert(
      ByteCount,
      (int)Buffer,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      ByteCount,
      "(ByteCount > 0) && (ByteCount <= IDE_ATA_MAXIMUM_TRANSFER_BYTES)",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0xE9u,
      0);
  PhysicalRegionDescriptor = IdexChannelPhysicalRegionDescriptorTable;
  RegionPhysicalAddress = MmGetPhysicalAddress(
                            ByteCount,
                            (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
                            BaseAddress);
  v5 = 4096 - ((unsigned __int16)BaseAddress & 0xFFF);
  if ( v5 > v2 )
    v5 = v2;
  BaseAddressa = &BaseAddress[v5];
  v6 = (_IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *)(v2 - v5);
  BytesRemaining = (unsigned int)v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = MmGetPhysicalAddress(v3, (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c", BaseAddressa);
      v4 = RegionPhysicalAddress;
      v3 = v5 + RegionPhysicalAddress;
      CurrentPhysicalAddress = v7;
      if ( v5 + RegionPhysicalAddress != v7 || (RegionPhysicalAddress ^ v7) & 0xFFFF0000 )
      {
        if ( RegionPhysicalAddress & 1 )
          RtlAssert(
            v3,
            RegionPhysicalAddress,
            (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            (int)v6,
            "(RegionPhysicalAddress & IDE_ALIGNMENT_REQUIREMENT) == 0",
            "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            0x114u,
            0);
        if ( v5 & 1 )
          RtlAssert(
            v3,
            v4,
            (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            (int)v6,
            "(RegionByteCount & IDE_ALIGNMENT_REQUIREMENT) == 0",
            "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            0x115u,
            0);
        if ( v5 > 0x10000 )
          RtlAssert(
            v3,
            v4,
            (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            (int)v6,
            "RegionByteCount <= 0x10000",
            "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            0x116u,
            0);
        PhysicalRegionDescriptor->PhysicalAddress = RegionPhysicalAddress;
        PhysicalRegionDescriptor->ByteCount.AsULong = (unsigned __int16)v5;
        v6 = PhysicalRegionDescriptor + 1;
        PhysicalRegionDescriptor = v6;
        if ( v6 > (_IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *)&unk_8004BA48 )
          RtlAssert(
            v3,
            v4,
            (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            (int)v6,
            "PhysicalRegionDescriptor <= EndingPhysicalRegionDescriptor",
            "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
            0x11Cu,
            0);
        RegionPhysicalAddress = CurrentPhysicalAddress;
        v5 = 0;
      }
      else
      {
        v6 = PhysicalRegionDescriptor;
      }
      if ( BytesRemaining <= 0x1000 )
        break;
      BaseAddressa += 4096;
      v5 += 4096;
      BytesRemaining -= 4096;
    }
    v5 += BytesRemaining;
  }
  else
  {
    v6 = IdexChannelPhysicalRegionDescriptorTable;
  }
  if ( RegionPhysicalAddress & 1 )
    RtlAssert(
      v3,
      v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v6,
      "(RegionPhysicalAddress & IDE_ALIGNMENT_REQUIREMENT) == 0",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x13Au,
      0);
  if ( v5 & 1 )
    RtlAssert(
      v3,
      v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v6,
      "(RegionByteCount & IDE_ALIGNMENT_REQUIREMENT) == 0",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x13Bu,
      0);
  if ( v5 > 0x10000 )
    RtlAssert(
      v3,
      v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v6,
      "RegionByteCount <= 0x10000",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x13Cu,
      0);
  v6->PhysicalAddress = RegionPhysicalAddress;
  v6->ByteCount.AsULong = (unsigned __int16)v5 | 0x80000000;
  if ( v6 > (_IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *)&unk_8004BA48 )
    RtlAssert(
      v3,
      v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v6,
      "PhysicalRegionDescriptor <= EndingPhysicalRegionDescriptor",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x142u,
      0);
  __outdword(0xFF64u, unk_80051370);
  __outbyte(0xFF62u, 6u);
}