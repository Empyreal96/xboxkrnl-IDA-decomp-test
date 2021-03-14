// local variable allocation has failed, the output may be wrong!
void __fastcall HalReadWritePCISpace(int a1, int a2, unsigned int BusNumber, unsigned int SlotNumber, unsigned int RegisterNumber, void *Buffer, unsigned int Length, char WritePCISpace)
{
  int v8; // esi
  int v9; // edx
  int v10; // ecx
  unsigned int (__stdcall *const *v11)(_PCI_TYPE1_CFG_BITS, unsigned int, void *); // edi
  int v12; // eax

  if ( BusNumber > 0xFF )
    RtlAssert(
      a2,
      a1,
      (int *)0xFF,
      BusNumber,
      "BusNumber <= PCI_MAX_BRIDGE_NUMBER",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\pcispace.c",
      0x146u,
      0);
  if ( RegisterNumber >= 0x100 )
    RtlAssert(
      a2,
      a1,
      (int *)0xFF,
      BusNumber,
      "RegisterNumber < sizeof(PCI_COMMON_CONFIG)",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\pcispace.c",
      0x147u,
      0);
  v8 = 8 * (SlotNumber & 0xE0 | ((SlotNumber & 0x1F | 32 * ((unsigned __int8)BusNumber | 0xFFFF8000)) << 8));
  _disable();
  if ( WritePCISpace )
  {
    HalpReadPCISpaceUshort((_PCI_TYPE1_CFG_BITS)v8, 0, &WritePCISpace + 2);
    if ( *((_WORD *)&WritePCISpace + 1) == -1 )
      RtlAssert(
        v9,
        v10,
        (int *)0xFF,
        v8,
        "DbgVendorID != PCI_INVALID_VENDORID",
        "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\pcispace.c",
        0x163u,
        0);
    v11 = HalpPCISpaceWriters;
  }
  else
  {
    v11 = HalpPCISpaceReaders;
  }
  for ( ; Length; Length -= v12 )
  {
    v12 = ((int (__stdcall *)(int, unsigned int, void *))v11[(unsigned __int8)HalpPCISpaceAccessMatrix[RegisterNumber & 3][Length & 3]])(
            v8,
            RegisterNumber,
            Buffer);
    RegisterNumber += v12;
    Buffer = (char *)Buffer + v12;
  }
  _enable();
}