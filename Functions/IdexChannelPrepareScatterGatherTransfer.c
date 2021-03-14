void __fastcall IdexChannelPrepareScatterGatherTransfer(int a1, int a2, _FILE_SEGMENT_ELEMENT *SegmentArray, unsigned int SegmentByteOffset, unsigned int ByteCount)
{
  unsigned int v5; // ebx
  unsigned int v6; // eax
  int v7; // ecx
  _IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *v8; // esi
  unsigned int v9; // ebx
  _IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *PhysicalRegionDescriptor; // [esp+Ch] [ebp-8h]
  unsigned int BytesRemaining; // [esp+10h] [ebp-4h]
  _FILE_SEGMENT_ELEMENT *SegmentArraya; // [esp+1Ch] [ebp+8h]
  unsigned int CurrentPhysicalAddress; // [esp+20h] [ebp+Ch]
  int RegionPhysicalAddress; // [esp+24h] [ebp+10h]

  v5 = 0;
  if ( !ByteCount || ByteCount > 0x20000 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      ByteCount,
      "(ByteCount > 0) && (ByteCount <= IDE_ATA_MAXIMUM_TRANSFER_BYTES)",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x175u,
      0);
  BytesRemaining = ByteCount;
  PhysicalRegionDescriptor = IdexChannelPhysicalRegionDescriptorTable;
  if ( SegmentByteOffset & 0xFFF )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      SegmentByteOffset,
      "BYTE_OFFSET(SegmentByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x181u,
      0);
  RegionPhysicalAddress = 0;
  SegmentArraya = &SegmentArray[SegmentByteOffset >> 12];
  while ( 1 )
  {
    v6 = MmGetPhysicalAddress(
           a2,
           (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
           (void *)((_DWORD)SegmentArraya->Buffer & 0xFFFFF000));
    CurrentPhysicalAddress = v6;
    if ( !v5 )
      RegionPhysicalAddress = v6;
    v7 = RegionPhysicalAddress;
    a2 = RegionPhysicalAddress + v5;
    if ( RegionPhysicalAddress + v5 != v6 || (RegionPhysicalAddress ^ v6) & 0xFFFF0000 )
    {
      if ( RegionPhysicalAddress & 1 )
        RtlAssert(
          a2,
          RegionPhysicalAddress,
          (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          0,
          "(RegionPhysicalAddress & IDE_ALIGNMENT_REQUIREMENT) == 0",
          "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          0x1A4u,
          0);
      if ( v5 & 1 )
        RtlAssert(
          a2,
          v7,
          (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          0,
          "(RegionByteCount & IDE_ALIGNMENT_REQUIREMENT) == 0",
          "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          0x1A5u,
          0);
      if ( v5 > 0x10000 )
        RtlAssert(
          a2,
          v7,
          (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          0,
          "RegionByteCount <= 0x10000",
          "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          0x1A6u,
          0);
      PhysicalRegionDescriptor->PhysicalAddress = RegionPhysicalAddress;
      PhysicalRegionDescriptor->ByteCount.AsULong = (unsigned __int16)v5;
      v8 = PhysicalRegionDescriptor + 1;
      PhysicalRegionDescriptor = v8;
      if ( v8 > (_IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *)&unk_8004BA48 )
        RtlAssert(
          a2,
          v7,
          (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          (int)v8,
          "PhysicalRegionDescriptor <= EndingPhysicalRegionDescriptor",
          "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
          0x1ACu,
          0);
      RegionPhysicalAddress = CurrentPhysicalAddress;
      v5 = 0;
    }
    else
    {
      v8 = PhysicalRegionDescriptor;
    }
    if ( BytesRemaining <= 0x1000 )
      break;
    ++SegmentArraya;
    v5 += 4096;
    BytesRemaining -= 4096;
  }
  v9 = BytesRemaining + v5;
  if ( RegionPhysicalAddress & 1 )
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v8,
      "(RegionPhysicalAddress & IDE_ALIGNMENT_REQUIREMENT) == 0",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x1C9u,
      0);
  if ( v9 & 1 )
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v8,
      "(RegionByteCount & IDE_ALIGNMENT_REQUIREMENT) == 0",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x1CAu,
      0);
  if ( v9 > 0x10000 )
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v8,
      "RegionByteCount <= 0x10000",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x1CBu,
      0);
  v8->PhysicalAddress = RegionPhysicalAddress;
  v8->ByteCount.AsULong = (unsigned __int16)v9 | 0x80000000;
  if ( v8 > (_IDE_PCI_PHYSICAL_REGION_DESCRIPTOR *)&unk_8004BA48 )
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      (int)v8,
      "PhysicalRegionDescriptor <= EndingPhysicalRegionDescriptor",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x1D1u,
      0);
  __outdword(0xFF64u, unk_80051370);
  __outbyte(0xFF62u, 6u);
}